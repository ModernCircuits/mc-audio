// SPDX-License-Identifier: BSL-1.0
#pragma once

#include <mc/core/config.hpp>

#include <mc/music/note/semitones.hpp>

namespace mc {

constexpr auto isMajor(Span<Note const> notes) noexcept -> bool
{
    if (notes.size() < 2) { return false; }
    auto const hasThird = notes[1] - notes[0] == Semitones{3};
    if (notes.size() == 2) { return hasThird; }
    return notes[1] - notes[0] == Semitones{4} && notes[2] - notes[0] == Semitones{7};
}

}  // namespace mc
