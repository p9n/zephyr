/*
 * SPDX-FileCopyrightText: Copyright (c) 2026 Mediatek
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define DT_DRV_COMPAT mediatek_scp_intc

#include <zephyr/device.h>
#include <zephyr/devicetree/interrupt_controller.h>
#include <zephyr/irq_nextlevel.h>
#include <zephyr/sw_isr_table.h>
#include <zephyr/irq.h>
#include <zephyr/sys/sys_io.h>

#define INTC_WORD(irq)      ((irq) >> 5)
#define INTC_BIT(irq)       ((irq) & 0x1F)
#define INTC_WORD_OFS(word) ((word) << 2)
#define INTC_GROUP_OFS(grp) ((grp) << 4)

#define INTC_IRQ_STA(base, word)                                                                   \
	((word == 4) ? ((base) + 0x268) : ((base) + 0x010 + INTC_WORD_OFS(word)))
#define INTC_IRQ_EN(base, word)                                                                    \
	((word == 4) ? ((base) + 0x26C) : ((base) + 0x020 + INTC_WORD_OFS(word)))
#define INTC_IRQ_WAKE_EN(base, word)                                                               \
	((word == 4) ? ((base) + 0x2F0) : ((base) + 0x240 + INTC_WORD_OFS(word)))
#define INTC_IRQ_POL(base, word)                                                                   \
	((word == 4) ? ((base) + 0x274) : ((base) + 0x040 + INTC_WORD_OFS(word)))
#define INTC_IRQ_GRP(base, grp, word)                                                              \
	((word == 4) ? ((base) + 0x278 + INTC_WORD_OFS(grp))                                       \
		     : ((base) + 0x050 + INTC_GROUP_OFS(grp) + INTC_WORD_OFS(word)))
#define INTC_IRQ_GRP_STA(base, grp, word)                                                          \
	((word == 4) ? ((base) + 0x2B4 + INTC_WORD_OFS(grp))                                       \
		     : ((base) + 0x150 + INTC_GROUP_OFS(grp) + INTC_WORD_OFS(word)))
#define INTC_IRQ_CLR_TRG(base) ((base) + 0x254)

#define PLIC_BASE            DT_INST_REG_ADDR_BY_NAME(0, plic)
#define CSR_MPU_LAPB         0xbe6
#define PLIC_PRIO_REG(irq)   (PLIC_BASE + ((irq) * 4))
#define PLIC_ENABLE_REG(grp) (PLIC_BASE + 0x2000 + ((grp) * 4))
#define PLIC_LEVEL_REG(grp)  (PLIC_BASE + 0x1080 + ((grp) * 4))
#define PLIC_THRESHOLD_REG   (PLIC_BASE + 0x200000)
#define PLIC_CLAIM_REG       (PLIC_BASE + 0x200004)

#define PARENT_IRQ DT_INST_IRQN(0)

static inline void set_polarity(uintptr_t base, unsigned int irq, unsigned int polarity)
{
	unsigned int word = INTC_WORD(irq);
	unsigned int mask = BIT(INTC_BIT(irq));

	if (polarity == 0) {
		sys_clear_bits(INTC_IRQ_POL(base, word), mask);
	} else {
		sys_set_bits(INTC_IRQ_POL(base, word), mask);
	}
}

static inline void set_routing(uintptr_t base, unsigned int irq, unsigned int group)
{
	unsigned int word = INTC_WORD(irq);
	unsigned int mask = BIT(INTC_BIT(irq));

	sys_set_bits(INTC_IRQ_GRP(base, group, word), mask);
}

static inline void setup_irq(uintptr_t base, unsigned int irq, unsigned int polarity,
			     unsigned int group)
{
	set_polarity(base, irq, polarity);
	set_routing(base, irq, group);
}

#define CONFIGURE_IRQ(node_id, base)                                                               \
	COND_CODE_1(DT_NODE_HAS_PROP(node_id, interrupts), (                                       \
		COND_CODE_1(DT_SAME_NODE(DT_IRQ_INTC(node_id), DT_DRV_INST(0)), (                  \
			setup_irq(base,                                                            \
				  DT_IRQ_BY_IDX(node_id, 0, irq),                                  \
				  DT_IRQ_BY_IDX(node_id, 0, polarity),                             \
				  DT_IRQ_BY_IDX(node_id, 0, group));                               \
		), ())                                                                             \
	), ())

static void mtk_scp_intc_intr_enable(const struct device *dev, unsigned int irq)
{
	uintptr_t base = DT_INST_REG_ADDR(0);
	unsigned int local_irq = irq_from_level_2(irq);
	unsigned int word = INTC_WORD(local_irq);
	unsigned int mask = BIT(INTC_BIT(local_irq));
	unsigned int key;

	key = irq_lock();
	sys_set_bits(INTC_IRQ_EN(base, word), mask);
	irq_unlock(key);
}

static void mtk_scp_intc_intr_disable(const struct device *dev, unsigned int irq)
{
	uintptr_t base = DT_INST_REG_ADDR(0);
	unsigned int local_irq = irq_from_level_2(irq);
	unsigned int word = INTC_WORD(local_irq);
	unsigned int mask = BIT(INTC_BIT(local_irq));
	unsigned int key;

	key = irq_lock();
	sys_clear_bits(INTC_IRQ_EN(base, word), mask);
	irq_unlock(key);
}

static int mtk_scp_intc_intr_get_line_state(const struct device *dev, unsigned int irq)
{
	uintptr_t base = DT_INST_REG_ADDR(0);
	unsigned int local_irq = irq_from_level_2(irq);
	unsigned int word = INTC_WORD(local_irq);
	unsigned int mask = BIT(INTC_BIT(local_irq));

	return (sys_read32(INTC_IRQ_EN(base, word)) & mask) != 0;
}

static unsigned int mtk_scp_intc_intr_get_state(const struct device *dev)
{
	uintptr_t base = DT_INST_REG_ADDR(0);

	for (int word = 0; word < 5; ++word) {
		if (sys_read32(INTC_IRQ_EN(base, word)) != 0) {
			return 1;
		}
	}

	return 0;
}

/* Global ISR for level 1 interrupt (MEIP) */
void mtk_scp_intc_isr(const void *arg)
{
	uintptr_t base = (uintptr_t)arg;
	uint32_t active_groups = 0;
	uint32_t plic_irq;
	uint32_t grp_id;

	/* Claim PLIC interrupt */
	plic_irq = sys_read32(PLIC_CLAIM_REG);
	if (plic_irq == 0 || plic_irq > 6) {
		return;
	}
	grp_id = plic_irq - 1;

	for (int word = 0; word < 5; ++word) {
		uint32_t irq_sta = sys_read32(INTC_IRQ_STA(base, word));

		if (irq_sta == 0) {
			continue;
		}
		uint32_t grp_sta = sys_read32(INTC_IRQ_GRP_STA(base, grp_id, word));
		uint32_t grp_pending = grp_sta & irq_sta;

		if (grp_pending != 0) {
			active_groups |= BIT(grp_id);
			while (grp_pending != 0) {
				uint32_t bit = __builtin_ctz(grp_pending);
				uint32_t local_irq = bit + 32 * word;
				uint32_t off = CONFIG_2ND_LVL_ISR_TBL_OFFSET + local_irq;

				/* Dispatch to Zephyr ISR table */
				_sw_isr_table[off].isr(_sw_isr_table[off].arg);

				grp_pending &= ~BIT(bit);
			}
		}
	}

	/* Clear all active groups trigger */
	if (active_groups != 0) {
		sys_write32(active_groups, INTC_IRQ_CLR_TRG(base));
	}

	/* Complete PLIC interrupt */
	sys_write32(plic_irq, PLIC_CLAIM_REG);
}

