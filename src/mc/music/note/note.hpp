// SPDX-License-Identifier: BSL-1.0

#pragma once

#include <mc/core/config.hpp>

#include <mc/music/note/semitones.hpp>

#include <mc/core/cstdint.hpp>
#include <mc/core/format.hpp>

namespace mc {

/// \class Note "mc/music/note.hpp" <mc/music/note.hpp>
/// \brief A music note.
/// \example note.cpp
/// \ingroup mc-music
struct Note
{
    constexpr Note() = default;
    explicit constexpr Note(int note) noexcept;

    [[nodiscard]] constexpr auto count() const noexcept -> int;
    [[nodiscard]] explicit constexpr operator int() const noexcept;
    [[nodiscard]] explicit constexpr operator uint8_t() const noexcept;

private:
    uint8_t _val{0};
};

constexpr auto operator++(Note& note) noexcept -> Note&;
constexpr auto operator++(Note& note, int) noexcept -> Note;

constexpr auto operator--(Note& note) noexcept -> Note&;
constexpr auto operator--(Note& note, int) noexcept -> Note;

[[nodiscard]] constexpr auto operator==(Note lhs, Note rhs) noexcept -> bool;
[[nodiscard]] constexpr auto operator!=(Note lhs, Note rhs) noexcept -> bool;
[[nodiscard]] constexpr auto operator<(Note lhs, Note rhs) noexcept -> bool;
[[nodiscard]] constexpr auto operator<=(Note lhs, Note rhs) noexcept -> bool;
[[nodiscard]] constexpr auto operator>(Note lhs, Note rhs) noexcept -> bool;
[[nodiscard]] constexpr auto operator>=(Note lhs, Note rhs) noexcept -> bool;

[[nodiscard]] constexpr auto operator-(Note lhs, Note rhs) noexcept -> Semitones;
[[nodiscard]] constexpr auto operator+(Note lhs, Semitones rhs) noexcept -> Note;
[[nodiscard]] constexpr auto operator-(Note lhs, Semitones rhs) noexcept -> Note;

}  // namespace mc

template<>
struct fmt::formatter<mc::Note>
{
    constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin());

    template<typename FormatContext>
    auto format(mc::Note const& note, FormatContext& ctx) const -> decltype(ctx.out());

    // Presentation format: 'n' - number, 'h' - human.
    char presentation = 'n';
};

#include "note.impl.hpp"
