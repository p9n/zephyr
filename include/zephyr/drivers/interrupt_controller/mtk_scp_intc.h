/*
 * SPDX-FileCopyrightText: Copyright (c) 2026 Mediatek
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_INCLUDE_DRIVERS_INTERRUPT_CONTROLLER_MTK_SCP_INTC_H_
#define ZEPHYR_INCLUDE_DRIVERS_INTERRUPT_CONTROLLER_MTK_SCP_INTC_H_

#include <zephyr/device.h>

/**
 * @brief Enable interrupt
 *
 * @param irq Multi-level encoded interrupt ID
 */
void mtk_scp_intc_irq_enable(unsigned int irq);

/**
 * @brief Disable interrupt
 *
 * @param irq Multi-level encoded interrupt ID
 */
void mtk_scp_intc_irq_disable(unsigned int irq);

/**
 * @brief Check if an interrupt is enabled
 *
 * @param irq Multi-level encoded interrupt ID
 * @return Returns true if interrupt is enabled, false otherwise
 */
int mtk_scp_intc_irq_is_enabled(unsigned int irq);

#endif /* ZEPHYR_INCLUDE_DRIVERS_INTERRUPT_CONTROLLER_MTK_SCP_INTC_H_ */
