// SPDX-License-Identifier: BSL-1.0

#pragma once

#include <mc/core/types.hpp>

namespace mc::dsp {

/// \class MidiNote "mc/dsp/midi/note.hpp" <mc/dsp/midi/note.hpp>
/// \brief A MIDI Note.
/// \example midi-notes.cpp
/// \ingroup mc-dsp-midi
struct MidiNote
{
    constexpr MidiNote() = default;

    explicit constexpr MidiNote(uint8_t note) noexcept : _note(note) {}

    [[nodiscard]] explicit constexpr operator uint8_t() const noexcept { return _note; }

private:
    uint8_t _note{};
};

}  // namespace mc::dsp
