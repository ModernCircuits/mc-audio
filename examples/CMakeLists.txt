# SPDX-License-Identifier: BSL-1.0

project(mc-dsp-example)

add_executable(mc-dsp-example-midi-notes midi-notes.cpp)
add_test(NAME example-midi-notes COMMAND mc-dsp-example-midi-notes)
target_link_libraries(mc-dsp-example-midi-notes mc::dsp)
