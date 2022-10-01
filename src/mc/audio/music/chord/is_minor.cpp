// SPDX-License-Identifier: BSL-1.0
#pragma once

#include <mc/core/config.hpp>

#include <mc/audio/music/note/semitones.hpp>

namespace mc {

constexpr auto isMinor(Span<Note const> notes) noexcept -> bool
{
    if (notes.size() < 2) { return false; }
    if (notes.size() == 2) {
        if (notes[1] - notes[0] == Semitones{3}) { return true; }
    }

    return notes[1] - notes[0] == Semitones{3} && notes[2] - notes[0] == Semitones{7};
}

}  // namespace mc
