/*
 * SPDX-FileCopyrightText: Copyright (c) 2026 Mediatek
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*
 * HACK: This snippet is included inside the template's 'rom_start' section.
 * We close it early here and open a custom 'vector' section to force the
 * Load Address (LMA) to CONFIG_MEDIATEK_SCP_PROGRAM_LOAD_ADDRESS (needed
 * for host loader), while keeping VMA at 0x0.
 * The closing brace for 'vector' is provided by the parent template.
 */
    } GROUP_LINK_IN(ROMABLE_REGION)
    SECTION_PROLOGUE(vector,,) AT(CONFIG_MEDIATEK_SCP_PROGRAM_LOAD_ADDRESS)
    {
        . = ALIGN(4);
        KEEP(*(.vectors.*))
