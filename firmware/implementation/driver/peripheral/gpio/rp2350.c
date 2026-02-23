// SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
// SPDX-License-Identifier: AGPL-3.0-only

#include <firmware/driver/peripheral/gpio.h>

#include <firmware/microcontroller/rp2350/register/io_bank0.h>
#include <firmware/microcontroller/rp2350/register/pads_bank0.h>
#include <firmware/microcontroller/rp2350/register/sio.h>

void gpio_initialize(gpio_pin_t pin) {
    PADS_BANK0->GPIO[pin] &= ~(1u << PADS_BANK0_GPIO_ISO_POSITION);
    IO_BANK0->GPIO[pin].CTRL = IO_BANK0_GPIO_CTRL_FUNCSEL_SIO;
}

void gpio_set_direction(gpio_pin_t pin, gpio_direction_t direction) {
    if (direction == GPIO_DIRECTION_INPUT) {
        SIO->GPIO_OUT_CLR = 1u << pin;
    } else {
        SIO->GPIO_OUT_SET = 1u << pin;
    }
}

void gpio_set_level(gpio_pin_t pin, gpio_level_t level) {
    if (level == GPIO_LEVEL_LOW) {
        SIO->GPIO_OE_CLR = 1u << pin;
    } else {
        SIO->GPIO_OE_SET = 1u << pin;
    }
}
