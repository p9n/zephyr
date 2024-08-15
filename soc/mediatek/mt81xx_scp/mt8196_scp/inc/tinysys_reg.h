/*
 * SPDX-FileCopyrightText: Copyright (c) 2026 Mediatek
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef ZEPHYR_SOC_MEDIATEK_MT81XX_SCP_MT8196_SCP_INC_TINYSYS_REG_H_
#define ZEPHYR_SOC_MEDIATEK_MT81XX_SCP_MT8196_SCP_INC_TINYSYS_REG_H_

#define L2TCM_START 0x00000000
#define L2TCM_SIZE  CFG_SCP_SRAM_SIZE

/*
 * 0xb000_0000 default remap to l2tcm
 * Once trap pointer enabled,
 * region info can be access through NULLPTR_BASE.
 */
#define NULLPTR_BASE 0xb0000000

#define REG_BASE 0x70000000

#define PAR_TOP_BASE 0x70020000

#define CLK_CTRL_BASE 0x70021000

#define SCP_IPS_BASE          0x70039000
/* CLK_CTRL */
#define CLK_SW_SEL            (CLK_CTRL_BASE + 0x0000) /* Clock Source Select */
#define CKSW_SEL_BIT          0
#define CKSW_SEL_MASK         0x3
#define CKSW_SEL_O_BIT        8
#define CKSW_SEL_O_MASK       0xf
#define CLK_ENABLE            (CLK_CTRL_BASE + 0x0004) /* Clock Source Enable */
#define CLK_SYS_EN_BIT        0
#define CLK_HIGH_EN_BIT       1
#define CLK_HIGH_CG_BIT       2
#define CLK_SYS_IRQ_EN_BIT    16
#define CLK_HIGH_IRQ_EN_BIT   17
#define CLK_SAFE_ACK          (CLK_CTRL_BASE + 0x0008) /* Clock Safe Ack */
#define CLK_SYS_SAFE_ACK_BIT  0
#define CLK_HIGH_SAFE_ACK_BIT 1

#define CLK_ACK          (CLK_CTRL_BASE + 0x000C) /* Clock Ack */
#define CLK_SYS_ACK_BIT  0
#define CLK_HIGH_ACK_BIT 1

#define CLK_IRQ_ACK      (CLK_CTRL_BASE + 0x0010) /* Clock Interrupt Acknowledge */
#define CLK_SYS_VAL      (CLK_CTRL_BASE + 0x0014) /* System Clock Counter Value */
#define CLK_SYS_VAL_BIT  0
#define CLK_SYS_VAL_MASK 0x3ff

#define CLK_HIGH_VAL      (CLK_CTRL_BASE + 0x0018) /* ULPOSC Clock Counter Value */
#define CLK_HIGH_VAL_BIT  0
#define CLK_HIGH_VAL_MASK 0x3ff

#define CLK_SEL_SLOW            (CLK_CTRL_BASE + 0x001C)
#define CLK_SW_SEL_SLOW_BIT     0
#define CLK_SW_SEL_SLOW_MASK    0x3
#define CLK_DIVSW_SEL_SLOW_BIT  4
#define CLK_DIVSW_SEL_SLOW_MASK 0x3

#define SLEEP_CTRL              (CLK_CTRL_BASE + 0x0020) /* Sleep mode control */
#define SLP_CTRL_EN_BIT         0
#define VREQ_COUNT_BIT          1
#define VREQ_COUNT_MASK         0x7F
#define SPM_SLP_MODE_BIT        8
#define SPM_SLP_MODE_CLK_AO_BIT 9
#define MOD_SLP_EN_OK           31

#define CLK_DIV_SEL      (CLK_CTRL_BASE + 0x0024) /* Clock Divider Select */
#define DIVSW_SEL_BIT    0
#define DIVSW_SEL_MASK   0x3
#define DIVSW_SEL_O_BIT  8
#define DIVSW_SEL_O_MASK 0xf
#define SLEEP_DEBUG      (CLK_CTRL_BASE + 0x0028) /* Sleep mode debug signals */
#define L1TCM_SRAM_PDN   (CLK_CTRL_BASE + 0x002C) /* Sram Power Down */
#define DMA_SRAM_PON     (CLK_CTRL_BASE + 0x0098) /* DMA Sram Power on */
#define SET_CLK_CG       (CLK_CTRL_BASE + 0x0030)
#define APB_CG_BIT       6
#define IPS_CG_BIT       27
#define SET_CLK_CG1      (CLK_CTRL_BASE + 0x0078)
#define CLR_CLK_CG_1     (CLK_CTRL_BASE + 0x007C)
#define R_CVFS_CG        19

/* Clock Gating ID */
#define TMR_M_CLK_CG  0
#define TMR_B_CLK_CG  1
#define MAD_MCLK_CG   2
#define I2C_PCLK_CG   3
#define I2C_BCLK_CG   21
#define GPIO_MCLK_CG  5
#define AP2P_MCLK_CG  6
#define UART_MCLK_CG  7
#define UART_BCLK_CG  8
#define UART_RST_N    9
#define UART1_MCLK_CG 10
#define UART1_BCLK_CG 11
#define UART1_RST_N   12
#define SPI0_CG       13
#define SPI1_CG       14
#define SPI2_CG       15
#define DMA0_CH0_CG   16
#define DMA0_CH1_CG   17
#define DMA0_CH2_CG   18
#define DMA0_CH3_CG   19
#define DMA_I2C_CG    20
#define I3C0_CG       21
#define I3C1_CG       22
#define DMA1_CH0_CG   23
#define DMA1_CH1_CG   24
#define DMA1_CH2_CG   25
#define DMA1_CH3_CG   26
#define SPI3_CG       30

/*Clock Gating ID 2*/
#define UART2_MCLK_CG             3
#define UART2_BCLK_CG             4
#define UART2_RST_N               5
#define SET_I3C_FAST_PCLK_CG      12
#define SET_I3C_FAST_WRAP_BCLK_CG 13

#define PMICW_CTRL                (CLK_CTRL_BASE + 0x0034) /* PMIC Wrapper Control */
#define PMICW_SLEEP_REQ_CORE0_BIT 0
#define PMICW_SLEEP_ACK_BIT       4
#define PMICW_CLK_MUX_BIT         8
#define PMICW_DCM_BIT             9

#define DCM_EN                    (CLK_CTRL_BASE + 0x003C) /* AHB bus DCM control */
#define SYS_DCM_EN_BIT            28
#define WAKE_CKSW_SEL             (CLK_CTRL_BASE + 0x0040)
#define WAKE_CKSW_SEL_NORMAL_BIT  0
#define WAKE_CKSW_SEL_NORMAL_MASK 0x3
#define WAKE_CKSW_SEL_SLOW_BIT    4
#define WAKE_CKSW_SEL_SLOW_MASK   0x3
#define WAKE_CKSW_SEL_O_BIT       8
#define WAKE_CKSW_SEL_O_MASK      0xf

#define UART_CK_SEL     (CLK_CTRL_BASE + 0x0044) /* UART_CK_SEL */
#define BCK_CK_SEL      (CLK_CTRL_BASE + 0x0048) /* BCLK_CK_SEL */
#define SPI_BCK_CK_SEL  (CLK_CTRL_BASE + 0x004C) /* SPI_BCLK_CK_SEL */
#define ILDO_CK_SEL_BIT 16
#define ILDO_CK_SEL_MSK 0x3
#define I3C_BCLK_SEL    (CLK_CTRL_BASE + 0x0050) /* I3C_BCLK_CK_SEL */
#define CPU_VREQ_CTRL   (CLK_CTRL_BASE + 0x0054) /* CPU_A_VREQ_CTRL */
#define B_VREQ_SEL      (1 << 0)
#define CLR_CLK_CG      (CLK_CTRL_BASE + 0x0058) /* PERI Clock Gating Clear */
#define CLR_CLK_CG1     (CLK_CTRL_BASE + 0x007C) /* PERI Clock Gating Clear */

#define CLK_HIGH_CORE    (CLK_CTRL_BASE + 0x005C) /* ulposc2 core control CLK_HIGH_CORE_CG */
#define HIGH_CORE_CG_BIT 1

#define SLEEP_STATE (CLK_CTRL_BASE + 0x0060)

#define SLP_IRQ2      (CLK_CTRL_BASE + 0x0064)
#define SLP_IRQ2_BIT  0
#define SLP_IRQ2_MASK 1

#define CLK_ON_CTRL           (CLK_CTRL_BASE + 0x006C)
#define HIGH_AO_BIT           0
#define HIGH_CG_AO_BIT        2
#define HIGH_CORE_AO_BIT      4
#define HIGH_CORE_DIS_SUB_BIT 5
#define HIGH_CORE_CG_AO_BIT   6
#define HIGH_FINAL_VAL_BIT    8
#define HIGH_FINAL_VAL_MASK   0x1f

#define CPU0_SRAM_PD              (CLK_CTRL_BASE + 0x0080)
#define CPU1_SRAM_PD              (CLK_CTRL_BASE + 0x0084)
#define TCM_TAIL_SRAM_PD          (CLK_CTRL_BASE + 0x0094)
#define CLK_CTRL_GENERAL_CTRL     (CLK_CTRL_BASE + 0x009C)
#define PMICW_SLEEP_REQ_CORE1_BIT 16
#define PMICW_SLEEP_ACK_COREL_BIT 29
#define PMICW_SLEEP_ACK_CORE0_BIT 30
#define PMICW_SLEEP_ACK_CORE1_BIT 31

#define CLK_CTRL_SLP_CTRL      (CLK_CTRL_BASE + 0x00A0)
#define SLOW_CLK_WAKE_DIS_BIT  0
#define SLOW_CLK_WAKE_DIS_MASK 0x1

#define FAST_WAKE_CNT_END      (CLK_CTRL_BASE + 0x00A4)
#define FAST_WAKE_CNT_END_BIT  0
#define FAST_WAKE_CNT_END_MASK 0xfff

#define CLK_CTRL_SLP_CTRL_2                      (CLK_CTRL_BASE + 0x00B0)
#define BYPASS_TSIP_CORE_PWR_DBGAPB_PROT_ACK_BIT 10
#define BYPASS_SLP_STATE_CORE1                   1
#define BYPASS_SLP_STATE_COREL                   2

#define SLP_EN_CPU0               (CLK_CTRL_BASE + 0x00F0)
#define PRE_SLP_STATE_CPU0_BIT    28
#define PRE_SLP_STATE_CPU0_MASK   0x7
#define SLEEP_WAKE_DEBUG_PERI_BIT 4
#define SLEEP_WAKE_DEBUG_NEW_BIT  3
#define SLEEP_WAKE_DEBUG_BIT      2
#define SLEEP_FAST_ONOFF_BIT      1
#define SLP_EN_CPU0_BIT           0

#define SLP_EN_CPU1             (CLK_CTRL_BASE + 0x00F4)
#define PRE_SLP_STATE_CPU1_BIT  28
#define PRE_SLP_STATE_CPU1_MASK 0x7
#define SLP_EN_CPU1_BIT         0

#define SLP_EN_CPUL             (CLK_CTRL_BASE + 0x0100)
#define PRE_SLP_STATE_CPUL_BIT  28
#define PRE_SLP_STATE_CPUL_MASK 0x7
#define SLP_EN_CPUL_BIT         0

#define SLP_IRQ_CPU0       (CLK_CTRL_BASE + 0x00F8)
#define SLP_IRQ_2_CPU0_BIT 1
#define SLP_IRQ_CPU0_BIT   0

