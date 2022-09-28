// SPDX-License-Identifier: BSL-1.0
#pragma once

#include <mc/core/config.hpp>

#include <mc/audio/stereo/mid_side_frame.hpp>
#include <mc/audio/stereo/stereo_frame.hpp>

namespace mc {
template<typename SampleType>
[[nodiscard]] constexpr auto toMidSide(StereoFrame<SampleType> frame) noexcept
    -> MidSideFrame<SampleType>
{
    auto const gain = static_cast<SampleType>(0.707946);  // -3dB
    return {
        (frame.left + frame.right) * gain,
        (frame.left - frame.right) * gain,
    };
}
}  // namespace mc
