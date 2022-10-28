// SPDX-License-Identifier: BSL-1.0
#pragma once

namespace mc {

template<typename T>
constexpr auto toMidSide(StereoFrame<T> frame) noexcept -> MidSideFrame<T>
{
    auto const gain = static_cast<T>(0.707946);  // -3dB
    return {
        (frame.left + frame.right) * gain,
        (frame.left - frame.right) * gain,
    };
}

}  // namespace mc