#define SLP_IRQ_CPU1       (CLK_CTRL_BASE + 0x00FC)
#define SLP_IRQ_2_CPU1_BIT 1
#define SLP_IRQ_CPU1_BIT   0

#define SLP_IRQ_CPUL       (CLK_CTRL_BASE + 0x0104)
#define SLP_IRQ_2_CPUL_BIT 1
#define SLP_IRQ_CPUL_BIT   0

#define HWDVFSRC_INTF_CTRL        (CLK_CTRL_BASE + 0x0120)
#define PMICW_SLEEP_REQ_COREL_BIT 16

#define SLP_PDN_REG           (CLK_CTRL_BASE + 0x0128)
#define SLP_PERI_PWR_OFF_MASK (0x1)
#define SLP_PERI_PWR_OFF_BIT  (3)
#define SLP_SLP_FLOW_NEW_MASK (0x1)
#define SLP_SLP_FLOW_NEW_BIT  (2)
#define SLP_PDN_CPU_OFF_MASK  (0x1)
#define SLP_PDN_CPU_OFF_BIT   (1)
#define SLP_PDN_TCM_SLP_MASK  (0x1)
#define SLP_PDN_TCM_SLP_BIT   (0)

/* PMIF SPMI ==================================== */
#define PMIF_BASE         (REG_BASE + 0x22000)
#define PMIF_ACC          (PMIF_BASE + 0x000)
#define PMIF_WDATA_31_0   (PMIF_BASE + 0x004)
#define PMIF_WDATA_63_32  (PMIF_BASE + 0x008)
#define PMIF_WDATA_95_64  (PMIF_BASE + 0x00C)
#define PMIF_WDATA_127_96 (PMIF_BASE + 0x010)
#define PMIF_RDATA_31_0   (PMIF_BASE + 0x014)
#define PMIF_RDATA_63_32  (PMIF_BASE + 0x018)
#define PMIF_RDATA_95_64  (PMIF_BASE + 0x01C)
#define PMIF_RDATA_127_96 (PMIF_BASE + 0x020)
#define PMIF_VLD_CLR      (PMIF_BASE + 0x024)
#define PMIF_STA          (PMIF_BASE + 0x028)

#define U_VOWIF_BASE        0x70023000
#define VOW_FIFO_EN         (U_VOWIF_BASE + 0x00) /* VIF_FIFO_EN */
#define VOW_FIFO_STATUS     (U_VOWIF_BASE + 0x04) /* VIF_FIFO_STATUS */
#define VOW_FIFO_DATA       (U_VOWIF_BASE + 0x08) /* VIF_RXDATA */
#define VOW_FIFO_DATA_THRES (U_VOWIF_BASE + 0x0C) /* FIFO_THRESHOLD */
#define VOW_FIFO_IRQ_ACK    (U_VOWIF_BASE + 0x10) /* VIF_IRQ_STATUS */
#define VOW_RXIF_CFG0       (U_VOWIF_BASE + 0x14) /* RXIF_CFG0 */
#define VOW_RXIF_CFG1       (U_VOWIF_BASE + 0x18) /* RXIF_CFG1 */
#define VOW_RXIF_CFG2       (U_VOWIF_BASE + 0x1C) /* RXIF_CFG2 */
#define VOW_RXIF_OUT        (U_VOWIF_BASE + 0x20) /* RXIF_OUT */
#define VOW_RXIF_STATUS     (U_VOWIF_BASE + 0x24) /* RXIF_STATUS */
#define VOW_R_DATAIN_IRQ_EN (U_VOWIF_BASE + 0x28) /* VOW_IRQ_MODE */

/* VOW SCP DMIC */
#define SCP_VOW_DMIC_BASE         (REG_BASE + 0x45000)
#define VOW_DMIC_EN               (SCP_VOW_DMIC_BASE + 0x0)
#define VOW_DMIC_FIFO_STA         (SCP_VOW_DMIC_BASE + 0x4)
#define VOW_DMIC_FIFO_THRESHOLD   (SCP_VOW_DMIC_BASE + 0x8)
#define VOW_DMIC_IRQ_ACK          (SCP_VOW_DMIC_BASE + 0xC)
#define VOW_DMIC_RDATA_CH1_CH2    (SCP_VOW_DMIC_BASE + 0x10)
#define VOW_DMIC_RDATA_CH3        (SCP_VOW_DMIC_BASE + 0x14)
#define VOW_DMIC_FIFO_DBG_EN      (SCP_VOW_DMIC_BASE + 0x18)
#define SCP_AFE_VOW_TOP_CON0      (SCP_VOW_DMIC_BASE + 0x28)
#define SCP_AFE_VOW_TOP_CON1      (SCP_VOW_DMIC_BASE + 0x2C)
#define SCP_VOW_ADDA_UL_SRC_CON0  (SCP_VOW_DMIC_BASE + 0x30)
#define SCP_VOW_ADDA1_UL_SRC_CON0 (SCP_VOW_DMIC_BASE + 0xA8)

/* CFGREG */
#define R_SYS_CTRL                (REG_BASE + 0x24000)
#define B_AUTO_DDREN_NEW          14
#define B_AUTO_APSRC              13
#define B_AUTO_BUS_REQ            10
#define B_AUTO_DDREN              9
#define B_PMIC_P2P_TO_EN          8
#define B_CFG_DBG_MULTICORE_EN    4
#define B_CFG_DBG_CROSS_TRIG_EN   3
#define B_EMI_DOMAIN_ABORT_IRQ_EN 2
#define B_LEGACY_DMA_REQ_MODE     1
#define B_CACHE_AUTO_REQ_EN       0

#define R_SYS_STATUS           (REG_BASE + 0x24004)
#define B_WDT_IRQ_CORES        16
#define B_PMIC_P2P_VIO_TIMEOUT 0

#define R_SLP_PROT_EN           (REG_BASE + 0x24008)
#define B_AUDSYS_SLP_PROTECT_EN 18
#define B_PDN_PWR_PROT_REQ      17
#define B_AO_PWR_PROT_REQ       16
#define B_BLOCK_DRAM_TRANS      4

#define R_SLP_PROT_STATUS           (REG_BASE + 0x2400c)
#define B_AUDIOSYS_PDN_PWR_PROT_ACK 18
#define B_PDN_PWR_PROT_ACK          17
#define B_AO_PWR_PROT_ACK           16

#define R_I2C_CTRL    (REG_BASE + 0x24010)
#define B_I2C1_FINISH 21
#define B_I2C1_IDLE   20
#define B_I2C0_FINISH 17
#define B_I2C0_IDLE   16

#define R_DEBUG_IRQ_STATUS      (REG_BASE + 0x24014)
#define B_EMI_DOMAIN_ABORT_MASK 3
#define B_CLK_CTRL_DBG_IRQ      2
#define B_WDT_IRQ_CORE1         1
#define B_WDT_IRQ_CORE0         0

#define R_SEMAPHORE      (REG_BASE + 0x50004)
#define R_SEMAPHORE_3MST (REG_BASE + 0x50008)
#define SEMA_AMP_PRINTF  (1 << 0)

#define R_SCP2SPM_VOL_LV          (REG_BASE + 0x24020)
#define R_SCP2SPM_GPR             (REG_BASE + 0x24024)
#define R_SPM2SCP_GPR             (REG_BASE + 0x24028)
#define R_INFRA_CTRL_STATUS       (REG_BASE + 0x2402C)
#define R_CPU_DBG_CROSS_INTF      (REG_BASE + 0x50000)
#define B_CORE1_DBG_RESTARTED_OUT 23
#define B_CORE1_DBG_RESTART_IN    22
#define B_CORE1_DBG_ACK_OUT       21
#define B_CORE1_DBG_REQ_IN        20
#define B_CORE0_DBG_RESTARTED_OUT 19
#define B_CORE0_DBG_RESTART_IN    18
#define B_CORE0_DBG_ACK_OUT       17
#define B_CORE0_DBG_REQ_IN        16
#define B_DBG_CROSS_RESTART       0

#define R_L2TCM_CTRL                    (REG_BASE + 0x24040)
#define R_L2TCM_AXI_BRIDGE_STATUS       (REG_BASE + 0x24044)
#define R_L2TCM_SEC_VIO_STATUS          (REG_BASE + 0x24048)
#define B_L2TCM_SEC_VIO_STATUS_VIO      (0)
#define B_L2TCM_SEC_VIO_STATUS_RW       (1)
#define B_L2TCM_SEC_VIO_STATUS_DOMAIN   (4)
#define B_L2TCM_SEC_VIO_STATUS_ID       (8)
#define L2TCM_SEC_VIO_STATUS_SEL_VIO    (0x1 << B_L2TCM_SEC_VIO_STATUS_VIO)
#define L2TCM_SEC_VIO_STATUS_SEL_RW     (0x1 << B_L2TCM_SEC_VIO_STATUS_RW)
#define L2TCM_SEC_VIO_STATUS_SEL_DOMAIN (0xF << B_L2TCM_SEC_VIO_STATUS_DOMAIN)
#define L2TCM_SEC_VIO_STATUS_SEL_ID     (0x1FFFFF << B_L2TCM_SEC_VIO_STATUS_ID)
#define L2TCM_SEC_VIO_ADDR              (REG_BASE + 0x2404c)
#define L2TCM_SEC_VIO_ACK               (REG_BASE + 0x24050)
#define MAIN_BUS_CTRL                   (REG_BASE + 0x24060)
#define SCP2APMCU_IPC_SET               (REG_BASE + 0x24080)
#define SCP2APMCU_BIT0                  (1 << 0)
#define SCP2APMCU_IPC_CLR               (REG_BASE + 0x50010)
#define SCP_SSHUB2APMCU_IPC_SET         (REG_BASE + 0x24088)
#define SCP_SSHUB2APMCU_IPC_CLR         (REG_BASE + 0x50014)
#define SCP2SPM_IPC_SET                 (REG_BASE + 0x24090)
#define SCP2SPM_IPC_CLR                 (REG_BASE + 0x50018)
#define GIPC_IN_SET                     (REG_BASE + 0x50040)
#define GIPC_IN_CLR                     (REG_BASE + 0x50044)
#define GIPC0_SETCLR_BIT_0              (1 << 0)
#define GIPC0_SETCLR_BIT_1              (1 << 1)
#define GIPC0_SETCLR_BIT_2              (1 << 2)
#define GIPC0_SETCLR_BIT_3              (1 << 3)
#define GIPC1_SETCLR_BIT_0              (1 << 4)
#define GIPC1_SETCLR_BIT_1              (1 << 5)
#define GIPC1_SETCLR_BIT_2              (1 << 6)
#define GIPC1_SETCLR_BIT_3              (1 << 7)
#define GIPC2_SETCLR_BIT_0              (1 << 8)
#define GIPC2_SETCLR_BIT_1              (1 << 9)
#define GIPC2_SETCLR_BIT_2              (1 << 10)
#define GIPC2_SETCLR_BIT_3              (1 << 11)
#define GIPC3_SETCLR_BIT_0              (1 << 12)
#define GIPC3_SETCLR_BIT_1              (1 << 13)
#define GIPC3_SETCLR_BIT_2              (1 << 14)
#define GIPC3_SETCLR_BIT_3              (1 << 15)
#define GIPC4_SETCLR_BIT_0              (1 << 16)
#define GIPC4_SETCLR_BIT_1              (1 << 17)
#define GIPC4_SETCLR_BIT_2              (1 << 18)
#define GIPC4_SETCLR_BIT_3              (1 << 19)
#define GIPC5_SETCLR_BIT_0              (1 << 20)
#define GIPC5_SETCLR_BIT_1              (1 << 21)
#define GIPC5_SETCLR_BIT_2              (1 << 22)
#define GIPC5_SETCLR_BIT_3              (1 << 23)

