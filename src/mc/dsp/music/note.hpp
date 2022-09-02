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
    explicit constexpr Note(uint8_t note) noexcept;

    MC_NODISCARD explicit constexpr operator uint8_t() const noexcept;

    MC_NODISCARD constexpr auto operator++() noexcept -> Note&;
    MC_NODISCARD constexpr auto operator++(int) noexcept -> Note;

    MC_NODISCARD constexpr auto operator--() noexcept -> Note&;
    MC_NODISCARD constexpr auto operator--(int) noexcept -> Note;

private:
    uint8_t _note{0};
};

}  // namespace mc::dsp

#include "note.impl.hpp"
