# SPDX-License-Identifier: BSL-1.0

include(CMakeFindDependencyMacro)

find_dependency(mc-core REQUIRED)
find_dependency(drflac REQUIRED)
find_dependency(drmp3 REQUIRED)
find_dependency(drwav REQUIRED)

include("${CMAKE_CURRENT_LIST_DIR}/mc-audio-targets.cmake")
