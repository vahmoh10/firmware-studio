// SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
// SPDX-License-Identifier: AGPL-3.0-only

#include <firmware/kernel/scheduler.h>

#include <firmware/architecture/port.h>
#include <firmware/kernel/type/task.h>
#include <firmware/service/gpio.h>
#include <firmware/service/uart.h>

static uint8_t gpio_stack[1024];
static uint8_t uart_stack[1024];

kernel_task_t tasks[] = {
    {
        .entry = gpio_run,
        .stack_base = (uintptr_t *)gpio_stack,
        .stack_size = sizeof(gpio_stack),
    },
    {
        .entry = uart_run,
        .stack_base = (uintptr_t *)uart_stack,
        .stack_size = sizeof(uart_stack),
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
