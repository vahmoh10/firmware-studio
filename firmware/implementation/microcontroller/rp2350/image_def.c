// SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
// SPDX-License-Identifier: AGPL-3.0-only

#include <stdint.h>

#include <firmware/compiler.h>

FIRMWARE_SECTION(".image_def")
FIRMWARE_USED
const uint32_t image_def[] = {
    0xFFFFDED3,
    0x10210142,
    0x000001ff,
    0x00000000,
    0xab123579,
};
