/*
 * SPDX-FileCopyrightText: Copyright (c) 2026 Mediatek
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*
 * HACK: This snippet is included inside the template's 'rom_start' section.
 * We close it early here and open a dummy section with
 * AT(CONFIG_MEDIATEK_SCP_PROGRAM_LOAD_ADDRESS). This rebases the linker's
 * Load Memory Address (LMA) counter so every subsequent section inherits an
 * LMA starting from CONFIG_MEDIATEK_SCP_PROGRAM_LOAD_ADDRESS (needed by the
 * host loader), while keeping VMA starting at 0x0.
 * The closing brace is provided by the parent linker template.
 */
    } GROUP_LINK_IN(ROMABLE_REGION)
    SECTION_PROLOGUE(vector,,) AT(CONFIG_MEDIATEK_SCP_PROGRAM_LOAD_ADDRESS)
    {
        . = ALIGN(4);
        KEEP(*(.vectors.*))