#define GIPC_OUT_SET           (REG_BASE + 0x50048)
#define GIPC_OUT_CLR           (REG_BASE + 0x5004c)
#define ADSP_EMI_AXI_BRG_CTRL  (REG_BASE + 0x240d0)
#define ADSP_TSIP_AXI_BRG_CTRL (REG_BASE + 0x240d4)
#define TSIP_ADSP_AXI_BRG_CTRL (REG_BASE + 0x240d8)
#define SCP_INFRA_AXI_BRG_CTRL (REG_BASE + 0x240dc)
#define SCP_EMI_AXI_BRG_CTRL   (REG_BASE + 0x240e0)
#define INFRA_SCP_AXI_BRG_CTRL (REG_BASE + 0x240e4)
#define SCP_TRACKER_CTRL2      (REG_BASE + 0x240e8)
#define SCP_DBG_CTRL           (REG_BASE + 0x240f0)
#define L2TCM_LAT_CNT_EN       (1 << 13)
#define EMI_LAT_CNT_EN         (1 << 12)
#define TRACKER_FORCE_IDLE                                                                         \
	(1 << 4) /* origial bus tracker will auto reply only when bus idle, this fake this signal  \
		  */

#define SCP_TRACKER_CTRL         (REG_BASE + 0x240f4)
#define BUS_WP_SLV_ERR_EN        (1 << 15)
#define BUS_DBG_OT_WEN_CTRL      (1 << 14)
#define DBG_TIMEOUT_HALT_EN      (1 << 13)
#define DBG_WDT_RST_EN           (1 << 12)
/* bus timer sel: 0:cpu, 1: 26M */
#define TIMER_CLOCK_SEL          (1 << 9)
#define DBG_AR_WATCHPOINT_EN     (1 << 8)
#define DBG_AR_WATCHPOINT_IRQ_EN (1 << 7)
#define DBG_AW_WATCHPOINT_IRQ_EN (1 << 6)
#define DBG_AW_TIMEOUT_IRQ_EN    (1 << 5)
#define DBG_AR_TIMEOUT_IRQ_EN    (1 << 4)
#define DBG_AW_WATCHPOINT_EN     (1 << 3)
#define DBG_SLV_ERR_EN           (1 << 2)
#define DBG_TIMEOUT_EN           (1 << 1)
#define DBG_CON_EN               (1 << 0)

#define EMI_LAT_RD_CNT       (REG_BASE + 0x24120)
#define EMI_LAT_WT_CNT       (REG_BASE + 0x24124)
#define EMI_LAT_RD_LAT_CNT   (REG_BASE + 0x24128)
#define EMI_LAT_WT_LAT_CNT   (REG_BASE + 0x2412c)
#define L2TCM_LAT_RD_CNT     (REG_BASE + 0x24130)
#define L2TCM_LAT_WT_CNT     (REG_BASE + 0x24134)
#define L2TCM_LAT_RD_LAT_CNT (REG_BASE + 0x24138)
#define L2TCM_LAT_WT_LAT_CNT (REG_BASE + 0x2413c)
#define R_GPR0_CFGREG        (REG_BASE + 0x24140)
#define SCP_DEBUG_CHECK_REG  R_GPR0_CFGREG
#define R_GPR1_CFGREG        (REG_BASE + 0x24144)
#define SCP_SLT_LOGGER_ADDR  R_GPR1_CFGREG

#define R_DUMMY_OUTPUT               (REG_BASE + 0x24148)
#define CORE_LITTLE_GATED_BYPASS_BIT 1
#define SMP_SYS_GATED_CHK_BYPASS_BIT 2
#define AUTO_PDN_APDMA_SRAM_EN_BIT   3

#define BUS_DBG_OUT               (REG_BASE + 0x24150)
#define BUS_DBG_OUT_LATCH         (REG_BASE + 0x24160)
#define CORE0_OS_TIMER_LATCH_CTRL (REG_BASE + 0x330A0)
#define OS_TIMER_LATCH_SEL_0      (0x1 << 0)
#define OS_TIMER_LATCH_EN_0       (0x1 << 6)
#define OS_TIMER_LATCH_SEL_1      (0x1 << 8)
#define OS_TIMER_LATCH_EN_1       (0x1 << 14)
#define OS_TIMER_LATCH_SEL_2      (0x1 << 16)
#define OS_TIMER_LATCH_EN_2       (0x1 << 22)
#define OS_TIMER_LATCH_SEL_3      (0x1 << 24)
#define OS_TIMER_LATCH_EN_3       (0x1 << 30)
#define EINT0                     (0)
#define EINT1                     (1)
#define EINT2                     (2)
#define EINT3                     (3)
#define EINT4                     (4)
#define EINT5                     (5)
#define EINT6                     (6)
#define EINT7                     (7)
#define EINT8                     (8)
#define EINT9                     (9)
#define EINT10                    (10)
#define EINT11                    (11)
#define EINT12                    (12)
#define EINT13                    (13)
#define EINT14                    (14)
#define EINT15                    (15)
#define EINT16                    (16)
#define EINT17                    (17)
#define EINT18                    (18)
#define EINT19                    (19)
#define i3c0_ibi_wake             (20)
#define i3c1_ibi_wake             (21)
#define timer_irq0                (22)
#define timer_irq1                (23)
#define timer_irq2                (24)
#define timer_irq3                (25)
#define timer_irq4                (26)
#define timer_irq5                (27)
#define os_timer_irq5             (28)

#define R_SCP_NEW_DDREN            (REG_BASE + 0x24208)
#define R_SCP_APSRC_MONITOR_AXUSER (REG_BASE + 0x2420C)

#define R_SCP_PMIF_HWINTF_0 (REG_BASE + 0x24210)
#define SCP_PWAP_REQ_OFFSET (0)
#define SCP_PWAP_REQ_MASK   (0x1)
#define SCP_PWAP_ACK_OFFSET (1)
#define SCP_PWAP_ACK_MASK   (0x1)
#define SCP_PWAP_ERR_OFFSET (2)
#define SCP_PWAP_ERR_MASK   (0x1)

#define R_SCP_PMIF_HWINTF_CRTL    (REG_BASE + 0x24214)
#define SCP_PWARP_PMID_ID_OFFSET  (0)
#define SCP_PWARP_PMID_ID_MASK    (0x1)
#define SCP_PWARP_BYTE_CNT_OFFSET (1)
#define SCP_PWARP_BYTE_CNT_MASK   (0x1)
#define SCP_PWARP_CMD_OFFSET      (2)
#define SCP_PWARP_CMD_MASK        (0x3)
#define SCP_PWARP_SLV_ID_OFFSET   (4)
#define SCP_PWARP_SLV_ID_MASK     (0xF)

#define R_SCP_PMIF_HWINTF_CRTL1 (REG_BASE + 0x24218)
#define SCP_PWARP_ADDR_OFFSET   (0)
#define SCP_PWARP_ADDR_MASK     (0xFFFF)
#define SCP_PWARP_WEN_OFFSET    (16)
#define SCP_PWARP_WEN_MASK      (0x1)

#define R_SCP_PMIF_HWINTF_WDATA (REG_BASE + 0x2421C)
#define R_SCP_PMIF_HWINTF_RDATA (REG_BASE + 0x24220)

#define R_SCP_NEW_DDREN_CTRL (REG_BASE + 0x24224)
#define R_SCP_NEW_APSRC_CTRL (REG_BASE + 0x24228)

#define R_SCP_DRAM_VIO_STATUS (REG_BASE + 0x2422C)
#define R_SCP_DRAM_VIO_ADDR_0 (REG_BASE + 0x24230)
#define R_SCP_DRAM_VIO_ADDR_1 (REG_BASE + 0x24234)

#define CORE0_OS_TIMER_LATCH_VALUE_0     (REG_BASE + 0x330A4)
#define CORE0_OS_TIMER_LATCH_VALUE_0_MSB (REG_BASE + 0x330A8)
#define CORE0_OS_TIMER_LATCH_VALUE_1     (REG_BASE + 0x330AC)
#define CORE0_OS_TIMER_LATCH_VALUE_1_MSB (REG_BASE + 0x330B0)
#define CORE0_OS_TIMER_LATCH_VALUE_2     (REG_BASE + 0x330B4)
#define CORE0_OS_TIMER_LATCH_VALUE_2_MSB (REG_BASE + 0x330B8)
#define CORE0_OS_TIMER_LATCH_VALUE_3     (REG_BASE + 0x330BC)
#define CORE0_OS_TIMER_LATCH_VALUE_3_MSB (REG_BASE + 0x330C0)
#define CORE0_OS_TIMER_LATCH_VALUE_4     (REG_BASE + 0x330C4)
#define CORE0_OS_TIMER_LATCH_VALUE_4_MSB (REG_BASE + 0x330C8)
#define CORE0_OS_TIMER_LATCH_CTRL2       (REG_BASE + 0x330DC)
#define OS_TIMER_LATCH_SEL_4             (0x1 << 0)
#define OS_TIMER_LATCH_EN_4              (0x1 << 6)

/* CFGREG_core0 */
#define SMP_SW_RSTN_CLR_AP   (REG_BASE + 0x5001C)
#define SMP_SW_RSTN_SET_AP   (REG_BASE + 0x50020)
#define CORE0_SW_RSTN_CLR    (REG_BASE + 0x30000)
#define CORE0_SW_RSTN_SET    (REG_BASE + 0x30004)
#define CORE0_MEM_ATT_PREDEF (REG_BASE + 0x30008)
#define CORE0_BUS_QOS        (REG_BASE + 0x3000c)
#define CORE0_DBG_CTRL       (REG_BASE + 0x30010)
#define M_CORE_TBUF_DBG_SEL  (7 << 4)

