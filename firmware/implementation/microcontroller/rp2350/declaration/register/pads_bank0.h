// SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
// SPDX-License-Identifier: AGPL-3.0-only

#ifndef FIRMWARE_MICROCONTROLLER_RP2350_REGISTER_PADS_BANK0_H
#define FIRMWARE_MICROCONTROLLER_RP2350_REGISTER_PADS_BANK0_H

#include <stdint.h>

#define PADS_BANK0_GPIO_ISO_BIT (1u << 8)

typedef struct {
    uint32_t VOLTAGE_SELECT;
    uint32_t GPIO[48];
} pads_bank0_t;

#define PADS_BANK0 ((volatile pads_bank0_t *)0x40038000)

#endif
