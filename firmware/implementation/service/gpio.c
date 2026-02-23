// SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
// SPDX-License-Identifier: AGPL-3.0-only

#include <firmware/service/gpio.h>

#include <firmware/driver/peripheral/gpio.h>

void gpio_run(void) {
    gpio_initialize(17);
    gpio_set_direction(17, GPIO_DIRECTION_OUTPUT);
    while (true) {
        gpio_set_level(17, GPIO_LEVEL_HIGH);
        for (volatile uint32_t i = 0; i < 100000; i++) {
        }
        gpio_set_level(17, GPIO_LEVEL_LOW);
        for (volatile uint32_t i = 0; i < 100000; i++) {
        }
    }
}
