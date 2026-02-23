# SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
# SPDX-License-Identifier: AGPL-3.0-only

add_library(service STATIC gpio.c uart.c)

target_link_libraries(service PRIVATE compile_options include_directories driver)
