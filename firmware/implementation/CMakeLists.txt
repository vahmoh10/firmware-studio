# SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
# SPDX-License-Identifier: AGPL-3.0-only

add_executable(firmware)

target_link_libraries(firmware PRIVATE link_options)

set_target_properties(firmware PROPERTIES SUFFIX ".elf")
