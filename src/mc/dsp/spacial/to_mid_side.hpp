// SPDX-License-Identifier: BSL-1.0
#pragma once

#include <mc/core/config.hpp>

#include <mc/dsp/spacial/mid_side_frame.hpp>
#include <mc/dsp/spacial/stereo_frame.hpp>

namespace mc {
namespace dsp {
template<typename SampleType>
MC_NODISCARD constexpr auto toMidSide(StereoFrame<SampleType> frame) noexcept
    -> MidSideFrame<SampleType>
{
    auto const gain = static_cast<SampleType>(0.707946);  // -3dB
    return {
        (frame.left + frame.right) * gain,
        (frame.left - frame.right) * gain,
    };
}
}  // namespace dsp
}  // namespace mc