#define CORE0_ITCM_ADDR_OFFSET  (REG_BASE + 0x30014)
#define CORE0_DTCM_ADDR_OFFSET  (REG_BASE + 0x30018)
#define CORE0_GENERAL_CTRL      (REG_BASE + 0x3001c)
#define B_CPU_TIMER_INT_EN      (1 << 0)
#define CORE0_CLK_SYS_REQ       (REG_BASE + 0x30020)
#define CORE0_BUS_REQ           (REG_BASE + 0x30024)
#define CORE0_APSRC_REQ         (REG_BASE + 0x30028)
#define CORE0_DDREN             (REG_BASE + 0x3002c)
#define CORE0_WDT_IRQ           (REG_BASE + 0x30030)
#define CORE0_WDT_CFG           (REG_BASE + 0x30034)
#define CORE0_WDT_KICK          (REG_BASE + 0x30038)
#define CORE0_WDT_CUR_VAL       (REG_BASE + 0x3003c)
#define CORE0_R_GPR0            (REG_BASE + 0x30040)
#define SCP_GRP_CORE0_SLPDBG    CORE0_R_GPR0
#define CORE0_R_GPR1            (REG_BASE + 0x30044)
#define DRAM_RESV_ADDR_REG      CORE0_R_GPR1
#define CORE0_R_GPR2            (REG_BASE + 0x30048)
#define DRAM_RESV_SIZE_REG      CORE0_R_GPR2
#define CORE0_R_GPR3            (REG_BASE + 0x3004c)
#define EXPECTED_FREQ_REG       CORE0_R_GPR3
#define CORE0_R_GPR4            (REG_BASE + 0x30050)
#define CURRENT_FREQ_REG        CORE0_R_GPR4
#define CORE0_R_GPR5            (REG_BASE + 0x30054)
#define SCP_GPR_HART0_REBOOT    (CORE0_R_GPR5 + uxPortGetCoreId() * 0x10000)
#define CORE_RDY_TO_REBOOT      0x34
#define CORE_REBOOT_OK          0x1
#define CORE0_R_GPR6            (REG_BASE + 0x30058)
#define SCP_GPR_HART1_REBOOT    (CORE0_R_GPR6 + uxPortGetCoreId() * 0x10000)
#define CORE0_R_GPR7            (REG_BASE + 0x3005c)
#define SCP_BOOTUP_HARTS_SYNC   (CORE0_R_GPR7 + (uxPortGetCoreId() * 0x10000))
#define HART0_BOOTUP_READY      1 << 0
#define HART1_BOOTUP_READY      1 << 1
#define CORE0_CLK_SYS_REQ_CNT   (REG_BASE + 0x30060)
#define CORE0_BUS_REQ_CNT       (REG_BASE + 0x30064)
#define CORE0_APSRC_REQ_CNT     (REG_BASE + 0x30068)
#define CORE0_STATUS            (REG_BASE + 0x30070)
#define CORE0_HARD0_HALT_BIT    1
#define CORE0_HARD1_HALT_BIT    2
#define CORE0_MON_PC            (REG_BASE + 0x30080)
#define CORE0_MON_LR            (REG_BASE + 0x30084)
#define CORE0_MON_SP            (REG_BASE + 0x30088)
#define CORE0_TBUF_WPTR         (REG_BASE + 0x3008c)
#define CORE0_MON_CCNT_LSB      (REG_BASE + 0x30090)
#define CORE0_MON_CCNT_MSB      (REG_BASE + 0x30094)
#define CORE0_MON_IRCNT_LSB     (REG_BASE + 0x30098)
#define CORE0_MON_IRCNT_MSB     (REG_BASE + 0x3009c)
#define CORE0_MON_PCNT3_LSB     (REG_BASE + 0x300a0)
#define CORE0_MON_PCNT3_MSB     (REG_BASE + 0x300a4)
#define CORE0_MON_PCNT4_LSB     (REG_BASE + 0x300a8)
#define CORE0_MON_PCNT4_MSB     (REG_BASE + 0x300ac)
#define CORE0_MON_PCNT5_LSB     (REG_BASE + 0x300b0)
#define CORE0_MON_PCNT5_MSB     (REG_BASE + 0x300b4)
#define CORE0_MON_PCNT6_LSB     (REG_BASE + 0x300b8)
#define CORE0_MON_PCNT6_MSB     (REG_BASE + 0x300bc)
#define CORE0_MON_PCNT7_LSB     (REG_BASE + 0x300c0)
#define CORE0_MON_PCNT7_MSB     (REG_BASE + 0x300c4)
#define CORE0_MON_PC_LATCH      (REG_BASE + 0x300d0)
#define CORE0_MON_LR_LATCH      (REG_BASE + 0x300d4)
#define CORE0_MON_SP_LATCH      (REG_BASE + 0x300d8)
#define CORE0_TBUF_DATA31_0     (REG_BASE + 0x300e0)
#define CORE0_TBUF_DATA63_32    (REG_BASE + 0x300e4)
#define CORE0_TBUF_DATA95_64    (REG_BASE + 0x300e8)
#define CORE0_TBUF_DATA127_96   (REG_BASE + 0x300ec)
#define CORE0_RD_L2TCM_CNT_PM   (REG_BASE + 0x30100)
#define CORE0_RD_DRAM_CNT_PM    (REG_BASE + 0x30104)
#define CORE0_RD_L2TCM_CNT_DM   (REG_BASE + 0x30108)
#define CORE0_WT_L2TCM_CNT_DM   (REG_BASE + 0x3010c)
#define CORE0_RD_DRAM_CNT_DM    (REG_BASE + 0x30110)
#define CORE0_WT_DRAM_CNT_DM    (REG_BASE + 0x30114)
#define CORE0_INTC_RX_IRQ_UART2 (REG_BASE + 0x32260)

/* CFGREG_core1 */
#define CORE1_SW_RSTN_CLR      (REG_BASE + 0x40000)
#define CORE1_SW_RSTN_SET      (REG_BASE + 0x40004)
#define CORE1_MEM_ATT_PREDEF   (REG_BASE + 0x40008)
#define CORE1_BUS_QOS          (REG_BASE + 0x4000c)
#define CORE1_DBG_CTRL         (REG_BASE + 0x40010)
#define CORE1_ITCM_ADDR_OFFSET (REG_BASE + 0x40014)
#define CORE1_DTCM_ADDR_OFFSET (REG_BASE + 0x40018)
#define CORE1_GENERAL_CTRL     (REG_BASE + 0x4001c)
#define CORE1_CLK_SYS_REQ      (REG_BASE + 0x40020)
#define CORE1_BUS_REQ          (REG_BASE + 0x40024)
#define CORE1_APSRC_REQ        (REG_BASE + 0x40028)
#define CORE1_DDREN            (REG_BASE + 0x4002c)
#define CORE1_WDT_IRQ          (REG_BASE + 0x40030)
#define CORE1_WDT_CFG          (REG_BASE + 0x40034)
#define CORE1_WDT_KICK         (REG_BASE + 0x40038)
#define CORE1_WDT_CUR_VAL      (REG_BASE + 0x4003c)
#define CORE1_R_GPR0           (REG_BASE + 0x40040)
#define SCP_GRP_CORE1_SLPDBG   CORE1_R_GPR0
#define CORE1_R_GPR1           (REG_BASE + 0x40044)
#define CORE1_R_GPR2           (REG_BASE + 0x40048)
#define CORE1_R_GPR3           (REG_BASE + 0x4004c)
#define CORE1_R_GPR4           (REG_BASE + 0x40050)
#define CORE1_R_GPR5           (REG_BASE + 0x40054)
#define CORE1_R_GPR6           (REG_BASE + 0x40058)
#define CORE1_R_GPR7           (REG_BASE + 0x4005c)

#define CORE1_CLK_SYS_REQ_CNT (REG_BASE + 0x40060)
#define CORE1_BUS_REQ_CNT     (REG_BASE + 0x40064)
#define CORE1_APSRC_REQ_CNT   (REG_BASE + 0x40068)
#define CORE1_STATUS          (REG_BASE + 0x40070)
#define CORE1_HARD0_HALT_BIT  1
#define CORE1_HARD1_HALT_BIT  2
#define CORE1_MON_PC          (REG_BASE + 0x40080)
#define CORE1_MON_LR          (REG_BASE + 0x40084)
#define CORE1_MON_SP          (REG_BASE + 0x40088)
#define CORE1_TBUF_WPTR       (REG_BASE + 0x4008c)
#define CORE1_MON_CCNT_LSB    (REG_BASE + 0x40090)
#define CORE1_MON_CCNT_MSB    (REG_BASE + 0x40094)
#define CORE1_MON_IRCNT_LSB   (REG_BASE + 0x40098)
#define CORE1_MON_IRCNT_MSB   (REG_BASE + 0x4009c)
#define CORE1_MON_PCNT3_LSB   (REG_BASE + 0x400a0)
#define CORE1_MON_PCNT3_MSB   (REG_BASE + 0x400a4)
#define CORE1_MON_PCNT4_LSB   (REG_BASE + 0x400a8)
#define CORE1_MON_PCNT4_MSB   (REG_BASE + 0x400ac)
#define CORE1_MON_PCNT5_LSB   (REG_BASE + 0x400b0)
#define CORE1_MON_PCNT5_MSB   (REG_BASE + 0x400b4)
#define CORE1_MON_PCNT6_LSB   (REG_BASE + 0x400b8)
#define CORE1_MON_PCNT6_MSB   (REG_BASE + 0x400bc)
#define CORE1_MON_PCNT7_LSB   (REG_BASE + 0x400c0)
#define CORE1_MON_PCNT7_MSB   (REG_BASE + 0x400c4)
#define CORE1_MON_PC_LATCH    (REG_BASE + 0x400d0)
#define CORE1_MON_LR_LATCH    (REG_BASE + 0x400d4)
#define CORE1_MON_SP_LATCH    (REG_BASE + 0x400d8)
#define CORE1_TBUF_DATA31_0   (REG_BASE + 0x400e0)
#define CORE1_TBUF_DATA63_32  (REG_BASE + 0x400e4)
#define CORE1_TBUF_DATA95_64  (REG_BASE + 0x400e8)
#define CORE1_TBUF_DATA127_96 (REG_BASE + 0x400ec)
#define CORE1_RD_L2TCM_CNT_PM (REG_BASE + 0x40100)
#define CORE1_RD_DRAM_CNT_PM  (REG_BASE + 0x40104)
#define CORE1_RD_L2TCM_CNT_DM (REG_BASE + 0x40108)
#define CORE1_WT_L2TCM_CNT_DM (REG_BASE + 0x4010c)
#define CORE1_RD_DRAM_CNT_DM  (REG_BASE + 0x40110)
#define CORE1_WT_DRAM_CNT_DM  (REG_BASE + 0x40114)

/* CFGREG_core_little */
#define CORE_LITTLE_STATUS         (REG_BASE + 0x3A070)
#define CORE_LITTLE_HARD0_HALT_BIT 1
#define CORE_LITTLE_HARD1_HALT_BIT 2

#define CORE_LITTLE_R_GPR0            (REG_BASE + 0x3A040)
#define SCP_GRP_COREL_SLPDBG          CORE_LITTLE_R_GPR0
#define CORE_LITTLE_R_GPR3            (REG_BASE + 0x3A04c)
#define CORE_LITTLE_EXPECTED_FREQ_REG CORE_LITTLE_R_GPR3

/* scp_bus_CTRL */
/* ??? */
#define SCP_BUS_CTRL   (REG_BASE + 0x46218)
#define BUS_DCM_TOP_EN (0x1 << 1)

#define SCP_DEBUG_AO_CTRL0  (REG_BASE + 0x47000)
#define DBG_TIMEOUT_TYPE    (0x1 << 1)
#define DBG_DEBUG_EN        (0x1 << 2)
#define DBG_DEBUG_CKEN      (0x1 << 3)
#define DBG_DEBUG_EN_TOP    (0x1 << 4)
#define DBG_TIMEOUT_IRQ     (0x1 << 8)
#define B_DBG_TIMEOUT_THRES 16

/* BUS TRACKER */
#define BUS_TRACKER_BASE        (REG_BASE + 0x80000)
#define BUS_DBG_CON             (BUS_TRACKER_BASE)
#define BUS_DBG_CON_IRQ_CLR     (0x1 << 7)
#define BUS_DBG_CON_IRQ_STA     (0xf << 8)
#define BUS_DBG_CON_AR_SLV_ERR  (0x1 << 12)
#define BUS_DBG_CON_AW_SLV_ERR  (0x1 << 13)
#define BUS_DBG_CON_SW_RST      (0x1 << 16)
#define BUS_DBG_CON_TIMEOUT_STA (0x3 << 20)
#define BUS_DBG_CON_TIMEOUT_CLR (0x1 << 23)

#define BUS_DBG_TIMER_CON0         SCP_TRACKER_CTRL2
#define BUS_DBG_TIMER0             (BUS_TRACKER_BASE + 0x00C)
#define BUS_DBG_MON                (BUS_TRACKER_BASE + 0x01C)
#define BUS_DBG_W_TRACK_DATA_VALID (BUS_TRACKER_BASE + 0x020)

