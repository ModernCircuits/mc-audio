# SPDX-License-Identifier: BSL-1.0

project(mc-audio-example)

add_executable(mc-audio-example-note note.cpp)
add_test(NAME example-note COMMAND mc-audio-example-note)
target_link_libraries(mc-audio-example-note mc::audio)
