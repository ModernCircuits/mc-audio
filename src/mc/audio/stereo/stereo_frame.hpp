// SPDX-License-Identifier: BSL-1.0
#pragma once

namespace mc {
template<typename T>
struct StereoFrame
{
    using SampleType = T;

    T left{};
    T right{};
};

template<typename T>
[[nodiscard]] constexpr auto operator+(StereoFrame<T> lhs, StereoFrame<T> rhs) noexcept
    -> StereoFrame<T>;

template<typename T>
[[nodiscard]] constexpr auto operator-(StereoFrame<T> lhs, StereoFrame<T> rhs) noexcept
    -> StereoFrame<T>;

template<typename T>
[[nodiscard]] constexpr auto operator*(StereoFrame<T> lhs, StereoFrame<T> rhs) noexcept
    -> StereoFrame<T>;

template<typename T>
[[nodiscard]] constexpr auto operator/(StereoFrame<T> lhs, StereoFrame<T> rhs) noexcept
    -> StereoFrame<T>;

template<typename T>
[[nodiscard]] constexpr auto operator+(StereoFrame<T> lhs, T rhs) noexcept
    -> StereoFrame<T>;

template<typename T>
[[nodiscard]] constexpr auto operator-(StereoFrame<T> lhs, T rhs) noexcept
    -> StereoFrame<T>;

template<typename T>
[[nodiscard]] constexpr auto operator*(StereoFrame<T> lhs, T rhs) noexcept
    -> StereoFrame<T>;

template<typename T>
[[nodiscard]] constexpr auto operator/(StereoFrame<T> lhs, T rhs) noexcept
    -> StereoFrame<T>;

template<typename T>
constexpr auto operator+=(StereoFrame<T>& lhs, StereoFrame<T> rhs) noexcept
    -> StereoFrame<T>&;

template<typename T>
constexpr auto operator-=(StereoFrame<T>& lhs, StereoFrame<T> rhs) noexcept
    -> StereoFrame<T>&;

template<typename T>
constexpr auto operator*=(StereoFrame<T>& lhs, StereoFrame<T> rhs) noexcept
    -> StereoFrame<T>&;

template<typename T>
constexpr auto operator/=(StereoFrame<T>& lhs, StereoFrame<T> rhs) noexcept
    -> StereoFrame<T>&;

template<typename T>
constexpr auto operator+=(StereoFrame<T>& lhs, T rhs) noexcept -> StereoFrame<T>&;

template<typename T>
constexpr auto operator-=(StereoFrame<T>& lhs, T rhs) noexcept -> StereoFrame<T>&;

template<typename T>
constexpr auto operator*=(StereoFrame<T>& lhs, T rhs) noexcept -> StereoFrame<T>&;

template<typename T>
constexpr auto operator/=(StereoFrame<T>& lhs, T rhs) noexcept -> StereoFrame<T>&;

}  // namespace mc

#include "stereo_frame.impl.hpp"
