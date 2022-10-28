// SPDX-License-Identifier: BSL-1.0
#pragma once

#include <mc/audio/stereo/mid_side_frame.hpp>
#include <mc/audio/stereo/stereo_frame.hpp>

namespace mc {

template<typename T>
[[nodiscard]] constexpr auto toMidSide(StereoFrame<T> frame) noexcept -> MidSideFrame<T>;

}  // namespace mc

#include "to_mid_side.ipp"
