cmake_minimum_required(VERSION 3.21)
project(mc-dsp VERSION 0.1.0)

add_library(mc-dsp INTERFACE)
add_library(mc::dsp ALIAS mc-dsp)
target_include_directories(mc-dsp INTERFACE ${PROJECT_SOURCE_DIR})