# SPDX-License-Identifier: BSL-1.0

cmake_minimum_required(VERSION 3.21)
project(mc-dsp VERSION 0.3.0)

find_package(mc-core REQUIRED)

add_library(mc-dsp INTERFACE)
add_library(mc::dsp ALIAS mc-dsp)

set_target_properties(mc-dsp
    PROPERTIES
        CXX_VISIBILITY_PRESET hidden
        VISIBILITY_INLINES_HIDDEN YES
        VERSION "${PROJECT_VERSION}"
        SOVERSION "${PROJECT_VERSION_MAJOR}"
        EXPORT_NAME dsp
)

target_include_directories(mc-dsp
    INTERFACE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)


target_link_libraries(mc-dsp
    INTERFACE
        mc-core::mc-core
)

if(EMSCRIPTEN)
    target_compile_options(mc-dsp
        INTERFACE
            "SHELL:-s USE_BOOST_HEADERS=1"
            "SHELL:-s DISABLE_EXCEPTION_CATCHING=0"
    )
    target_link_options(mc-dsp
        INTERFACE
            "SHELL:-s USE_BOOST_HEADERS=1"
            "SHELL:-s DISABLE_EXCEPTION_CATCHING=0"
    )
endif()

install(
    TARGETS
        "mc-dsp"
    EXPORT
        "mc-dsp-targets"
    LIBRARY DESTINATION
        "${CMAKE_INSTALL_LIBDIR}"
    ARCHIVE DESTINATION
        "${CMAKE_INSTALL_LIBDIR}"
    RUNTIME DESTINATION
        "${CMAKE_INSTALL_BINDIR}"
    INCLUDES DESTINATION
        "${CMAKE_INSTALL_INCLUDEDIR}"
)


include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    mc-dsp-config-version.cmake
    VERSION
        ${PROJECT_VERSION}
    COMPATIBILITY
        AnyNewerVersion
)

configure_file(mc-dsp-config.cmake.in mc-dsp-config.cmake @ONLY)
install(
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/mc-dsp-config.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/mc-dsp-config-version.cmake"
    DESTINATION
        "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
)

install(
    EXPORT
        mc-dsp-targets
    NAMESPACE
        mc::
    DESTINATION
        "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
)
