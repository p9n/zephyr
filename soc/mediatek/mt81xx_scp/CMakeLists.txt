# SPDX-FileCopyrightText: Copyright (c) 2026 Mediatek
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(.)
zephyr_sources(soc.c)

add_subdirectory(mt8196_scp)
