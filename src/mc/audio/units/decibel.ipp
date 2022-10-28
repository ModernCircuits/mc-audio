// SPDX-License-Identifier: BSL-1.0
#pragma once

#include <mc/core/cmath.hpp>

namespace mc {

template<typename T>
constexpr Decibel<T>::Decibel(T v) noexcept : _count{v}
{}

template<typename T>
constexpr auto Decibel<T>::count() const noexcept -> T
{
    return _count;
}

template<typename T>
constexpr auto toDecibel(T gain) noexcept -> Decibel<T>
{
    return Decibel<T>{log10(gain) * T(20)};
}

template<typename T>
constexpr auto toGain(Decibel<T> dB) noexcept -> T
{
    return pow(T(10), dB.count() * T(0.05));
}

template<typename T>
constexpr auto operator==(Decibel<T> lhs, Decibel<T> rhs) noexcept -> bool
{
    return lhs.count() == rhs.count();
}

template<typename T>
constexpr auto operator!=(Decibel<T> lhs, Decibel<T> rhs) noexcept -> bool
{
    return lhs.count() != rhs.count();
}

template<typename T>
constexpr auto operator<(Decibel<T> lhs, Decibel<T> rhs) noexcept -> bool
{
    return lhs.count() < rhs.count();
}

template<typename T>
constexpr auto operator<=(Decibel<T> lhs, Decibel<T> rhs) noexcept -> bool
{
    return lhs.count() <= rhs.count();
}

template<typename T>
constexpr auto operator>(Decibel<T> lhs, Decibel<T> rhs) noexcept -> bool
{
    return lhs.count() > rhs.count();
}

template<typename T>
constexpr auto operator>=(Decibel<T> lhs, Decibel<T> rhs) noexcept -> bool
{
    return lhs.count() >= rhs.count();
}

}  // namespace mc
