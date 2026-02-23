// SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
// SPDX-License-Identifier: AGPL-3.0-only

#ifndef FIRMWARE_MICROCONTROLLER_RP2350_REGISTER_RESETS_H
#define FIRMWARE_MICROCONTROLLER_RP2350_REGISTER_RESETS_H

#include <stdint.h>

#define RESETS_RESET_UART0_POSITION 26

typedef struct {
    uint32_t RESET;
} resets_t;

#define RESETS ((volatile resets_t *)0x40020000)

#endif
