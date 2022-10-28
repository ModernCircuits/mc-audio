// SPDX-License-Identifier: BSL-1.0
#pragma once

#include <mc/core/array.hpp>
#include <mc/core/cstddef.hpp>

namespace mc {

constexpr auto isBlackKey(Note note) noexcept -> bool
{
    constexpr auto const notes = Array<bool, 12>{
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
    return notes[static_cast<size_t>(note.count() % 12)];
}

}  // namespace mc
