// SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
// SPDX-License-Identifier: AGPL-3.0-only

#include <firmware/architecture/port.h>

#include <register/systick.h>

void architecture_start_scheduler(kernel_task_t tasks[], uint8_t tasks_number) {
    SYSTICK->SYST_RVR = 1000;
    SYSTICK->SYST_CVR = 0;
    SYSTICK->SYST_CSR = (1u << SYSTICK_SYST_CSR_ENABLE_POSITION) | (1u << SYSTICK_SYST_CSR_TICKINT_POSITION) | (1u << SYSTICK_SYST_CSR_CLKSOURCE_POSITION);
    for (uint8_t i = 0; i < tasks_number; i++) {
        uintptr_t *stack_pointer = (uintptr_t *)((uint8_t *)tasks[i].stack_base + tasks[i].stack_size);
        *(--stack_pointer) = 0x01000000;
        *(--stack_pointer) = (uintptr_t)tasks[i].entry;
        for (uint8_t j = 0; j < 6; j++) {
            *(--stack_pointer) = 0;
        }
        *(--stack_pointer) = 0xFFFFFFFD;
        for (uint8_t j = 0; j < 8; j++) {
            *(--stack_pointer) = 0;
        }
        tasks[i].stack_pointer = stack_pointer;
    }
    __asm volatile(
        "msr psp, %0 \n"
        "mov r0, #2 \n"
        "msr control, r0 \n"
        "bx %1 \n"
        :: "r" (tasks[0].stack_base + tasks[0].stack_size), "r" (tasks[0].entry)
        : "r0"
    );
}
