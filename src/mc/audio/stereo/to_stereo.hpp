// SPDX-License-Identifier: BSL-1.0
#pragma once

#include <mc/audio/stereo/mid_side_frame.hpp>
#include <mc/audio/stereo/stereo_frame.hpp>

namespace mc {

template<typename T>
[[nodiscard]] constexpr auto toStereo(MidSideFrame<T> frame) noexcept -> StereoFrame<T>;

}  // namespace mc

#include "to_stereo.impl.hpp"
