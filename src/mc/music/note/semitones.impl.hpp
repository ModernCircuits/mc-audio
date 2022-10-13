// SPDX-License-Identifier: BSL-1.0
#pragma once

namespace mc {

constexpr Semitones::Semitones(int val) noexcept : _val{static_cast<uint8_t>(val)} {}

constexpr auto Semitones::count() const noexcept -> int { return static_cast<int>(_val); }

constexpr Semitones::operator int() const noexcept { return count(); }

constexpr Semitones::operator uint8_t() const noexcept { return _val; }

constexpr auto operator++(Semitones& semitones) noexcept -> Semitones&
{
    semitones = Semitones{semitones.count() + 1};
    return semitones;
}

constexpr auto operator++(Semitones& semitones, int) noexcept -> Semitones
{
    auto old = semitones;
    ++semitones;
    return old;
}

constexpr auto operator--(Semitones& semitones) noexcept -> Semitones&
{
    semitones = Semitones{semitones.count() - 1};
    return semitones;
}

constexpr auto operator--(Semitones& semitones, int) noexcept -> Semitones
{
    auto old = semitones;
    --semitones;
    return old;
}

constexpr auto operator==(Semitones lhs, Semitones rhs) -> bool
{
    return lhs.count() == rhs.count();
}

constexpr auto operator!=(Semitones lhs, Semitones rhs) -> bool { return !(lhs == rhs); }

constexpr auto operator<(Semitones lhs, Semitones rhs) -> bool
{
    return lhs.count() < rhs.count();
}

constexpr auto operator<=(Semitones lhs, Semitones rhs) -> bool
{
    return lhs.count() <= rhs.count();
}

constexpr auto operator>(Semitones lhs, Semitones rhs) -> bool
{
    return lhs.count() > rhs.count();
}

constexpr auto operator>=(Semitones lhs, Semitones rhs) -> bool
{
    return lhs.count() >= rhs.count();
}

}  // namespace mc
