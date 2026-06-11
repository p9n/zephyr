/*
 * SPDX-FileCopyrightText: Copyright (c) 2026 Mediatek
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/init.h>
#include <zephyr/device.h>
#include <zephyr/drivers/timer/system_timer.h>
#include <zephyr/sys/clock.h>
#include <zephyr/kernel.h>
#include <zephyr/irq.h>
#include <zephyr/sys/sys_io.h>
#include "tinysys_reg.h"
#include "mtk_scp_timer.h"

#define OSTIMER_FREQ              ((uint64_t)CONFIG_SYS_CLOCK_HW_CYCLES_PER_SEC)
#define OSTIMER_CYCLES_PER_TICK   (OSTIMER_FREQ / CONFIG_SYS_CLOCK_TICKS_PER_SEC)
#define INT_TIMER_FREQ            32768
#define INT_TIMER_CYCLES_PER_TICK (INT_TIMER_FREQ / CONFIG_SYS_CLOCK_TICKS_PER_SEC)

#define CSR_MCTREN     (0x7c0)
#define CSR_MCTREN_VIC 6

/*
 * Enable VIC mode for CPU interrupts.
 * This is a CPU/SoC level configuration, but it requires the timer clocks
 * (TMR_MCLK/TMR_BCLK) to be enabled first (which is done in sys_clock_driver_init),
 * otherwise the CPU hangs. Thus, we keep it here.
 */
static void vic_enable(void)
{
	unsigned long tmp;
	unsigned long bit = BIT(CSR_MCTREN_VIC);

	__asm__ volatile("csrrs %0, %1, %2" : "=r"(tmp) : "i"(CSR_MCTREN), "r"(bit));
}

static uint64_t last_cycle;

/* get ostimer counter */
static uint64_t timer_get_global_timer_tick(void)
{
	uint32_t high = 0, low = 0, high_retry = 0;

	while (1) {
		high = sys_read32(OSTIMER_CUR_H);
		low = sys_read32(OSTIMER_CUR_L);
		high_retry = sys_read32(OSTIMER_CUR_H);
		if (high_retry == high) {
			break;
		}
	}

	return ((uint64_t)high << 32) | low;
}

static uint32_t cycles_to_ticks(uint64_t cycles)
{
	if (likely(cycles <= UINT32_MAX)) {
		return (uint32_t)cycles / (uint32_t)OSTIMER_CYCLES_PER_TICK;
	}

	return (uint32_t)(cycles / OSTIMER_CYCLES_PER_TICK);
}

static void timer_isr(const void *arg)
{
	ARG_UNUSED(arg);

	/* Clear TIMER interrupt */
	sys_set_bits(TIMER_IRQ_CTRL, TIMER_IRQ_CLEAR);

	/* Disable TIMER */
	sys_clear_bits(TIMER_EN, TIMER_ENABLE);
	/* Disable TIMER IRQ */
	sys_clear_bits(TIMER_IRQ_CTRL, TIMER_IRQ_ENABLE);

	uint64_t now_cycle = timer_get_global_timer_tick();
	uint32_t dticks = cycles_to_ticks(now_cycle - last_cycle);

	if (dticks > 0) {
		last_cycle += (uint64_t)dticks * OSTIMER_CYCLES_PER_TICK;
		sys_clock_announce(dticks);
	}

	sys_write32(INT_TIMER_CYCLES_PER_TICK, TIMER_RST_VAL);
	sys_set_bits(TIMER_IRQ_CTRL, TIMER_IRQ_ENABLE);
	sys_set_bits(TIMER_EN, TIMER_ENABLE);
}

uint32_t sys_clock_elapsed(void)
{
	return 0;
}

uint32_t sys_clock_cycle_get_32(void)
{
	return (uint32_t)timer_get_global_timer_tick();
}

/*  Current hardware clock up-counter (in cycles). */
uint64_t sys_clock_cycle_get_64(void)
{
	return timer_get_global_timer_tick();
}

static int sys_clock_driver_init(void)
{
	uint32_t val = sys_read32(TIMER_IN_CLK);
	/* enable clock */
	sys_write32(val | (BIT(TMR_M_CLK_CG) | BIT(TMR_B_CLK_CG)), TIMER_IN_CLK);

	/* Start global timer */
	sys_write32(1, OSTIMER_CON);

	IRQ_CONNECT(DT_IRQN(DT_NODELABEL(ostimer)), 0, timer_isr, NULL, 0);

	/* Enable VIC mode for CPU interrupts */
	vic_enable();

	/* Enable APB and IPS clocks */
	sys_write32(BIT(IPS_CG_BIT) | BIT(APB_CG_BIT), CLR_CLK_CG);

	/* Setup TIMER (32kHz clock source in bits 4..5 of TIMER_EN) */
	sys_clear_bits(TIMER_EN, TIMER_CLK_SRC_MASK << TIMER_CLK_SRC_SHIFT);
	sys_write32(INT_TIMER_CYCLES_PER_TICK, TIMER_RST_VAL);
	sys_set_bits(TIMER_IRQ_CTRL, TIMER_IRQ_ENABLE);
	sys_set_bits(TIMER_EN, TIMER_ENABLE);

	last_cycle = timer_get_global_timer_tick();

	/* Enable the multilevel timer interrupt */
	irq_enable(DT_IRQN(DT_NODELABEL(ostimer)));

	return 0;
}
SYS_INIT(sys_clock_driver_init, PRE_KERNEL_2, CONFIG_SYSTEM_CLOCK_INIT_PRIORITY);
