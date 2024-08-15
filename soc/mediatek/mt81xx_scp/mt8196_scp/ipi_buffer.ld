/*
 * SPDX-FileCopyrightText: Copyright (c) 2026 Mediatek
 *
 * SPDX-License-Identifier: Apache-2.0
 */

SECTION_DATA_PROLOGUE(.ipi_buffer,(NOLOAD),)
{
    . = ALIGN(4);
    KEEP(*(.ipi_buffer))
} GROUP_DATA_LINK_IN(RAMABLE_REGION, RAMABLE_REGION)
