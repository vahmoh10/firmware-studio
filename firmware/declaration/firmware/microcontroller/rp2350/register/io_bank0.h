// SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
// SPDX-License-Identifier: AGPL-3.0-only

#ifndef FIRMWARE_MICROCONTROLLER_RP2350_REGISTER_IO_BANK0_H
#define FIRMWARE_MICROCONTROLLER_RP2350_REGISTER_IO_BANK0_H

#include <stdint.h>

typedef enum : uint8_t {
    IO_BANK0_GPIO_CTRL_FUNCSEL_UART = 0x02,
    IO_BANK0_GPIO_CTRL_FUNCSEL_SIO = 0x05,
} io_bank0_gpio_ctrl_funcsel_t;

typedef struct {
    uint32_t STATUS;
    uint32_t CTRL;
} io_bank0_gpio_t;

typedef struct {
    io_bank0_gpio_t GPIO[48];
} io_bank0_t;

#define IO_BANK0 ((volatile io_bank0_t *)0x40028000)

#endif
