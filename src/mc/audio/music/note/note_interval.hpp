// SPDX-License-Identifier: BSL-1.0

#pragma once

#include <mc/core/config.hpp>

#include <mc/core/cstdint.hpp>

namespace mc {

/// \class NoteInterval
/// \ingroup mc-audio-music
struct NoteInterval
{
    constexpr NoteInterval() = default;
    explicit constexpr NoteInterval(uint8_t val) noexcept;

    [[nodiscard]] explicit constexpr operator uint8_t() const noexcept;

    [[nodiscard]] constexpr auto operator++() -> NoteInterval&;
    [[nodiscard]] constexpr auto operator++(int) -> NoteInterval;

    [[nodiscard]] constexpr auto operator--() -> NoteInterval&;
    [[nodiscard]] constexpr auto operator--(int) -> NoteInterval;

private:
    uint8_t _val{0};
};

[[nodiscard]] constexpr auto operator==(NoteInterval lhs, NoteInterval rhs) -> bool;
[[nodiscard]] constexpr auto operator!=(NoteInterval lhs, NoteInterval rhs) -> bool;
[[nodiscard]] constexpr auto operator<(NoteInterval lhs, NoteInterval rhs) -> bool;
[[nodiscard]] constexpr auto operator<=(NoteInterval lhs, NoteInterval rhs) -> bool;
[[nodiscard]] constexpr auto operator>(NoteInterval lhs, NoteInterval rhs) -> bool;
[[nodiscard]] constexpr auto operator>=(NoteInterval lhs, NoteInterval rhs) -> bool;

}  // namespace mc

#include "note_interval.cpp"  // NOLINT
