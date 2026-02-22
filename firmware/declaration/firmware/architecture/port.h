// SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
// SPDX-License-Identifier: AGPL-3.0-only

#ifndef FIRMWARE_ARCHITECTURE_ARMV8M_PORT_H
#define FIRMWARE_ARCHITECTURE_ARMV8M_PORT_H

#include <firmware/kernel/type/task.h>

void architecture_start_scheduler(kernel_task_t tasks[], uint8_t tasks_number);

#endif
