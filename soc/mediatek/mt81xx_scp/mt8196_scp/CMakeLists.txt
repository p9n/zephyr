# SPDX-FileCopyrightText: Copyright (c) 2026 Mediatek
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(./inc)

set(SOC_LINKER_SCRIPT ${ZEPHYR_BASE}/include/zephyr/arch/riscv/common/linker.ld CACHE INTERNAL "")

zephyr_linker_sources(ROM_START SORT_KEY 0x00_rom_start rom_start.ld)
zephyr_linker_sources(DATA_SECTIONS ipi_buffer.ld)

