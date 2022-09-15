// SPDX-License-Identifier: BSL-1.0
#pragma once

#include <mc/core/config.hpp>

#include <mc/dsp/spacial/mid_side_frame.hpp>
#include <mc/dsp/spacial/stereo_frame.hpp>

namespace mc {
namespace dsp {
template<typename SampleType>
[[nodiscard]] constexpr auto toStereo(MidSideFrame<SampleType> frame) noexcept
    -> StereoFrame<SampleType>
{
    auto const gain = static_cast<SampleType>(0.707946);  // -3dB
    return {
        (frame.mid + frame.side) * gain,
        (frame.mid - frame.side) * gain,
    };
}
}  // namespace dsp
}  // namespace mc
