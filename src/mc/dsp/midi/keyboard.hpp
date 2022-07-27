// SPDX-License-Identifier: BSL-1.0

#pragma once

#include <mc/dsp/midi/note.hpp>

#include <mc/core/array.hpp>
#include <mc/core/type_traits.hpp>

namespace mc::dsp {

/// \ingroup mc-dsp-midi
[[nodiscard]] constexpr auto isBlackNote(MidiNote note) noexcept -> bool
{
    constexpr auto const notes = std::array<bool, 12>{
        false,  // C
        true,   // C#
        false,  // D
        true,   // D#
        false,  // E
        false,  // F
        true,   // F#
        false,  // G
        true,   // G#
        false,  // A
        true,   // A#
        false,  // B
    };
    return notes[static_cast<uint8_t>(note) % 12U];
}

/// \ingroup mc-dsp-midi
[[nodiscard]] constexpr auto isWhiteNote(MidiNote note) noexcept -> bool
{
    return !isBlackNote(note);
}

}  // namespace mc::dsp
