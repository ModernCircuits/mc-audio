// SPDX-License-Identifier: BSL-1.0
#pragma once

namespace mc {
namespace dsp {

template<typename T>
constexpr StereoWidth<T>::StereoWidth(T initialWidth) noexcept
    : _width{initialWidth}
    , _coeff{initialWidth * T(0.5)}
{}

template<typename T>
constexpr auto StereoWidth<T>::width(T newWidth) noexcept -> void
{
    _width = newWidth;
    _coeff = newWidth * T(0.5);
}

template<typename T>
[[nodiscard]] constexpr auto StereoWidth<T>::width() const noexcept -> T
{
    return _width;
}

template<typename T>
[[nodiscard]] constexpr auto StereoWidth<T>::operator()(StereoFrame<T> in) -> StereoFrame<T>
{
    auto const mid  = (in.left + in.right) * 0.5F;
    auto const side = (in.right - in.left) * _coeff;

    return {
        mid - side,
        mid + side,
    };
}
}  // namespace dsp
}  // namespace mc
