/*
 * SPDX-FileCopyrightText: Copyright (c) 2026 Mediatek
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define DT_DRV_COMPAT mediatek_mrv55_uart

#include <zephyr/drivers/uart.h>
#include <zephyr/kernel.h>
#include <zephyr/spinlock.h>
#include <zephyr/sys/sys_io.h>
#include <zephyr/types.h>

#include "mt_uart.h"

struct uart_mrv55_config {
	uintptr_t base;
	uint32_t baud_rate;
	uint32_t clock_frequency;
};

struct uart_mrv55_dev_data {
	struct k_spinlock lock;
};

static int uart_mrv55_init(const struct device *dev)
{
	const struct uart_mrv55_config *config = dev->config;
	uintptr_t base = config->base;
	uint32_t speed = config->baud_rate;
	unsigned int highspeed;
	unsigned int quot, divisor, remainder;
	unsigned int uartclk = config->clock_frequency;
	unsigned short data, high_speed_div, sample_count, sample_point;
	unsigned int tmp_div;

	sys_write32(0x1, UART_FEATURE_SEL(base));

	sys_write32(UART_FCR_NORMAL, UART_FCR(base)); /* clear fifo */
	sys_write32(UART_NONE_PARITY | UART_WLS_8 | UART_1_STOP, UART_LCR(base));

	if (speed <= 115200) {
		highspeed = 0;
		quot = 16;
	} else {
		highspeed = 3;
		quot = 1;
	}

	if (highspeed < 3) { /*0~2 */
		/* Set divisor DLL and DLH    */
		divisor = uartclk / (quot * speed);
		remainder = uartclk % (quot * speed);

		if (remainder >= (quot / 2) * speed) {
			divisor += 1;
		}

		sys_write32(highspeed, UART_HIGHSPEED(base));
		sys_write32((divisor & 0x00ff), UART_DLL_RE(base));
		sys_write32(((divisor >> 8) & 0x00ff), UART_DLH_RE(base));
	} else {
		data = (unsigned short)(uartclk / speed);
		high_speed_div = (data >> 8) + 1; /* divided by 256 */

		tmp_div = uartclk / (speed * high_speed_div);
		divisor = (unsigned short)tmp_div;

		remainder = (uartclk) % (high_speed_div * speed);
		/*get (sample_count+1) */
		if (remainder >= ((speed) * (high_speed_div)) >> 1) {
			divisor = (unsigned short)(tmp_div + 1);
		} else {
			divisor = (unsigned short)tmp_div;
		}

		sample_count = divisor - 1;

		/*get the sample point */
		sample_point = (sample_count - 1) >> 1;

		/*configure register */
		sys_write32(highspeed, UART_HIGHSPEED(base));

		sys_write32((high_speed_div & 0x00ff), UART_DLL_RE(base));
		sys_write32(((high_speed_div >> 8) & 0x00ff), UART_DLH_RE(base));
		sys_write32(sample_count, UART_SAMPLE_COUNT(base));
		sys_write32(sample_point, UART_SAMPLE_POINT(base));
	}

	return 0;
}

static int uart_mrv55_poll_in(const struct device *dev, unsigned char *c)
{
	const struct uart_mrv55_config *config = dev->config;
	struct uart_mrv55_dev_data *data = dev->data;
	uintptr_t base = config->base;
	int ret = -1;
	k_spinlock_key_t key = k_spin_lock(&data->lock);

	if (sys_read32(UART_LSR(base)) & UART_LSR_DR) {
		*c = (unsigned char)sys_read32(UART_RBR(base));
		ret = 0;
	}

	k_spin_unlock(&data->lock, key);

	return ret;
}

static void uart_mrv55_poll_out(const struct device *dev, unsigned char c)
{
	const struct uart_mrv55_config *config = dev->config;
	struct uart_mrv55_dev_data *data = dev->data;
	uintptr_t base = config->base;
	k_spinlock_key_t key = k_spin_lock(&data->lock);

	while ((sys_read32(UART_LSR(base)) & UART_LSR_THRE) == 0) {
	}

	sys_write32((unsigned int)c, UART_THR(base));

	k_spin_unlock(&data->lock, key);
}

static DEVICE_API(uart, uart_mrv55_driver_api) = {
	.poll_in = uart_mrv55_poll_in,
	.poll_out = uart_mrv55_poll_out,
};

#define UART_MRV55_DEVICE_INIT(n)                                                                  \
	static const struct uart_mrv55_config uart_mrv55_cfg_##n = {                               \
		.base = DT_INST_REG_ADDR(n),                                                       \
		.baud_rate = DT_INST_PROP(n, current_speed),                                       \
		.clock_frequency = DT_INST_PROP(n, clock_frequency),                               \
	};                                                                                         \
	static struct uart_mrv55_dev_data uart_mrv55_data_##n;                                     \
	DEVICE_DT_INST_DEFINE(n, &uart_mrv55_init, NULL, &uart_mrv55_data_##n,                     \
			      &uart_mrv55_cfg_##n, PRE_KERNEL_1, CONFIG_SERIAL_INIT_PRIORITY,      \
			      &uart_mrv55_driver_api)

DT_INST_FOREACH_STATUS_OKAY(UART_MRV55_DEVICE_INIT)
