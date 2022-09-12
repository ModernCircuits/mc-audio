// SPDX-License-Identifier: BSL-1.0

#pragma once

#include <mc/core/config.hpp>

#include <mc/core/cmath.hpp>

namespace mc {
namespace dsp {

template<typename T>
struct Decibel
{
    constexpr Decibel() noexcept = default;
    constexpr explicit Decibel(T v) noexcept;

    MC_NODISCARD constexpr auto count() const noexcept -> T;

private:
    T _count{};
};

template<typename T>
MC_NODISCARD constexpr auto toDecibel(T gain) noexcept -> Decibel<T>;

template<typename T>
MC_NODISCARD constexpr auto toGain(Decibel<T> dB) noexcept -> T;

}  // namespace dsp
}  // namespace mc

#include "decibel.cpp"  // NOLINT
