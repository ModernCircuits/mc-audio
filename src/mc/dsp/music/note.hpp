// SPDX-License-Identifier: BSL-1.0

#pragma once

#include <mc/core/config.hpp>

#include <mc/core/cstdint.hpp>
#include <mc/core/format.hpp>

namespace mc {
namespace dsp {

/// \class Note "mc/dsp/music/note.hpp" <mc/dsp/music/note.hpp>
/// \brief A music note.
/// \example note.cpp
/// \ingroup mc-dsp-music
struct Note
{
    constexpr Note() = default;
    explicit constexpr Note(uint8_t note) noexcept;

    MC_NODISCARD explicit constexpr operator uint8_t() const noexcept;

    MC_NODISCARD constexpr auto operator++() noexcept -> Note&;
    MC_NODISCARD constexpr auto operator++(int) noexcept -> Note;

    MC_NODISCARD constexpr auto operator--() noexcept -> Note&;
    MC_NODISCARD constexpr auto operator--(int) noexcept -> Note;

private:
    uint8_t _note{0};
};

MC_NODISCARD constexpr auto operator==(Note lhs, Note rhs) noexcept -> bool;
MC_NODISCARD constexpr auto operator!=(Note lhs, Note rhs) noexcept -> bool;

}  // namespace dsp
}  // namespace mc

template<>
struct fmt::formatter<mc::dsp::Note>
{
    constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin());

    template<typename FormatContext>
    auto format(mc::dsp::Note const& note, FormatContext& ctx) const -> decltype(ctx.out());

    // Presentation format: 'n' - number, 'h' - human.
    char presentation = 'n';
};

#include "note.cpp"  // NOLINT
