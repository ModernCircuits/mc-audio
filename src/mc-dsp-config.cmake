# SPDX-License-Identifier: BSL-1.0

include(CMakeFindDependencyMacro)

find_dependency(mc-core REQUIRED)

include("${CMAKE_CURRENT_LIST_DIR}/mc-dsp-targets.cmake")
