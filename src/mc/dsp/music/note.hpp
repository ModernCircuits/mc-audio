// SPDX-License-Identifier: BSL-1.0

#pragma once

#include <mc/core/config.hpp>

#include <mc/core/cstdint.hpp>

namespace mc::dsp {

/// \class Note "mc/dsp/music/note.hpp" <mc/dsp/music/note.hpp>
/// \brief A music note.
/// \example note.cpp
/// \ingroup mc-dsp-music
struct Note
{
    constexpr Note() = default;

    explicit constexpr Note(uint8_t note) noexcept : _note(note) {}

    MC_NODISCARD explicit constexpr operator uint8_t() const noexcept { return _note; }

private:
    uint8_t _note{};
};

}  // namespace mc::dsp
