# SPDX-License-Identifier: BSL-1.0

cmake_minimum_required(VERSION 3.21)
project(mc-audio-dev VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(CTest)
enable_testing()

add_subdirectory(src)
add_subdirectory(examples)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake)
include(code_coverage)
include(compiler_options)
include(compiler_warnings)

find_package(Catch2 REQUIRED)
include(Catch)

add_executable(mc-audio-tests)
catch_discover_tests(mc-audio-tests)
target_link_libraries(mc-audio-tests
    PRIVATE
        Catch2::Catch2WithMain
        mc::audio
        mc::coverage
        mc::compiler_options
        mc::compiler_warnings
)

target_sources(mc-audio-tests
    PRIVATE
        "src/mc/audio/music/chord/is_major.test.cpp"
        "src/mc/audio/music/chord/is_minor.test.cpp"
        "src/mc/audio/music/keyboard/is_black_key.test.cpp"
        "src/mc/audio/music/keyboard/is_white_key.test.cpp"
        "src/mc/audio/music/note/note.test.cpp"
        "src/mc/audio/music/note/semitones.test.cpp"
        "src/mc/audio/music/note/to_hertz.test.cpp"
        "src/mc/audio/music/note/to_nearest_note.test.cpp"
        "src/mc/audio/stereo/stereo_frame.test.cpp"
        "src/mc/audio/units/decibel.test.cpp"
        "src/mc/audio/units/frequency.test.cpp"
)
