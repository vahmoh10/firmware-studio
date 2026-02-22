// SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
// SPDX-License-Identifier: AGPL-3.0-only

#ifndef FIRMWARE_KERNEL_TYPE_TASK_H
#define FIRMWARE_KERNEL_TYPE_TASK_H

#include <stddef.h>
#include <stdint.h>

typedef void (*task_entry_t)(void);

typedef struct {
    task_entry_t entry;
    uintptr_t *stack_base;
    uintptr_t *stack_pointer;
    size_t stack_size;
} kernel_task_t;

#endif
