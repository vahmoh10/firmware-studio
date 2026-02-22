// SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
// SPDX-License-Identifier: AGPL-3.0-only

#include <firmware/kernel/scheduler.h>

#include <firmware/architecture/port.h>

#include <firmware/kernel/type/task.h>

[[noreturn]]
void run_idle_task(void) {
    while (true) {
    }
}

static uint8_t idle_task_stack[1024];

kernel_task_t tasks[] = {
    {
        .entry = run_idle_task,
        .stack_base = (uintptr_t *)idle_task_stack,
        .stack_size = sizeof(idle_task_stack),
    },
};

constexpr uint8_t TASK_NUMBER = sizeof(tasks) / sizeof(tasks[0]);

uint8_t current_task = 0;

void kernel_start_scheduler(void) {
    architecture_start_scheduler(tasks, TASK_NUMBER);
}

void kernel_save_current_task_stack(uintptr_t *stack_pointer) {
    tasks[current_task].stack_pointer = stack_pointer;
}

uintptr_t *kernel_restore_next_task_stack(void) {
    current_task = (current_task + 1) % TASK_NUMBER;
    return tasks[current_task].stack_pointer;
}