/* BUS_DBG_TIMEOUT_INFO for AW, AR ... stall timeout */
#define BUS_DBG_TIMEOUT_INFO      (BUS_TRACKER_BASE + 0x028)
#define BUS_DBG_STALL_DISABLE_CFG (BUS_TRACKER_BASE + 0x02C)
#define AR_STALL_DISABLE          (0x1 << 0)
#define R_STALL_DISABLE           (0x1 << 1)
#define B_STALL_DISABLE           (0x1 << 2)
#define W_STALL_DISABLE           (0x1 << 3)
#define NO_W_VALID_CHK_DISABLE    (0x1 << 4)
#define AW_OVERFLOW_DET_DISABLE   (0x1 << 5)
#define SYSTIMER_LATCH_SLVERR_L   (BUS_TRACKER_BASE + 0x040)
#define SYSTIMER_LATCH_SLVERR_H   (BUS_TRACKER_BASE + 0x044)

/* latch systimer when "first timeout event trigger", gary code type */
#define SYSTIMER_LATCH_H (BUS_TRACKER_BASE + 0x048)
#define SYSTIMER_LATCH_L (BUS_TRACKER_BASE + 0x04C)

#define BUS_DBG_AR_SLVERR_ADDR_L (BUS_TRACKER_BASE + 0x080)
#define BUS_DBG_AR_SLVERR_ADDR_H (BUS_TRACKER_BASE + 0x084)
#define BUS_DBG_AR_SLVERR_ID     (BUS_TRACKER_BASE + 0x088)
#define BUS_DBG_AR_SLVERR_LOG    (BUS_TRACKER_BASE + 0x08C)
#define AR_SLVERR_LEN            (0xF << 0)
#define AR_SLVERR_SIZE           (0x7 << 4)
#define AR_SLVERR_SEC            (0x1 << 8)

#define BUS_DBG_AW_SLVERR_ADDR_L (BUS_TRACKER_BASE + 0x090)
#define BUS_DBG_AW_SLVERR_ADDR_H (BUS_TRACKER_BASE + 0x094)
#define BUS_DBG_AW_SLVERR_ID     (BUS_TRACKER_BASE + 0x098)
#define BUS_DBG_AW_SLVERR_LOG    (BUS_TRACKER_BASE + 0x09C)
#define AW_SLVERR_LEN            (0xF << 0)
#define AW_SLVERR_SIZE           (0x7 << 4)
#define AW_SLVERR_SEC            (0x1 << 8)

#define BUS_DBG_AR_TRACK_LOG (BUS_TRACKER_BASE + 0x200)
#define BUS_DBG_AR_TRACK_ID  (BUS_TRACKER_BASE + 0x300)
#define BUS_DBG_AR_TRACK_L   (BUS_TRACKER_BASE + 0x400)
#define BUS_DBG_AR_TRACK_H   (BUS_TRACKER_BASE + 0x600)

#define BUS_DBG_AW_TRACK_LOG (BUS_TRACKER_BASE + 0x800)
#define BUS_DBG_AW_TRACK_ID  (BUS_TRACKER_BASE + 0x900)
#define BUS_DBG_AW_TRACK_L   (BUS_TRACKER_BASE + 0xA00)
#define BUS_DBG_AW_TRACK_H   (BUS_TRACKER_BASE + 0xC00)

#define BUS_DBG_WP_CFG          (BUS_TRACKER_BASE + 0x10018)
#define SECURITY_EN             (0x1 << 0)
#define SECURITY_MASK           (0x1 << 1)
#define BUS_DBG_WP_DEF_SLV_ADDR (BUS_TRACKER_BASE + 0x1001C)
#define BUS_DBG_WP              (BUS_TRACKER_BASE + 0x10020)
#define BUS_DBG_WP_EXT          (BUS_TRACKER_BASE + 0x10024)
#define BUS_DBG_WP_MASK         (BUS_TRACKER_BASE + 0x10028)
#define BUS_DBG_WP_MASK_EXT     (BUS_TRACKER_BASE + 0x1002C)

/* CFG_DEVAPC_AO_BASE */
#define R_APC_CON        (REG_BASE + 0x48F00)
#define B_APC_VIO_ADDR   (12)
#define B_APC_VIO        (31)
#define APC_VIO_SEL_ADDR (0x3FFF << B_APC_VIO_ADDR)
#define APC_VIO_SEL_VIO  (0x1 << B_APC_VIO)

#define R_SYS0_D0_APC_0       (REG_BASE + 0x48000)
#define R_SYS0_D0_APC_1       (REG_BASE + 0x48004)
#define R_SYS0_D0_APC_2       (REG_BASE + 0x48008)
#define R_SYS0_D0_APC_3       (REG_BASE + 0x4800C)
#define R_SYS0_D1_APC_0       (REG_BASE + 0x48040)
#define R_SYS0_D1_APC_1       (REG_BASE + 0x48044)
#define R_SYS0_D1_APC_2       (REG_BASE + 0x48048)
#define R_SYS0_D2_APC_0       (REG_BASE + 0x48080)
#define R_SYS0_D2_APC_1       (REG_BASE + 0x48084)
#define R_SYS0_D2_APC_2       (REG_BASE + 0x48088)
#define R_SYS0_D3_APC_0       (REG_BASE + 0x480C0)
#define R_SYS0_D3_APC_1       (REG_BASE + 0x480C4)
#define R_SYS0_D3_APC_2       (REG_BASE + 0x480C8)
#define R_SYS0_D4_APC_0       (REG_BASE + 0x48100)
#define R_SYS0_D4_APC_1       (REG_BASE + 0x48104)
#define R_SYS0_D4_APC_2       (REG_BASE + 0x48108)
#define R_SYS0_D5_APC_0       (REG_BASE + 0x48140)
#define R_SYS0_D5_APC_1       (REG_BASE + 0x48144)
#define R_SYS0_D5_APC_2       (REG_BASE + 0x48148)
#define R_SYS0_D6_APC_0       (REG_BASE + 0x48180)
#define R_SYS0_D6_APC_1       (REG_BASE + 0x48184)
#define R_SYS0_D6_APC_2       (REG_BASE + 0x48188)
#define R_SYS0_D7_APC_0       (REG_BASE + 0x481C0)
#define R_SYS0_D7_APC_1       (REG_BASE + 0x481C4)
#define R_SYS0_D7_APC_2       (REG_BASE + 0x481C8)
#define D_RW                  0
#define D_SEC_RW              1U
#define D_SEC_RW_NOSEC_R      2U
#define D_NORW                3U
/* APC0 */
#define B_MAIN_BCRM_PDN_APC   0
#define B_PDN_RSV1_APC        2
#define B_SYST_INFRA_1_APC    4
#define B_SYST_INFRA_2_APC    6
#define B_SYST_INFRA_4_APC    8
#define B_AUDIO_S_1_APC       10
#define B_L1TCM_APC           12
#define B_PAR_TOP_APC         14
#define B_CLK_CTRL_APC        16
#define B_SPMI_APC            18
#define B_VOW_APC             20
#define B_CFGREG_APC          22
#define B_GPIO_APC            24
#define B_UART0_APC           26
#define B_UART1_APC           28
#define B_I2C0_APC            30
/* APC1 */
#define B_I2C1_APC            0
#define B_SPI0_APC            2
#define B_SPI1_APC            4
#define B_SPI2_APC            6
#define B_EINT_APC            8
#define B_RSV00_APC           10
#define B_CFG_CORE0_APC       12
#define B_DMA_CORE0_APC       14
#define B_INTC_CORE0_APC      16
#define B_TMR_CORE0_APC       18
#define B_DBG_CORE0_APC       20
#define B_SPI3_APC            22
#define B_I2C2_APC            24
#define B_I2C3_APC            26
#define B_RSV01_APC           28
#define B_CFG_CORE1_APC       30
/* APC2 */
#define B_DMA_CORE1_APC       0
#define B_INTC_CORE1_APC      2
#define B_TMR_CORE1_APC       4
#define B_DBG_CORE1_APC       6
#define B_RSV03_APC           8
#define B_BCRM_APC            10
#define B_BUS_DEBUG_APC       12
#define B_TRACKER_APC         14
#define B_DMA_I2C_APC         16
#define B_BACKUP1_APC         18
#define B_BACKUP2_APC         20
#define B_BACKUP3_APC         22
#define B_BACKUP4_APC         24
#define B_RSV10_APC           26
#define B_CACHE_DBG_CORE0_APC 28
#define B_CACHE_DBG_CORE1_APC 30
/* APC3 */
#define B_DEV_APC_AO_APC      0
#define B_DEV_APC_APC         2
#define B_CFGREG_SEC_APC      4
#define B_RSV_BCRM_PDN_APC    6
#define B_RSV11_APC           8
#define B_I2C_WRAP_APC        10
#define B_RSV12_APC           12
#define B_MBOX0_APC           14
#define B_MBOX1_APC           16
#define B_MBOX2_APC           18
#define B_MBOX3_APC           20
#define B_MBOX4_APC           22
#define B_RSV13_APC           24

/* DEVAPC */
#define R_TSIP_AO_D0_VIO_MASK_0        (REG_BASE + 0x4C000)
#define R_TSIP_AO_D0_VIO_MASK_1        (REG_BASE + 0x4C004)
#define R_TSIP_AO_D0_VIO_MASK_2        (REG_BASE + 0x4C008)
#define R_TSIP_AO_D0_VIO_MASK_3        (REG_BASE + 0x4C00C)
#define R_TSIP_AO_D0_VIO_MASK_4        (REG_BASE + 0x4C010)
#define R_TSIP_AO_D0_VIO_STA_0         (REG_BASE + 0x4C400)
#define R_TSIP_AO_D0_VIO_STA_1         (REG_BASE + 0x4C404)
#define R_TSIP_AO_D0_VIO_STA_2         (REG_BASE + 0x4C408)
#define R_TSIP_AO_D0_VIO_STA_3         (REG_BASE + 0x4C40C)
#define R_TSIP_AO_D0_VIO_STA_4         (REG_BASE + 0x4C410)
#define R_TSIP_AO_VIO_DBG0             (REG_BASE + 0x4C900)
#define B_AO_PDN_DMN_ID                (0)
#define B_AO_PDN_W_VIO                 (6)
#define B_AO_PDN_R_VIO                 (7)
#define AO_PDN_SEL_DMN_ID              (0x1 << B_AO_PDN_DMN_ID)
#define AO_PDN_SEL_W_VIO               (0x1 << B_AO_PDN_W_VIO)
#define AO_PDN_SEL_R_VIO               (0x1 << B_AO_PDN_R_VIO)
#define R_TSIP_AO_VIO_DBG1             (REG_BASE + 0x4C904)
#define R_TSIP_AO_VIO_DBG2             (REG_BASE + 0x4C908)
#define R_TSIP_AO_VIO_DBG3             (REG_BASE + 0x4C90C)
#define R_TSIP_AO_PDN_APC_CON          (REG_BASE + 0x4CF00)
#define B_AO_PDN_APC_VIO_ADDR          (16)
#define B_AO_PDN_APC_VIO               (31)
#define B_AO_PDN_VIO_AUTO_CLR_EN       (8)
#define AO_PDN_APC_VIO_SEL_ADDR        (0xFFF << B_AO_PDN_APC_VIO_ADDR)
#define AO_PDN_APC_VIO_SEL_VIO         (0x1 << B_AO_PDN_APC_VIO)
#define AO_PDN_APC_VIO_SEL_AUTO_CLR_EN (0x1 << B_AO_PDN_VIO_AUTO_CLR_EN)
#define R_TSIP_AO_VIO_SHFT_CON         (REG_BASE + 0x4CF10)
#define B_AO_PDN_APC_VIO_SHFT_EN       (0)
#define B_AO_PDN_APC_VIO_SHFT_DONE     (1)
#define AO_PDN_APC_VIO_SHFT_SEL_EN     (0x1 << B_AO_PDN_APC_VIO_SHFT_EN)
#define AO_PDN_APC_VIO_SHFT_SEL_DONE   (0x1 << B_AO_PDN_APC_VIO_SHFT_DONE)

