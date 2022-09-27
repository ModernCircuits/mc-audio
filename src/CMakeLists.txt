# SPDX-License-Identifier: BSL-1.0

cmake_minimum_required(VERSION 3.21)
project(mc-audio VERSION 0.9.0)

find_package(mc-core REQUIRED)

add_library(mc-audio INTERFACE)
add_library(mc::audio ALIAS mc-audio)

target_include_directories(mc-audio
    INTERFACE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_link_libraries(mc-audio
    INTERFACE
        mc::core
)

if(EMSCRIPTEN)
    target_compile_options(mc-audio
        INTERFACE
            "SHELL:-s USE_BOOST_HEADERS=1"
            "SHELL:-s DISABLE_EXCEPTION_CATCHING=0"
    )
    target_link_options(mc-audio
        INTERFACE
            "SHELL:-s USE_BOOST_HEADERS=1"
            "SHELL:-s DISABLE_EXCEPTION_CATCHING=0"
    )
endif()

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set_target_properties(mc-audio PROPERTIES
    CXX_VISIBILITY_PRESET
        hidden
    VISIBILITY_INLINES_HIDDEN
        YES
    VERSION
        ${PROJECT_VERSION}
    SOVERSION
        ${PROJECT_VERSION_MAJOR}
    EXPORT_NAME
        audio
)

install(
    TARGETS
        mc-audio
    EXPORT
        mc-audio-targets
)

export(
    EXPORT
        mc-audio-targets
    NAMESPACE
        mc::
)

configure_file("mc-audio-config.cmake" "." COPYONLY)
write_basic_package_version_file(mc-audio-config-version.cmake COMPATIBILITY SameMajorVersion)

install(
    EXPORT
        mc-audio-targets
    DESTINATION
        ${CMAKE_INSTALL_LIBDIR}/cmake/mc-audio
    NAMESPACE
        mc::
)

install(
    FILES
        mc-audio-config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/mc-audio-config-version.cmake
    DESTINATION
        ${CMAKE_INSTALL_LIBDIR}/cmake/mc-audio
)
