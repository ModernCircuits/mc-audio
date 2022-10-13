// SPDX-License-Identifier: BSL-1.0
#pragma once

#include <mc/core/cstdint.hpp>

namespace mc {

/// \class Semitones
/// \ingroup mc-music
struct Semitones
{
    constexpr Semitones() = default;
    explicit constexpr Semitones(int val) noexcept;

    [[nodiscard]] constexpr auto count() const noexcept -> int;
    [[nodiscard]] explicit constexpr operator int() const noexcept;
    [[nodiscard]] explicit constexpr operator uint8_t() const noexcept;

private:
    uint8_t _val{0};
};

constexpr auto operator++(Semitones& semitones) noexcept -> Semitones&;
constexpr auto operator++(Semitones& semitones, int) noexcept -> Semitones;

constexpr auto operator--(Semitones& semitones) noexcept -> Semitones&;
constexpr auto operator--(Semitones& semitones, int) noexcept -> Semitones;

[[nodiscard]] constexpr auto operator==(Semitones lhs, Semitones rhs) -> bool;
[[nodiscard]] constexpr auto operator!=(Semitones lhs, Semitones rhs) -> bool;
[[nodiscard]] constexpr auto operator<(Semitones lhs, Semitones rhs) -> bool;
[[nodiscard]] constexpr auto operator<=(Semitones lhs, Semitones rhs) -> bool;
[[nodiscard]] constexpr auto operator>(Semitones lhs, Semitones rhs) -> bool;
[[nodiscard]] constexpr auto operator>=(Semitones lhs, Semitones rhs) -> bool;

}  // namespace mc

#include "semitones.impl.hpp"
