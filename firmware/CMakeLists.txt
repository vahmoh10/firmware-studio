# SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
# SPDX-License-Identifier: AGPL-3.0-only

cmake_minimum_required(VERSION 3.21)

project(firmware LANGUAGES C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

include(configuration/interface/compile_options.cmake)
include(configuration/interface/include_directories.cmake)
include(configuration/interface/link_options.cmake)

option(BUILD_VERIFICATION "Build Verification" OFF)

add_subdirectory(implementation)

if(BUILD_VERIFICATION)
    add_subdirectory(verification)
endif()
