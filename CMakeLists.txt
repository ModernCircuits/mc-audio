# SPDX-License-Identifier: BSL-1.0

cmake_minimum_required(VERSION 3.21)
project(mc-dsp-dev VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(CTest)
enable_testing()

add_subdirectory(src)
add_subdirectory(examples)

find_package(Catch2 REQUIRED)
include(Catch)

add_executable(mc-dsp-tests)
catch_discover_tests(mc-dsp-tests)
target_link_libraries(mc-dsp-tests PRIVATE mc::dsp Catch2::Catch2WithMain)

target_sources(mc-dsp-tests
    PRIVATE
        "src/mc/dsp/music/keyboard.test.cpp"
        "src/mc/dsp/music/to_hertz.test.cpp"
        "src/mc/dsp/music/to_nearest_note.test.cpp"
)
