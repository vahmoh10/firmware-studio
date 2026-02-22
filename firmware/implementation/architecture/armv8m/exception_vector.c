// SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
// SPDX-License-Identifier: AGPL-3.0-only

#include <exception_vector.h>

#include <firmware/kernel/initialization.h>

#include <register/scb.h>

void Reset_Handler(void) {
    kernel_initialize();
}

FIRMWARE_NAKED
void PendSV_Handler(void) {
    __asm volatile(
        "mrs r0, psp \n"
        "stmdb r0!, {r4-r11, lr} \n"
        "bl kernel_save_current_task_stack \n"
        "bl kernel_restore_next_task_stack \n"
        "ldmia r0!, {r4-r11, lr} \n"
        "msr psp, r0 \n"
        "bx lr \n"
    );
}

void SysTick_Handler(void) {
    SCB->ICSR = 1 << SCB_ICSR_PENDSVSET_POSITION;
}

[[noreturn]]
void Default_Handler(void) {
    while (true) {
    }
}
