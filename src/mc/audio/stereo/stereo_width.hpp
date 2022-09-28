// SPDX-License-Identifier: BSL-1.0
#pragma once

#include <mc/core/config.hpp>

#include <mc/audio/stereo/stereo_frame.hpp>

namespace mc {
template<typename T>
struct StereoWidth
{
    using SampleType = T;

    constexpr StereoWidth() noexcept = default;
    explicit constexpr StereoWidth(T initialWidth) noexcept;

    constexpr auto width(T newWidth) noexcept -> void;
    [[nodiscard]] constexpr auto width() const noexcept -> T;

    [[nodiscard]] constexpr auto operator()(StereoFrame<T> in) -> StereoFrame<T>;

private:
    T _width{1.0};
    T _coeff{_width * T(0.5)};
};
}  // namespace mc

#include "stereo_width.cpp"  // NOLINT