#define R_TSIP_AO_VIO_SHFT_STA_0 (REG_BASE + 0x4CF20)
#define R_TSIP_AO_VIO_SHFT_SEL_0 (REG_BASE + 0x4CF30)

/* CFG_SEC_BASE */
#define R_SECURE_CTRL         (REG_BASE + 0x2A000)
#define B_DBGEN_LOCK          (1 << 0)
#define B_OCD_BYPASS_JTAG     (1 << 1)
#define B_V_REQ_SECURE_DIS    (1 << 4)
#define B_MBOX0_SIZE          (1 << 5)
#define B_MBOX1_SIZE          (1 << 6)
#define B_MBOX2_SIZE          (1 << 7)
#define B_MBOX3_SIZE          (1 << 8)
#define B_MBOX4_SIZE          (1 << 9)
#define B_MBOX5_SIZE          (1 << 10)
#define B_CORE1_PROG_REMAP_EN (1 << 12)
#define B_CORE1_DATA_REMAP_EN (1 << 13)
#define B_COREL_PROG_REMAP_EN (1 << 14)
#define B_COREL_DATA_REMAP_EN (1 << 15)

#define B_CORE0_CACHE_DBG_EN (1 << 28)
#define B_CORE1_CACHE_DBG_EN (1 << 29)

#define MBOX_BASE0 (REG_BASE + 0x2A020)
#define MBOX_BASE1 (REG_BASE + 0x2A024)
#define MBOX_BASE2 (REG_BASE + 0x2A028)
#define MBOX_BASE3 (REG_BASE + 0x2A02C)
#define MBOX_BASE4 (REG_BASE + 0x2A030)
#define MBOX_BASE5 (REG_BASE + 0x2A034)

#define R_GPR0_CFGREG_SEC     (REG_BASE + 0x2A040)
#define AOVDRAM_RESV_ADDR_REG R_GPR0_CFGREG_SEC
#define R_GPR1_CFGREG_SEC     (REG_BASE + 0x2A044)
#define AOVDRAM_RESV_SIZE_REG R_GPR1_CFGREG_SEC
#define R_GPR2_CFGREG_SEC     (REG_BASE + 0x2A048)
#define ILDO_EFUSE_DATA       R_GPR2_CFGREG_SEC
#define R_GPR3_CFGREG_SEC     (REG_BASE + 0x2A04C)

#define R_REMAP_L1C1             (REG_BASE + 0x2A050)
#define R_REMAP_L1C2             (REG_BASE + 0x2A054)
#define R_REMAP_L1C3             (REG_BASE + 0x2A058)
#define R_REMAP_L1C_OTHER        (REG_BASE + 0x2A05c)
#define L1C_SHIFT_MASK           0xfff00000
#define L1C_ALIGN                0x00100000
#define L1C_EXT_ADDR_SHIFT       20
#define L1C_EXT_OTHER_ADDR_SHIFT 27

#define R_REMAP_OXx123 (REG_BASE + 0x2A060)
/* scp view
 * 0x4XXX_XXXX: bit[0:8] replace bit[27:35]
 * 0x5XXX_XXXX: bit[16:23] replace bit[28:35]
 * 0x6XXX_XXXX: bit[24:31] replace bit[28:35]
 */
#define R_REMAP_OX4x56 (REG_BASE + 0x2A064)
#define R_REMAP_OX89AB (REG_BASE + 0x2A068)
#define R_REMAP_OXCDEF (REG_BASE + 0x2A06c)

/* L2TCM SEC CONTROL */
#define R_L2TCM_SEC_SET_R0    (REG_BASE + 0x2A090)
#define R_L2TCM_SEC_SET_R1    (REG_BASE + 0x2A094)
#define R_L2TCM_SEC_SET_R2    (REG_BASE + 0x2A098)
#define R_L2TCM_SEC_SET_R3    (REG_BASE + 0x2A09C)
#define R_L2TCM_SEC_SET_R0_0  (REG_BASE + 0x2A0E0)
#define R_L2TCM_SEC_SET_R1_0  (REG_BASE + 0x2A0E4)
#define R_L2TCM_SEC_SET_R2_0  (REG_BASE + 0x2A0E8)
#define R_L2TCM_SEC_SET_R3_0  (REG_BASE + 0x2A0EC)
#define SEC_RW_NOSEC_RW       (0)
#define SEC_RW_NOSEC_BLOCK    (1)
#define SEC_RW_NOSEC_RO       (2)
#define SEC_RW_NOSEC_WO       (3)
#define SEC_RO_NOSEC_RO       (4)
#define SEC_BLOCK_NOSEC_BLOCK (5)
#define SEC_SET_D15           (28)
#define SEC_SET_D14           (24)
#define SEC_SET_D13           (20)
#define SEC_SET_D12           (16)
#define SEC_SET_D11           (12)
#define SEC_SET_D10           (8)
#define SEC_SET_D9            (4)
#define SEC_SET_D8            (0)
#define SEC_SET_D7            (28)
#define SEC_SET_D6            (24)
#define SEC_SET_D5            (20)
#define SEC_SET_D4            (16)
#define SEC_SET_D3            (12)
#define SEC_SET_D2            (8)
#define SEC_SET_D1            (4)
#define SEC_SET_D0            (0)

#define R_L2TCM_SEC_ADDR0     (REG_BASE + 0x2A0A0)
#define R_L2TCM_SEC_ADDR1     (REG_BASE + 0x2A0A4)
#define R_L2TCM_SEC_ADDR2     (REG_BASE + 0x2A0A8)
#define R_L2TCM_SEC_REGION_EN (REG_BASE + 0x2A0AC)
#define L2TCM_REGION_EN       (1)
#define L2TCM_REG0            (0)
#define L2TCM_REG1            (1)
#define L2TCM_REG2            (2)
#define L2TCM_REG3            (3)

#define R_L2TCM_OFFSET_RANGE_0_LOW  (REG_BASE + 0x2A0b0)
#define R_L2TCM_OFFSET_RANGE_0_HIGH (REG_BASE + 0x2A0b4)
#define R_L2TCM_OFFSET_RANGE_1_LOW  (REG_BASE + 0x2A0b8)
#define R_L2TCM_OFFSET_RANGE_1_HIGH (REG_BASE + 0x2A0bc)
#define R_EXT_OFFSET_RANGE_0_LOW    (REG_BASE + 0x2A0c0)
#define R_EXT_OFFSET_RANGE_0_HIGH   (REG_BASE + 0x2A0c4)
#define R_EXT_OFFSET_RANGE_1_LOW    (REG_BASE + 0x2A0c8)
#define R_EXT_OFFSET_RANGE_1_HIGH   (REG_BASE + 0x2A0cc)
#define R_L2TCM_OFFSET_ADD          (REG_BASE + 0x2A0d0)
#define R_EXT_OFFSET_ADD            (REG_BASE + 0x2A0d4)

#define GPIO_BASE          0x70025000
#define UART0_BASE         0x70026000
#define UART1_BASE         0x70027000
#define UART2_BASE         0x70038000
#define UART3_BASE         0x70028000
#define I2C0_BASE          0x70400000
#define I2C1_BASE          0x70440000
#define I2C2_BASE          0x70480000
#define I2C3_BASE          0x704C0000
#define I2C4_BASE          0x70500000
#define I2C5_BASE          0x70540000
#define I2C6_BASE          0x70580000
#define I2C7_BASE          0x705C0000
#define I2C8_BASE          0x70600000
#define I2C9_BASE          0x70640000
#define I2C10_BASE         0x70690000
#define I2C_WRAP_BASE      0x70680000
#define FAST_I2C_WRAP_BASE 0x706D0000
/* the base address of i2c at the ap side */
#define AP_I2C7_BASE       AP_BASE + 0x03AB0000
#define AP_I2C8_BASE       AP_BASE + 0x03B30000
#define AP_I2C_WRAP_BASE   AP_BASE + 0x03C30000

#define SPI0_BASE 0x706E1000
#define SPI1_BASE 0x706E9000
#define SPI2_BASE 0x706F1000
#define SPI3_BASE 0x706F9000

#define EINT_BASE  0x7002d000
#define EINT_D0_EN 0x7002d400
#define EINT_D1_EN 0x7002d420

#define CFGREG_CORE0_BASE 0x70030000
#define CFGREG_CORE1_BASE 0x70040000

#define CFGREG_CORE_BASE_REG (CFGREG_CORE0_BASE + (uxPortGetCoreId() * 0x10000))
#define CLK_SYS_REQ_OFF      (0x20)
#define BUS_REQ_OFF          (0x24)
#define APSRC_REQ_OFF        (0x28)
#define DDREN_REQ_OFF        (0x2C)

/* Resource */
/* to support SMP task migration, the same REQ_REG is required */
#define CLK_SYS_REQ (CFGREG_CORE0_BASE + CLK_SYS_REQ_OFF) /* 26M   */
#define BUS_REQ     (CFGREG_CORE0_BASE + BUS_REQ_OFF)     /* Infra */
#define APSRC_REQ   (CFGREG_CORE0_BASE + APSRC_REQ_OFF)   /* Apsrc  */
#define DDREN_REQ   (CFGREG_CORE0_BASE + DDREN_REQ_OFF)   /* Ddren */
#define B_REQ_EN    (1 << 0)                              /* REQ BIT */
#define B_REQ_ACK   (1 << 16)                             /* ACK BIT */

#define EMI_REQ_OFF     (0x184)
#define VCORE_REQ_OFF   (0x188)
#define PMIC_REQ_OFF    (0x18c)
#define BUS_PLL_REQ_OFF (0x190)
#define AOV_REQ_OFF     (0x1a4)
#define EMI_REQ         (CFGREG_CORE0_BASE + EMI_REQ_OFF)     /* EMI     */
#define VCORE_REQ       (CFGREG_CORE0_BASE + VCORE_REQ_OFF)   /* VCORE   */
#define PMIC_REQ        (CFGREG_CORE0_BASE + PMIC_REQ_OFF)    /* PMIC NM */
#define BUS_PLL_REQ     (CFGREG_CORE0_BASE + BUS_PLL_REQ_OFF) /* BUS_PLL */
#define AOV_REQ         (CFGREG_CORE0_BASE + AOV_REQ_OFF)     /* AOV BUS */

#define AOV_REQ_CNT       (CFGREG_CORE0_BASE + 0x1a8)
#define RESOURCE_IRQ_EN   (28)
#define RESOURCE_CNT_MASK (0x003fffff)

/* DRAM ACK TIMEOUT DEBUGGING */

/* CFG_DMA_SUPPORT */
#define SCP_DMA_CORE0_BASE      0x70031000
#define SCP_I2C_DMA_BASE        0x70700000
#define SCP_IRQ_CTRL_CORE0_BASE 0x70032000

