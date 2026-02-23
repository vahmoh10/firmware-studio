# SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
# SPDX-License-Identifier: AGPL-3.0-only

add_library(driver STATIC peripheral/gpio/${MICROCONTROLLER}.c peripheral/uart/${MICROCONTROLLER}.c)

target_link_libraries(driver PRIVATE compile_options include_directories)
