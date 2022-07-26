// SPDX-License-Identifier: BSL-1.0

#pragma once

#include <mc/core/type_traits.hpp>
#include <mc/dsp/midi/note.hpp>

namespace mc::dsp {

/// \ingroup group-midi
[[nodiscard]] constexpr auto isBlackNote(MidiNote note) noexcept -> bool
{
    auto const noteNumber = static_cast<unsigned>(toUnderlying(note));
    return ((1U << (noteNumber % 12U)) & 0x054a) != 0U;
}

/// \ingroup group-midi
[[nodiscard]] constexpr auto isWhiteNote(MidiNote note) noexcept -> bool
{
    return !isBlackNote(note);
}

}  // namespace mc::dsp
