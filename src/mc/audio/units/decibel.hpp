// SPDX-License-Identifier: BSL-1.0

#pragma once

#include <mc/core/config.hpp>

#include <mc/core/cmath.hpp>

namespace mc {

template<typename T>
struct Decibel
{
    constexpr Decibel() noexcept = default;
    constexpr explicit Decibel(T v) noexcept;

    [[nodiscard]] constexpr auto count() const noexcept -> T;

private:
    T _count{};
};

template<typename T>
[[nodiscard]] constexpr auto toDecibel(T gain) noexcept -> Decibel<T>;

template<typename T>
[[nodiscard]] constexpr auto toGain(Decibel<T> dB) noexcept -> T;

template<typename T>
[[nodiscard]] constexpr auto operator==(Decibel<T> lhs, Decibel<T> rhs) noexcept -> bool;

template<typename T>
[[nodiscard]] constexpr auto operator!=(Decibel<T> lhs, Decibel<T> rhs) noexcept -> bool;

template<typename T>
[[nodiscard]] constexpr auto operator<(Decibel<T> lhs, Decibel<T> rhs) noexcept -> bool;

template<typename T>
[[nodiscard]] constexpr auto operator<=(Decibel<T> lhs, Decibel<T> rhs) noexcept -> bool;

template<typename T>
[[nodiscard]] constexpr auto operator>(Decibel<T> lhs, Decibel<T> rhs) noexcept -> bool;

template<typename T>
[[nodiscard]] constexpr auto operator>=(Decibel<T> lhs, Decibel<T> rhs) noexcept -> bool;

}  // namespace mc

#include "decibel.impl.hpp"
