// SPDX-License-Identifier: BSL-1.0
#pragma once

namespace mc {

template<typename T>
constexpr auto toStereo(MidSideFrame<T> frame) noexcept -> StereoFrame<T>
{
    auto const gain = static_cast<T>(0.707946);  // -3dB
    return {
        (frame.mid + frame.side) * gain,
        (frame.mid - frame.side) * gain,
    };
}

}  // namespace mc
