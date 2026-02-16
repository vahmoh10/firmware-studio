# SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
# SPDX-License-Identifier: AGPL-3.0-only

add_library(kernel STATIC initialization.c)

target_include_directories(kernel PRIVATE declaration)

target_link_libraries(kernel PRIVATE compile_options include_directories)
