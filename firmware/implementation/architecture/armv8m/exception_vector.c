// SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
// SPDX-License-Identifier: AGPL-3.0-only

#include <exception_vector.h>

#include <firmware/kernel/initialization.h>

void Reset_Handler(void) {
    kernel_initialize();
}
