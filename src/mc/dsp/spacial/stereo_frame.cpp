// SPDX-License-Identifier: BSL-1.0
#pragma once

#include <mc/core/config.hpp>

namespace mc::dsp {

template<typename T>
constexpr auto operator+(StereoFrame<T> lhs, StereoFrame<T> rhs) noexcept -> StereoFrame<T>
{
    return {
        lhs.left + rhs.left,
        lhs.right + rhs.right,
    };
}

template<typename T>
constexpr auto operator-(StereoFrame<T> lhs, StereoFrame<T> rhs) noexcept -> StereoFrame<T>
{
    return {
        lhs.left - rhs.left,
        lhs.right - rhs.right,
    };
}

template<typename T>
constexpr auto operator*(StereoFrame<T> lhs, StereoFrame<T> rhs) noexcept -> StereoFrame<T>
{
    return {
        lhs.left * rhs.left,
        lhs.right * rhs.right,
    };
}

template<typename T>
constexpr auto operator/(StereoFrame<T> lhs, StereoFrame<T> rhs) noexcept -> StereoFrame<T>
{
    return {
        lhs.left / rhs.left,
        lhs.right / rhs.right,
    };
}

template<typename T>
constexpr auto operator+(StereoFrame<T> lhs, T rhs) noexcept -> StereoFrame<T>
{
    return {
        lhs.left + rhs,
        lhs.right + rhs,
    };
}

template<typename T>
constexpr auto operator-(StereoFrame<T> lhs, T rhs) noexcept -> StereoFrame<T>
{
    return {
        lhs.left - rhs,
        lhs.right - rhs,
    };
}

template<typename T>
constexpr auto operator*(StereoFrame<T> lhs, T rhs) noexcept -> StereoFrame<T>
{
    return {
        lhs.left * rhs,
        lhs.right * rhs,
    };
}

template<typename T>
constexpr auto operator/(StereoFrame<T> lhs, T rhs) noexcept -> StereoFrame<T>
{
    return {
        lhs.left / rhs,
        lhs.right / rhs,
    };
}

template<typename T>
constexpr auto operator+=(StereoFrame<T>& lhs, StereoFrame<T> rhs) noexcept
    -> StereoFrame<T>&
{
    lhs = lhs + rhs;
    return lhs;
}

template<typename T>
constexpr auto operator-=(StereoFrame<T>& lhs, StereoFrame<T> rhs) noexcept
    -> StereoFrame<T>&
{
    lhs = lhs - rhs;
    return lhs;
}

template<typename T>
constexpr auto operator*=(StereoFrame<T>& lhs, StereoFrame<T> rhs) noexcept
    -> StereoFrame<T>&
{
    lhs = lhs * rhs;
    return lhs;
}

template<typename T>
constexpr auto operator/=(StereoFrame<T>& lhs, StereoFrame<T> rhs) noexcept
    -> StereoFrame<T>&
{
    lhs = lhs / rhs;
    return lhs;
}

template<typename T>
constexpr auto operator+=(StereoFrame<T>& lhs, T rhs) noexcept -> StereoFrame<T>&
{
    lhs = lhs + rhs;
    return lhs;
}

template<typename T>
constexpr auto operator-=(StereoFrame<T>& lhs, T rhs) noexcept -> StereoFrame<T>&
{
    lhs = lhs - rhs;
    return lhs;
}

template<typename T>
constexpr auto operator*=(StereoFrame<T>& lhs, T rhs) noexcept -> StereoFrame<T>&
{
    lhs = lhs * rhs;
    return lhs;
}

template<typename T>
constexpr auto operator/=(StereoFrame<T>& lhs, T rhs) noexcept -> StereoFrame<T>&
{
    lhs = lhs / rhs;
    return lhs;
}

}  // namespace mc::dsp
