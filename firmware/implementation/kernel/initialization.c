// SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
// SPDX-License-Identifier: AGPL-3.0-only

#include <firmware/kernel/initialization.h>

#include <stdint.h>

extern uint8_t data_start[];
extern uint8_t data_end[];
extern uint8_t data_load[];
extern uint8_t bss_start[];
extern uint8_t bss_end[];

[[noreturn]]
void kernel_initialize(void) {
    for (uint8_t *source = data_load, *destination = data_start; destination < data_end;) {
        *destination++ = *source++;
    }
    for (uint8_t *destination = bss_start; destination < bss_end;) {
        *destination++ = 0;
    }
    while (true) {
    }
}