#define I2C0_DMA_BASE    (SCP_I2C_DMA_BASE + 0x20000)
#define I2C1_DMA_BASE    (SCP_I2C_DMA_BASE + 0x40000)
#define I2C2_DMA_BASE    (SCP_I2C_DMA_BASE + 0x60000)
#define I2C3_DMA_BASE    (SCP_I2C_DMA_BASE + 0x80000)
#define I2C4_DMA_BASE    (SCP_I2C_DMA_BASE + 0xA0000)
#define I2C5_DMA_BASE    (SCP_I2C_DMA_BASE + 0xC0000)
#define I2C6_DMA_BASE    (SCP_I2C_DMA_BASE + 0xE0000)
#define I2C7_DMA_BASE    (SCP_I2C_DMA_BASE + 0x100000)
#define I2C8_DMA_BASE    (SCP_I2C_DMA_BASE + 0x120000)
#define I2C9_DMA_BASE    (SCP_I2C_DMA_BASE + 0x140000)
#define I2C10_DMA_BASE   (SCP_I2C_DMA_BASE + 0x160000)
#define AP_I2C7_DMA_BASE AP_BASE + 0x06420000
#define AP_I2C8_DMA_BASE AP_BASE + 0x06450000

#define CORE0_INTC_IRQ_GRP0_0 (SCP_IRQ_CTRL_CORE0_BASE + 0x50)
#define CORE0_INTC_IRQ_GRP0_1 (SCP_IRQ_CTRL_CORE0_BASE + 0x54)
#define CORE0_INTC_IRQ_GRP4_0 (SCP_IRQ_CTRL_CORE0_BASE + 0x90)
#define CLK_CTRL_IRQ_EN_BIT   12
#define CLK_CTRL_IRQ_EN       (1 << 12)
#define CORE0_INTC_IRQ_GRP0_2 (SCP_IRQ_CTRL_CORE0_BASE + 0x58)

#define CORE0_INTC_SLP_WAKE_EN0 (SCP_IRQ_CTRL_CORE0_BASE + 0x240)
#define CORE0_INTC_SLP_WAKE_EN1 (SCP_IRQ_CTRL_CORE0_BASE + 0x244)
#define CORE0_INTC_SLP_WAKE_EN2 (SCP_IRQ_CTRL_CORE0_BASE + 0x248)
#define CORE0_INTC_IRQ_EN0      (SCP_IRQ_CTRL_CORE0_BASE + 0x20)
#define CORE0_INTC_IRQ_EN1      (SCP_IRQ_CTRL_CORE0_BASE + 0x24)
#define CORE0_INTC_IRQ_EN2      (SCP_IRQ_CTRL_CORE0_BASE + 0x28)

/*******************************************************************
 * Registers for XGPT
 *******************************************************************/
#define SCP_TIMER_CORE0_BASE 0x70033000

/* LATCH TIMER ENABLE BIT SHIFT */
#define ENABLE_BIT_SHIFT 0x06

/*******************************************************************
 * Registers for Systick
 *******************************************************************/
#define TIMER_CPU_TICK_IRQ 0x7003001C

#define DEBUG_APB_CORE0_BASE 0x70034000

/********************************************************************/

#define SCP_DMA_CORE1_BASE      0x70041000
#define SCP_IRQ_CTRL_CORE1_BASE 0x70042000

#define CORE1_INTC_IRQ_GRP0_0 (SCP_IRQ_CTRL_CORE1_BASE + 50)
#define CORE1_INTC_IRQ_GRP0_1 (SCP_IRQ_CTRL_CORE1_BASE + 54)
#define CORE1_INTC_IRQ_GRP0_2 (SCP_IRQ_CTRL_CORE1_BASE + 58)

#define CORE1_INTC_SLP_WAKE_EN0 (SCP_IRQ_CTRL_CORE1_BASE + 240)
#define CORE1_INTC_SLP_WAKE_EN1 (SCP_IRQ_CTRL_CORE1_BASE + 244)
#define CORE1_INTC_SLP_WAKE_EN2 (SCP_IRQ_CTRL_CORE1_BASE + 248)

#define SCP_TIMER_CORE1_BASE 0x70043000
#define DEBUG_APB_CORE1_BASE 0x70044000

#define PERI_BUS_BCRM_BASE  0x70052000
#define PERI_BUS_DEBUG_BASE 0x70053000

#define CORE0_CACHE_RAM_BASE 0x70060000
#define CORE1_CACHE_RAM_BASE 0x70060000
#define MAIN_BUS_DEVAPCAO    0x70048000
#define PERI_BUS_DEVAPCAO    0x700a4000
#define CFG_SEC_BASE         0x7002A000
#define MAIN_BUS_DEVAPC      0x7004C000
#define PERI_BUS_DEVAPC      0x700a9000

/* INTC reg */
#define INTC_IRQ_BASE (SCP_IRQ_CTRL_CORE0_BASE + uxPortGetCoreId() * 0x10000)

#define INTC_IRQ_RAW_STA0  (INTC_IRQ_BASE + 0x000)
#define INTC_IRQ_RAW_STA4  (INTC_IRQ_BASE + 0x264)
#define INTC_IRQ_STA0      (INTC_IRQ_BASE + 0x010)
#define INTC_IRQ_STA4      (INTC_IRQ_BASE + 0x268)
#define INTC_IRQ_EN0       (INTC_IRQ_BASE + 0x020)
#define INTC_IRQ_EN4       (INTC_IRQ_BASE + 0x26C)
#define INTC_IRQ_POL0      (INTC_IRQ_BASE + 0x040)
#define INTC_IRQ_POL4      (INTC_IRQ_BASE + 0x274)
#define INTC_IRQ_GRP0_0    (INTC_IRQ_BASE + 0x050)
#define INTC_IRQ_GRP0_4    (INTC_IRQ_BASE + 0x278)
#define INTC_IRQ_GRP0_STA0 (INTC_IRQ_BASE + 0x150)
#define INTC_IRQ_GRP0_STA4 (INTC_IRQ_BASE + 0x2B4)
#define INTC_SLP_WAKE_EN0  (INTC_IRQ_BASE + 0x240)
#define INTC_SLP_WAKE_EN4  (INTC_IRQ_BASE + 0x2F0)
#define INTC_IRQ_OUT       (INTC_IRQ_BASE + 0x250)
#define INTC_IRQ_CLR_TRG   (INTC_IRQ_BASE + 0x254)
#define INTC_UART_RX_IRQ   (INTC_IRQ_BASE + 0x258)
#define INTC_IRQ_WAKE_EN0  INTC_SLP_WAKE_EN0
#define INTC_IRQ_WAKE_EN4  INTC_SLP_WAKE_EN4

/* temp patch */
#define SCP_TIMER0_IRQ_CTRL   0
#define IPC0_IRQ_EN           0
#define CLK_CTRL_IRQn         0
#define IPI_DVT_TEST          0
#define SCP_INTC_IRQ_ENABLE   0
#define SCP_INTC_IRQ_SLEEP_EN 0
#define CLK_CTRL_SLP_IRQ_EN   0
#define EINT_SLP_IRQ_EN       0
#define IPC0_SLP_IRQ_EN       0
#define SCP_TIMER0_EN         0
#define SCP_TIMER0_RST_VAL    0
#define SCP_A_TO_HOST         0
#define SCP_SECURE_CRTL       0
#define SCP_ONE_TIME_LOCK     0
#define SCP_SLP_PROTECT_CFG   0
#define SCP_FPU_FLAGS         0
#define CM4_CONTROL           0
#define TCM_LOCK_CFG          0
#define AP_RESOURCE           0
#define BUS_RESOURCE          0
#define WDT_REG_BASE          0

#define INFRA2MM_BASE  0x30000000 /* scp view: 0x3000_0000 to ap view: 0x3000_0000 */
#define APU_BASE       0x4C000000 /* scp view: 0x4000_0000 to ap view: 0x4800_0000 */
#define remap_mask_0x4 0xF8000000 /* scp remap 0x4 bit[35:27] */
#define remap_val_0x4  ((APU_BASE & remap_mask_0x4) >> 27)

/* SLB BASE */
/* AP site RG Base */
#define AP_BASE              0x60000000 /* 0x1000_0000 remap to 0x6 */
#define TOPCK_BASE           (AP_BASE + 0x0)
#define DVFSRC_BASE          (AP_BASE + 0x12000)
#define AP_GPIO_BASE         (AP_BASE + 0x2D000)
#define AP_UART0_BASE        (AP_BASE + 0x6000000)
#define INFRACFG_AO_REG_BASE (AP_BASE + 0x6640000)
#define VLP_BASE             (AP_BASE + 0x0C016000)
#define SPM2SCP_CLR          (AP_BASE + 0xC00187C)
/* PLL_ULPOSC1_CON0/PLL_ULPOSC2_CON0 */
#define ULPOSC1_CON0         (VLP_BASE + 0x200)
#define ULPOSC2_CON0         (VLP_BASE + 0x210)
#define RG_OSC_CALI_MSK_EX   0x3
#define RG_OSC_CALI_SHFT_EX  7
#define RG_OSC_CALI_MSK      0x7f
#define RG_OSC_CALI_SHFT     0
#define RG_OSC_IBAND_MSK     0x7f
#define RG_OSC_IBAND_SHFT    9
#define RG_OSC_FBAND_MSK     0x1f
#define RG_OSC_FBAND_SHFT    16
#define RG_OSC_DIV_MSK       0x3f
#define RG_OSC_DIV_SHFT      21
#define RG_OSC_CP_EN_MSK     0x1
#define RG_OSC_CP_EN_SHFT    27

/* PLL_ULPOSC1_CON1/PLL_ULPOSC2_CON1 */
#define ULPOSC1_CON1        (VLP_BASE + 0x204)
#define ULPOSC2_CON1        (VLP_BASE + 0x214)
#define RG_OSC_32KCALI_MSK  0xff
#define RG_OSC_32KCALI_SHFT 0
#define RG_OSC_RSV1_MSK     0xff
#define RG_OSC_RSV1_SHFT    8
#define RG_OSC_RSV2_MSK     0xff
#define RG_OSC_RSV2_SHFT    16
#define RG_OSC_MOD_MSK      0x3
#define RG_OSC_MOD_SHFT     24
#define RG_OSC_DIV2_EN_MSK  0x1
#define RG_OSC_DIV2_EN_SHFT 26
#define RG_OSC_OUTSEL_MSK   0xf
#define RG_OSC_OUTSEL_SHFT  27

/* PLL_ULPOSC1_CON1/PLL_ULPOSC2_CON1 */
#define ULPOSC1_CON2     (VLP_BASE + 0x208)
#define ULPOSC2_CON2     (VLP_BASE + 0x218)
#define RG_OSC_BIAS_MSK  0xff
#define RG_OSC_BIAS_SHFT 0

/* SCP PLL MUX RG */
#define CLK_CFG_UPDATE       (VLP_BASE + 0x0004)
#define SCP_CK_UPDATE_SHFT   0
#define CLK_CFG_0            (VLP_BASE + 0x0010)
#define CLK_CFG_0_SET        (VLP_BASE + 0x0014)
#define CLK_CFG_0_CLR        (VLP_BASE + 0x0018)
#define CLK_SCP_SEL_MSK      0x7
#define CLK_SCP_SEL_SHFT     0
#define CLK_SCP_SEL_PDN_SHFT 7

/* FREQUENCY METER CONTROL */
#define VLP_FQMTR_CON0          (VLP_BASE + 0x0230)
#define VLP_FQMTR_CON1          (VLP_BASE + 0x0234)
#define VLP_CLK_PROT_IDLE_REG_0 (VLP_BASE + 0x0304)

