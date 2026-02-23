// SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
// SPDX-License-Identifier: AGPL-3.0-only

#include <firmware/service/uart.h>

#include <stdint.h>

#include <firmware/driver/peripheral/uart.h>

void uart_run(void) {
    uart_initialize();
    while (true) {
        uart_write("Hello World!\r\n");
        for (volatile uint32_t i = 0; i < 100000; i++) {
        }
    }
}
