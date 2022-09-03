// SPDX-License-Identifier: BSL-1.0
#pragma once

#include <mc/core/config.hpp>

namespace mc {
namespace dsp {
template<typename T>
struct StereoFrame
{
    using SampleType = T;

    T left{};
    T right{};
};

template<typename T>
MC_NODISCARD constexpr auto operator+(StereoFrame<T> lhs, StereoFrame<T> rhs) noexcept
    -> StereoFrame<T>;

template<typename T>
MC_NODISCARD constexpr auto operator-(StereoFrame<T> lhs, StereoFrame<T> rhs) noexcept
    -> StereoFrame<T>;

template<typename T>
MC_NODISCARD constexpr auto operator*(StereoFrame<T> lhs, StereoFrame<T> rhs) noexcept
    -> StereoFrame<T>;

template<typename T>
MC_NODISCARD constexpr auto operator/(StereoFrame<T> lhs, StereoFrame<T> rhs) noexcept
    -> StereoFrame<T>;

template<typename T>
MC_NODISCARD constexpr auto operator+(StereoFrame<T> lhs, T rhs) noexcept -> StereoFrame<T>;

template<typename T>
MC_NODISCARD constexpr auto operator-(StereoFrame<T> lhs, T rhs) noexcept -> StereoFrame<T>;

template<typename T>
MC_NODISCARD constexpr auto operator*(StereoFrame<T> lhs, T rhs) noexcept -> StereoFrame<T>;

template<typename T>
MC_NODISCARD constexpr auto operator/(StereoFrame<T> lhs, T rhs) noexcept -> StereoFrame<T>;

template<typename T>
MC_NODISCARD constexpr auto operator+=(StereoFrame<T>& lhs, StereoFrame<T> rhs) noexcept
    -> StereoFrame<T>&;

template<typename T>
MC_NODISCARD constexpr auto operator-=(StereoFrame<T>& lhs, StereoFrame<T> rhs) noexcept
    -> StereoFrame<T>&;

template<typename T>
MC_NODISCARD constexpr auto operator*=(StereoFrame<T>& lhs, StereoFrame<T> rhs) noexcept
    -> StereoFrame<T>&;

template<typename T>
MC_NODISCARD constexpr auto operator/=(StereoFrame<T>& lhs, StereoFrame<T> rhs) noexcept
    -> StereoFrame<T>&;

template<typename T>
MC_NODISCARD constexpr auto operator+=(StereoFrame<T>& lhs, T rhs) noexcept
    -> StereoFrame<T>&;

template<typename T>
MC_NODISCARD constexpr auto operator-=(StereoFrame<T>& lhs, T rhs) noexcept
    -> StereoFrame<T>&;

template<typename T>
MC_NODISCARD constexpr auto operator*=(StereoFrame<T>& lhs, T rhs) noexcept
    -> StereoFrame<T>&;

template<typename T>
MC_NODISCARD constexpr auto operator/=(StereoFrame<T>& lhs, T rhs) noexcept
    -> StereoFrame<T>&;

}  // namespace dsp
}  // namespace mc

#include "stereo_frame.cpp"  // NOLINT
