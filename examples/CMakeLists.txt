# SPDX-License-Identifier: BSL-1.0

project(mc-dsp-example)

add_executable(mc-dsp-example-note note.cpp)
add_test(NAME example-note COMMAND mc-dsp-example-note)
target_link_libraries(mc-dsp-example-note mc::dsp)
