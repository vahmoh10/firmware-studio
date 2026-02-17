// SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
// SPDX-License-Identifier: AGPL-3.0-only

#include <stdint.h>

#include <firmware/compiler.h>

#include <exception_vector.h>

extern const uintptr_t stack_top;

FIRMWARE_SECTION(".vector_table")
FIRMWARE_USED
const uintptr_t vector_table[] = {
    (uintptr_t)&stack_top,
    (uintptr_t)Reset_Handler,
};
