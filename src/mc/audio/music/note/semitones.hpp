// SPDX-License-Identifier: BSL-1.0

#pragma once

#include <mc/core/config.hpp>

#include <mc/core/cstdint.hpp>

namespace mc {

/// \class Semitones
/// \ingroup mc-audio-music
struct Semitones
{
    constexpr Semitones() = default;
    explicit constexpr Semitones(int val) noexcept;

    [[nodiscard]] explicit constexpr operator uint8_t() const noexcept;
    [[nodiscard]] explicit constexpr operator int() const noexcept;

    [[nodiscard]] constexpr auto operator++() -> Semitones&;
    [[nodiscard]] constexpr auto operator++(int) -> Semitones;

    [[nodiscard]] constexpr auto operator--() -> Semitones&;
    [[nodiscard]] constexpr auto operator--(int) -> Semitones;

private:
    uint8_t _val{0};
};

[[nodiscard]] constexpr auto operator==(Semitones lhs, Semitones rhs) -> bool;
[[nodiscard]] constexpr auto operator!=(Semitones lhs, Semitones rhs) -> bool;
[[nodiscard]] constexpr auto operator<(Semitones lhs, Semitones rhs) -> bool;
[[nodiscard]] constexpr auto operator<=(Semitones lhs, Semitones rhs) -> bool;
[[nodiscard]] constexpr auto operator>(Semitones lhs, Semitones rhs) -> bool;
[[nodiscard]] constexpr auto operator>=(Semitones lhs, Semitones rhs) -> bool;

}  // namespace mc

#include "semitones.cpp"  // NOLINT
