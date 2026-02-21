// SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
// SPDX-License-Identifier: AGPL-3.0-only

#ifndef FIRMWARE_MICROCONTROLLER_RP2350_REGISTER_XOSC_H
#define FIRMWARE_MICROCONTROLLER_RP2350_REGISTER_XOSC_H

#include <stdint.h>

#define XOSC_CTRL_ENABLE_POSITION 12

typedef enum : uint16_t {
    XOSC_CTRL_ENABLE_DISABLE = 0xD1Eu,
    XOSC_CTRL_ENABLE_ENABLE = 0xFABu,
} xoxc_ctrl_enable_t;

typedef struct {
    uint32_t CTRL;
} xosc_t;

#define XOSC ((volatile xosc_t *)0x40048000)

#endif
