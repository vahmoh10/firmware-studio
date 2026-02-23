// SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
// SPDX-License-Identifier: AGPL-3.0-only

#ifndef FIRMWARE_DRIVER_PERIPHERAL_GPIO_H
#define FIRMWARE_DRIVER_PERIPHERAL_GPIO_H

#include <stdint.h>

typedef uint8_t gpio_pin_t;

typedef enum : uint8_t {
    GPIO_DIRECTION_INPUT,
    GPIO_DIRECTION_OUTPUT,
} gpio_direction_t;

typedef enum : uint8_t {
    GPIO_LEVEL_LOW,
    GPIO_LEVEL_HIGH,
} gpio_level_t;

void gpio_initialize(gpio_pin_t pin);
void gpio_set_direction(gpio_pin_t pin, gpio_direction_t direction);
void gpio_set_level(gpio_pin_t pin, gpio_level_t level);

#endif