/* Global APIs required by RISC-V privileged arch support */
void mtk_scp_intc_irq_enable(unsigned int irq)
{
	const struct device *dev = DEVICE_DT_INST_GET(0);

	mtk_scp_intc_intr_enable(dev, irq);
}

void mtk_scp_intc_irq_disable(unsigned int irq)
{
	const struct device *dev = DEVICE_DT_INST_GET(0);

	mtk_scp_intc_intr_disable(dev, irq);
}

int mtk_scp_intc_irq_is_enabled(unsigned int irq)
{
	const struct device *dev = DEVICE_DT_INST_GET(0);

	return mtk_scp_intc_intr_get_line_state(dev, irq);
}

static const struct irq_next_level_api mtk_scp_intc_apis = {
	.intr_enable = mtk_scp_intc_intr_enable,
	.intr_disable = mtk_scp_intc_intr_disable,
	.intr_get_state = mtk_scp_intc_intr_get_state,
	.intr_get_line_state = mtk_scp_intc_intr_get_line_state,
};

static int mtk_scp_intc_init(const struct device *dev)
{
	uintptr_t base = DT_INST_REG_ADDR(0);

	/* Disable all interrupts initially and clear all group routing */
	for (int word = 0; word < 5; ++word) {
		sys_write32(0, INTC_IRQ_EN(base, word));
		sys_write32(0, INTC_IRQ_WAKE_EN(base, word));
		for (int group = 0; group < 15; ++group) {
			sys_write32(0, INTC_IRQ_GRP(base, group, word));
		}
		sys_write32(0, INTC_IRQ_POL(base, word));
	}

	/* Enable APB (needed for PLIC access) */
	__asm__ volatile("csrw %0, %1" ::"i"(CSR_MPU_LAPB), "r"(PLIC_BASE));

	/* Complete any active PLIC interrupts from previous run */
	uint32_t active_irq;

	while (1) {
		active_irq = sys_read32(PLIC_CLAIM_REG);
		if (active_irq == 0) {
			break;
		}
		sys_write32(active_irq, PLIC_CLAIM_REG);
	}

	/* Enable PLIC lines for groups 0 to 5 */
	for (int grp = 0; grp < 6; ++grp) {
		unsigned int plic_irq = grp + 1;

		sys_write32(1, PLIC_PRIO_REG(plic_irq));
		sys_set_bits(PLIC_ENABLE_REG(plic_irq >> 5), BIT(plic_irq & 31));
		sys_set_bits(PLIC_LEVEL_REG(plic_irq >> 5), BIT(plic_irq & 31));
	}
	sys_write32(0, PLIC_THRESHOLD_REG);

	/* Configure interrupts from DT */
	DT_FOREACH_STATUS_OKAY_NODE_VARGS(CONFIGURE_IRQ, base)

	/* Connect ISR to parent interrupt (MEIP) */
	IRQ_CONNECT(PARENT_IRQ, 0, mtk_scp_intc_isr, (void *)DT_INST_REG_ADDR(0), 0);
	irq_enable(PARENT_IRQ);

	return 0;
}

DEVICE_DT_INST_DEFINE(0, mtk_scp_intc_init, NULL, NULL, NULL, PRE_KERNEL_1,
		      CONFIG_INTC_INIT_PRIORITY, &mtk_scp_intc_apis);

IRQ_PARENT_ENTRY_DEFINE(mtk_scp_intc_0, DEVICE_DT_INST_GET(0), DT_INST_IRQN(0),
			INTC_INST_ISR_TBL_OFFSET(0), 2);
