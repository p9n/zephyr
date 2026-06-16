/*
 * SPDX-FileCopyrightText: Copyright (c) 2026 Mediatek
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/arch/cpu.h>
#include <zephyr/devicetree.h>
#include <zephyr/init.h>
#include <zephyr/sys/sys_io.h>

#include "tinysys_reg.h"

#define REG_UART0_RXTX (AP_GPIO_BASE + 0x440)
#define REG_UART1_RXTX (AP_GPIO_BASE + 0x420)

#define UART0_CLK_MASK ((1 << UART_BCLK_CG) | (1 << UART_MCLK_CG))
#define UART0_RST_MASK (1 << UART_RST_N)
#define UART1_CLK_MASK ((1 << UART1_BCLK_CG) | (1 << UART1_MCLK_CG))
#define UART1_RST_MASK (1 << UART1_RST_N)

static int mediatek_scp_init(void)
{
#if DT_NODE_HAS_STATUS(DT_NODELABEL(uart0), okay)
	/* Enable Clock & Reset for UART0 */
	sys_set_bits(SET_CLK_CG, UART0_CLK_MASK | UART0_RST_MASK);
	/* Configure GPIOs for UART0 RX/TX */
	sys_write32((sys_read32(REG_UART0_RXTX) & 0xFFFF00FF) | 0x3300, REG_UART0_RXTX);
#endif

#if DT_NODE_HAS_STATUS(DT_NODELABEL(uart1), okay)
	/* Enable Clock & Reset for UART1 */
	sys_set_bits(SET_CLK_CG, UART1_CLK_MASK | UART1_RST_MASK);
	/* Configure GPIOs for UART1 RX/TX */
	sys_write32((sys_read32(REG_UART1_RXTX) & 0xFF00FFFF) | 0x440000, REG_UART1_RXTX);
#endif

	return 0;
}

SYS_INIT(mediatek_scp_init, PRE_KERNEL_1, 0);
