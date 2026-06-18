/*
 * SPDX-FileCopyrightText: Copyright (c) 2026 Mediatek
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define DT_DRV_COMPAT mediatek_mtk_scp_ipm

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/ipm.h>
#include <zephyr/irq.h>
#include <zephyr/cache.h>
#include <string.h>

#include "tinysys_reg.h"

#define IPC_SHARED_OBJ_BUF_SIZE 288

/*
 * The layout of the IPC0 AP/SCP shared buffer.
 * This should sync across kernel and EC.
 */
struct ipc_shared_obj {
	/* IPI ID */
	int32_t id;
	/* Length of the contents in buffer. */
	uint32_t len;
	/* Shared buffer contents. */
	uint8_t buffer[IPC_SHARED_OBJ_BUF_SIZE];
};

/* Shared IPI buffers allocated in the .ipi_buffer section */
static struct ipc_shared_obj ipi_buffers[2] __attribute__((section(".ipi_buffer")));
static struct ipc_shared_obj *const ipi_send_buf = &ipi_buffers[0];
static struct ipc_shared_obj *const ipi_recv_buf = &ipi_buffers[1];

struct ipm_mtk_scp_data {
	ipm_callback_t callback;
	void *user_data;
	bool enabled;
	struct k_spinlock lock;
};

static inline int scp2ap_is_irq_set(void)
{
	return sys_read32(SCP2APMCU_IPC_SET) & SCP2APMCU_BIT0;
}

static int ipm_mtk_scp_send(const struct device *dev, int wait, uint32_t id, const void *data,
			    int size)
{
	struct ipm_mtk_scp_data *dev_data = dev->data;
	int ret = 0;
	k_spinlock_key_t key;

	if (id > INT32_MAX) {
		return -EINVAL;
	}

	if (size > IPC_SHARED_OBJ_BUF_SIZE) {
		return -EMSGSIZE;
	}

	key = k_spin_lock(&dev_data->lock);

	if (scp2ap_is_irq_set()) {
		if (wait) {
			while (scp2ap_is_irq_set()) {
				k_busy_wait(1);
			}
		} else {
			ret = -EBUSY;
			goto unlock;
		}
	}

	ipi_send_buf->id = id;
	ipi_send_buf->len = size;
	if (data && size > 0) {
		memcpy(ipi_send_buf->buffer, data, size);
	}

	/* flush memory cache */
	sys_cache_data_flush_range((void *)ipi_send_buf, sizeof(*ipi_send_buf));

	/* Trigger interrupt to AP */
	sys_write32(0x1, SCP2SPM_IPC_SET);
	sys_write32(SCP2APMCU_BIT0, SCP2APMCU_IPC_SET);

	if (wait) {
		while (scp2ap_is_irq_set()) {
			k_busy_wait(1);
		}
	}

unlock:
	k_spin_unlock(&dev_data->lock, key);
	return ret;
}

static void ipm_mtk_scp_register_callback(const struct device *dev, ipm_callback_t cb,
					  void *user_data)
{
	struct ipm_mtk_scp_data *data = dev->data;

	data->callback = cb;
	data->user_data = user_data;
}

static int ipm_mtk_scp_max_data_size_get(const struct device *dev)
{
	ARG_UNUSED(dev);
	return IPC_SHARED_OBJ_BUF_SIZE;
}

static uint32_t ipm_mtk_scp_max_id_val_get(const struct device *dev)
{
	ARG_UNUSED(dev);
	return INT32_MAX;
}

static int ipm_mtk_scp_set_enabled(const struct device *dev, int enable)
{
	struct ipm_mtk_scp_data *data = dev->data;

	data->enabled = !!enable;
	if (enable) {
		irq_enable(DT_INST_IRQN(0));
	} else {
		irq_disable(DT_INST_IRQN(0));
	}

	return 0;
}

static void ipm_mtk_scp_isr(const struct device *dev)
{
	struct ipm_mtk_scp_data *data = dev->data;

	if (sys_read32(GIPC_IN_SET) & GIPC0_SETCLR_BIT_0) {
		sys_cache_data_invd_range((void *)ipi_recv_buf, sizeof(*ipi_recv_buf));
		if (data->enabled && data->callback) {
			data->callback(dev, data->user_data, ipi_recv_buf->id,
				       ipi_recv_buf->buffer);
		}
		sys_write32(sys_read32(GIPC_IN_SET), GIPC_IN_CLR);
	}
}

static int ipm_mtk_scp_init(const struct device *dev)
{
	memset(ipi_send_buf, 0, sizeof(struct ipc_shared_obj));

	IRQ_CONNECT(DT_INST_IRQN(0), 0, ipm_mtk_scp_isr, DEVICE_DT_INST_GET(0), 0);

	return 0;
}

static DEVICE_API(ipm, ipm_mtk_scp_api) = {
	.send = ipm_mtk_scp_send,
	.register_callback = ipm_mtk_scp_register_callback,
	.max_data_size_get = ipm_mtk_scp_max_data_size_get,
	.max_id_val_get = ipm_mtk_scp_max_id_val_get,
	.set_enabled = ipm_mtk_scp_set_enabled,
};

static struct ipm_mtk_scp_data ipm_mtk_scp_data_0;

DEVICE_DT_INST_DEFINE(0, &ipm_mtk_scp_init, NULL, &ipm_mtk_scp_data_0, NULL, POST_KERNEL,
		      CONFIG_KERNEL_INIT_PRIORITY_DEVICE, &ipm_mtk_scp_api);