/* PMIC SSHUB INIT */
#ifndef MT8678_PMIC_SUPPORT
/* VSRAM_CORE VBUCK4 */
#define RG_BUCK_VBUCK4_HW3_OP_EN        (0x168f)
#define RG_BUCK_VBUCK4_HW3_OP_EN_MSK    0x1
#define RG_BUCK_VBUCK4_HW3_OP_EN_SHFT   3
#define RG_BUCK_VBUCK4_HW3_OP_CFG       (0x1692)
#define RG_BUCK_VBUCK4_HW3_OP_CFG_MSK   0x1
#define RG_BUCK_VBUCK4_HW3_OP_CFG_SHFT  3
#define RG_BUCK_VBUCK4_HW3_OP_MODE      (0x1695)
#define RG_BUCK_VBUCK4_HW3_OP_MODE_MSK  0x1
#define RG_BUCK_VBUCK4_HW3_OP_MODE_SHFT 3
#define RG_BUCK_VBUCK4_SSHUB_VOSEL      (0x169b)
#define RG_BUCK_VBUCK4_SSHUB_VOSEL_MSK  0xff
#define RG_BUCK_VBUCK4_SSHUB_VOSEL_SHFT 0
#define RG_BUCK_VBUCK4_SSHUB_EN         (0x169a)
#define RG_BUCK_VBUCK4_SSHUB_EN_MSK     0x1
#define RG_BUCK_VBUCK4_SSHUB_EN_SHFT    0
#else
/* VSRAM_CORE VBUCK1 */
#define RG_BUCK_VBUCK1_HW3_OP_EN        (0x150f)
#define RG_BUCK_VBUCK1_HW3_OP_EN_MSK    0x1
#define RG_BUCK_VBUCK1_HW3_OP_EN_SHFT   3
#define RG_BUCK_VBUCK1_HW3_OP_CFG       (0x1512)
#define RG_BUCK_VBUCK1_HW3_OP_CFG_MSK   0x1
#define RG_BUCK_VBUCK1_HW3_OP_CFG_SHFT  3
#define RG_BUCK_VBUCK1_HW3_OP_MODE      (0x1515)
#define RG_BUCK_VBUCK1_HW3_OP_MODE_MSK  0x1
#define RG_BUCK_VBUCK1_HW3_OP_MODE_SHFT 3
#define RG_BUCK_VBUCK1_SSHUB_VOSEL      (0x151b)
#define RG_BUCK_VBUCK1_SSHUB_VOSEL_MSK  0xff
#define RG_BUCK_VBUCK1_SSHUB_VOSEL_SHFT 0
#define RG_BUCK_VBUCK1_SSHUB_EN         (0x151a)
#define RG_BUCK_VBUCK1_SSHUB_EN_MSK     0x1
#define RG_BUCK_VBUCK1_SSHUB_EN_SHFT    0
#endif /* MT8678_PMIC_SUPPORT */
/* VS3 BUCK */
#define RG_BUCK_VS3_HW3_OP_EN              (0x190f) /* 0x0 => 0x1 */
#define RG_BUCK_VS3_HW3_OP_EN_MSK          0x1
#define RG_BUCK_VS3_HW3_OP_EN_SHFT         3
#define RG_BUCK_VS3_HW3_OP_CFG             (0x1912) /* 0x0 => 0x0 */
#define RG_BUCK_VS3_HW3_OP_CFG_MSK         0x1
#define RG_BUCK_VS3_HW3_OP_CFG_SHFT        3
#define RG_BUCK_VS3_HW3_OP_MODE            (0x1915) /* 0x1 => 0x0 */
#define RG_BUCK_VS3_HW3_OP_MODE_MSK        0x1
#define RG_BUCK_VS3_HW3_OP_MODE_SHFT       3
#define RG_BUCK_VS3_VOTER_CON0             (0x191a) /* vs3 voter */
#define RG_BUCK_VS3_VOTER_CON0_MSK         0xff
#define RG_BUCK_VS3_VOTER_CON0_SHFT        0
#define RG_BUCK_VS3_VOTER_CON0_SET         (0x191b)
#define RG_BUCK_VS3_VOTER_CON0_SET_MSK     0x1
#define RG_BUCK_VS3_VOTER_CON0_SET_SHFT    (6 + uxPortGetCoreId())
#define RG_BUCK_VS3_VOTER_CON0_CLR         (0x191c)
#define RG_BUCK_VS3_VOTER_CON0_CLR_MSK     0x1
#define RG_BUCK_VS3_VOTER_CON0_CLR_SHFT    (6 + uxPortGetCoreId())
/* VSRAM_APU LDO */
#define RG_LDO_VSRAM_APU_VOSEL             (0x1b47)
#define RG_LDO_VSRAM_APU_VOSEL_MSK         0x7f
#define RG_LDO_VSRAM_APU_VOSEL_SHFT        0
#define RG_LDO_VSRAM_APU_VOSEL_SLEEP       (0x1ea3) /* 0.55v */
#define RG_LDO_VSRAM_APU_VOSEL_SLEEP_MSK   0x7f
#define RG_LDO_VSRAM_APU_VOSEL_SLEEP_SHFT  0
#define RG_LDO_TOP_RSV0                    (0x1b34) /* 0x0 => 0x1 */
#define RG_LDO_TOP_RSV0_MSK                0xf
#define RG_LDO_TOP_RSV0_SHFT               4
#define RG_LDO_VSRAM_APU_ONLV_EN           (0x1e9e) /* b'1: ONLV, b'0: no ONLV */
#define RG_LDO_VSRAM_APU_ONLV_EN_MSK       0x1
#define RG_LDO_VSRAM_APU_ONLV_EN_SHFT      3
#define RG_LDO_VSRAM_APU_RC11_OP_EN        (0x1eab) /* 0x0 => 0x1 */
#define RG_LDO_VSRAM_APU_RC11_OP_EN_MSK    0x1
#define RG_LDO_VSRAM_APU_RC11_OP_EN_SHFT   3
#define RG_LDO_VSRAM_APU_RC11_OP_CFG       (0x1eae) /* 0x0 => 0x0 */
#define RG_LDO_VSRAM_APU_RC11_OP_CFG_MSK   0x1
#define RG_LDO_VSRAM_APU_RC11_OP_CFG_SHFT  3
#define RG_LDO_VSRAM_APU_RC11_OP_MODE      (0x1eb1) /* 0x0 => 0x0 */
#define RG_LDO_VSRAM_APU_RC11_OP_MODE_MSK  0x1
#define RG_LDO_VSRAM_APU_RC11_OP_MODE_SHFT 3

/* DVFSRC VCORE REQUEST CONTROL */
#define DVFSRC_VCORE_REQUEST (DVFSRC_BASE + 0x6C)
#define VCORE_SCP_MSK        0x7
#define VCORE_SCP_SHFT       12
#define DVFSRC_CURRENT       (DVFSRC_BASE + 0xD44)
#define DVFSRC_TARGET        (DVFSRC_BASE + 0xD48)

/* INFRA IRQ REG*/

#define CLK_AP_CG_CTRL_SET (INFRACFG_AO_REG_BASE + 0x24)
#define CLK_AP_CG_CTRL_CLR (INFRACFG_AO_REG_BASE + 0x28)
#define CLK_AP_CG_CTRL_STA (INFRACFG_AO_REG_BASE + 0x10)
#define CLK_AP_UART1_CLK   (1 << 0)

#define SCP_INFRA_IRQ_STA    (TOPCK_BASE + 0x1b10)
#define INFRA_IRQ_SET        (TOPCK_BASE + 0x1b14)
#define INFRA_IRQ_CLR        (TOPCK_BASE + 0x1b18)
#define AP_AWAKE_LOCK        (0)
#define AP_AWAKE_UNLOCK      (1)
#define CONNSYS_AWAKE_LOCK   (2)
#define CONNSYS_AWAKE_UNLOCK (3)
#define CONNSYS_AWAKE_IRQ    (4)
#define CONNSYS_BT_AWAKE_IRQ (6)

/* mbox irq reg */
#define MBOX0_OUT_IRQ_SET (REG_BASE + 0xA0104)
#define MBOX1_OUT_IRQ_SET (REG_BASE + 0xB0104)
#define MBOX2_OUT_IRQ_SET (REG_BASE + 0xC0104)
#define MBOX3_OUT_IRQ_SET (REG_BASE + 0xD0104)
#define MBOX4_OUT_IRQ_SET (REG_BASE + 0xE0104)
#define MBOX5_OUT_IRQ_SET (REG_BASE + 0xF0104)

#define MBOX0_IN_IRQ_CLR (REG_BASE + 0xA0108)
#define MBOX1_IN_IRQ_CLR (REG_BASE + 0xB0108)
#define MBOX2_IN_IRQ_CLR (REG_BASE + 0xC0108)
#define MBOX3_IN_IRQ_CLR (REG_BASE + 0xD0108)
#define MBOX4_IN_IRQ_CLR (REG_BASE + 0xE0108)
#define MBOX5_IN_IRQ_CLR (REG_BASE + 0xF0108)

#define MBOX0_OUT_IRQ_CLR (REG_BASE + 0xA010C)
#define MBOX1_OUT_IRQ_CLR (REG_BASE + 0xB010C)
#define MBOX2_OUT_IRQ_CLR (REG_BASE + 0xC010C)
#define MBOX3_OUT_IRQ_CLR (REG_BASE + 0xD010C)
#define MBOX4_OUT_IRQ_CLR (REG_BASE + 0xE010C)
#define MBOX5_OUT_IRQ_CLR (REG_BASE + 0xF010C)

#define APB_BASE_ADDR (REG_BASE + 0x9000000)
#define APB_END_ADDR  (APB_BASE_ADDR + 0x400000)

/* SPI MASTER MAX SUPPORT */
#define SPI_HOST_NUM (4)

/* SENTRY */
#define AP_SCP_DRAM_OFFSET 0X10000000

#define SCP_SIZE_128K 0x20000
#define SCP_SIZE_64K  0x10000
#define SCP_SIZE_1M   0x100000
#define SCP_SIZE_2M   (2 * SCP_SIZE_1M)
#define SCP_SIZE_6M   (6 * SCP_SIZE_1M)
#define SCP_SIZE_50M  (50 * SCP_SIZE_1M)

#define SCP_SIZE_60M   (60 * SCP_SIZE_1M)
#define SCP_SIZE_80M   (80 * SCP_SIZE_1M)
#define SCP_SIZE_240M  (240 * SCP_SIZE_1M)
#define SCP_SIZE_256M  (256 * SCP_SIZE_1M)
#define SCP_SIZE_360M  (360 * SCP_SIZE_1M)
#define SCP_SIZE_1000M (1000 * SCP_SIZE_1M)

#define SCP_OFFSET_AP                                                                              \
	0x50000000 /* base on v03/dma_api.c {.ap_addr    = 0x60000000, .scp_addr       = */
		   /* 0x60000000,}, */
#define SCP_NON_CACHED_BASE 0xC1000000UL /* total:240M   0xC1000000~0xD0000000 */
#define SCP_NON_CACHED_SIZE SCP_SIZE_240M
#define SCP_CAR_LOGO_BASE                                                                          \
	(0x66A00000UL - SCP_OFFSET_AP) /* (0x62000000UL + SCP_SIZE_80M - SCP_SIZE_6M) */
#define SCP_CAR_LOGO_SIZE SCP_SIZE_6M

#endif /* ZEPHYR_SOC_MEDIATEK_MT81XX_SCP_MT8196_SCP_INC_TINYSYS_REG_H_ */
