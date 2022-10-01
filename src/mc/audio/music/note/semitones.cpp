// SPDX-License-Identifier: BSL-1.0

#pragma once

namespace mc {

constexpr Semitones::Semitones(int val) noexcept : _val{static_cast<uint8_t>(val)} {}

constexpr Semitones::operator uint8_t() const noexcept { return _val; }

constexpr Semitones::operator int() const noexcept { return static_cast<int>(_val); }

constexpr auto Semitones::operator++() -> Semitones&
{
    ++_val;
    return *this;
}

constexpr auto Semitones::operator++(int) -> Semitones
{
    auto old = *this;
    ++_val;
    return old;
}

constexpr auto Semitones::operator--() -> Semitones&
{
    --_val;
    return *this;
}

constexpr auto Semitones::operator--(int) -> Semitones
{
    auto old = *this;
    --_val;
    return old;
}

constexpr auto operator==(Semitones lhs, Semitones rhs) -> bool
{
    return static_cast<int>(lhs) == static_cast<int>(rhs);
}

constexpr auto operator!=(Semitones lhs, Semitones rhs) -> bool { return !(lhs == rhs); }

constexpr auto operator<(Semitones lhs, Semitones rhs) -> bool
{
    return static_cast<int>(lhs) < static_cast<int>(rhs);
}

constexpr auto operator<=(Semitones lhs, Semitones rhs) -> bool
{
    return static_cast<int>(lhs) <= static_cast<int>(rhs);
}

constexpr auto operator>(Semitones lhs, Semitones rhs) -> bool
{
    return static_cast<int>(lhs) > static_cast<int>(rhs);
}

constexpr auto operator>=(Semitones lhs, Semitones rhs) -> bool
{
    return static_cast<int>(lhs) >= static_cast<int>(rhs);
}

}  // namespace mc
