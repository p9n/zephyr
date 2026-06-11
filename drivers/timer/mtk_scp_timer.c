/*
 * SPDX-FileCopyrightText: Copyright (c) 2026 Mediatek
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/init.h>
#include <zephyr/device.h>
#include <zephyr/drivers/timer/system_timer.h>
#include <zephyr/sys_clock.h>
#include <zephyr/kernel.h>
#include <zephyr/irq.h>
#include <zephyr/sys/sys_io.h>
#include "tinysys_reg.h"
#include "mtk_scp_timer.h"

#define NS_PER_TICK               ((uint64_t)NSEC_PER_SEC / CONFIG_SYS_CLOCK_TICKS_PER_SEC)
#define INT_TIMER_FREQ            32768
#define INT_TIMER_CYCLES_PER_TICK (INT_TIMER_FREQ / CONFIG_SYS_CLOCK_TICKS_PER_SEC)

/* multiplier and shifter for 13MHz global timer */
#define OSTIMER_TIMER_MULT  (161319385)
#define OSTIMER_TIMER_SHIFT (21)

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

static uint64_t ostimer_last_cycle;
static unsigned long long ostimer_init_cycle_percpu;
static uint64_t last_count;

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

/* get ostimer timestamp */
static unsigned long long get_boot_time_ns(void)
{
	unsigned long long cycle = 0;
	unsigned long long timestamp = 0;
	uint32_t high, low;

	cycle = timer_get_global_timer_tick();

	if (cycle < ostimer_last_cycle) {
		cycle = ostimer_last_cycle + 1;
	}
	ostimer_last_cycle = cycle;

	cycle = cycle - ostimer_init_cycle_percpu;
	/*
	 * Split the 64-bit cycle count into high and low 32-bit parts to avoid
	 * overflow during the 64-bit multiplication by OSTIMER_TIMER_MULT.
	 * Note: ((high * MULT) << 11) will still overflow if high * MULT >= 2^53,
	 * which limits the maximum uptime to ≈500 years at 13MHz.
	 */
	high = (cycle >> 32) & 0x00000000FFFFFFFFULL;
	low = cycle & 0x00000000FFFFFFFFULL;
	timestamp = (((unsigned long long)high * OSTIMER_TIMER_MULT) << 11) +
		    (((unsigned long long)low * OSTIMER_TIMER_MULT) >> OSTIMER_TIMER_SHIFT);

	return timestamp;
}

/* ticks: 1ms */
static uint64_t xgpt_time(void)
{
	uint64_t time_ns;
	uint64_t timer_tick;

	time_ns = get_boot_time_ns();
	timer_tick = (uint64_t)(time_ns / NS_PER_TICK);

	return timer_tick;
}

static void timer_isr(const void *arg)
{
	ARG_UNUSED(arg);
	uint64_t timer_tick;

	/* Clear TIMER interrupt */
	sys_set_bits(TIMER_IRQ_CTRL, TIMER_IRQ_CLEAR);

	/* Disable TIMER */
	sys_clear_bits(TIMER_EN, TIMER_ENABLE);
	/* Disable TIMER IRQ */
	sys_clear_bits(TIMER_IRQ_CTRL, TIMER_IRQ_ENABLE);

	timer_tick = xgpt_time();
	uint32_t dticks = (uint32_t)(timer_tick - last_count);

	if (dticks > 0) {
		last_count = timer_tick;
		sys_clock_announce(dticks);
	}

	if (!IS_ENABLED(CONFIG_TICKLESS_KERNEL)) {
		sys_clock_set_timeout(1, false);
	}
}

void sys_clock_set_timeout(uint32_t ticks, bool idle)
{
	ARG_UNUSED(idle);

	if (ticks == K_TICKS_FOREVER || ticks == INT32_MAX) {
		/* Disable timer */
		sys_clear_bits(TIMER_EN, TIMER_ENABLE);
		return;
	}

	/* Disable timer first to allow writing RST_VAL */
	sys_clear_bits(TIMER_EN, TIMER_ENABLE);

	sys_write32(INT_TIMER_CYCLES_PER_TICK * ticks, TIMER_RST_VAL);
	sys_set_bits(TIMER_IRQ_CTRL, TIMER_IRQ_ENABLE);
	sys_set_bits(TIMER_EN, TIMER_ENABLE);
}

uint32_t sys_clock_elapsed(void)
{
	if (!IS_ENABLED(CONFIG_TICKLESS_KERNEL)) {
		return 0;
	}

	uint64_t now = xgpt_time();
	uint32_t ret = (uint32_t)(now - last_count);

	return ret;
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

	/* select 32kHz clock source */
	sys_clear_bits(TIMER_CLK_SEL_REG, TIMER_CLK_SRC_MASK << TIMER_CLK_SRC_SHIFT);

	/* Enable APB and IPS clocks */
	sys_write32(BIT(IPS_CG_BIT) | BIT(APB_CG_BIT), CLR_CLK_CG);

	/* Setup TIMER */
	sys_clear_bits(TIMER_EN, TIMER_CLK_SRC_MASK << TIMER_CLK_SRC_SHIFT);
	sys_write32(INT_TIMER_CYCLES_PER_TICK, TIMER_RST_VAL);
	sys_set_bits(TIMER_IRQ_CTRL, TIMER_IRQ_ENABLE);
	sys_set_bits(TIMER_EN, TIMER_ENABLE);

	ostimer_init_cycle_percpu = timer_get_global_timer_tick();
	last_count = 0;

	/* Enable the multilevel timer interrupt */
	irq_enable(DT_IRQN(DT_NODELABEL(ostimer)));

	return 0;
}
SYS_INIT(sys_clock_driver_init, PRE_KERNEL_2, CONFIG_SYSTEM_CLOCK_INIT_PRIORITY);
