// SPDX-License-Identifier: BSL-1.0

#pragma once

#include <mc/audio/units/frequency.hpp>

#include <mc/core/algorithm.hpp>
#include <mc/core/cmath.hpp>
#include <mc/core/span.hpp>
#include <mc/music/note/note.hpp>

namespace mc {

/// \brief Get MIDI note number for a given frequency
/// \ingroup mc-music
template<typename T>
auto toNearestNote(Hertz<T> frequency) -> Note
{
    auto raw = T{12} * (log2(frequency.count()) - log2(T{440})) + T{69};
    return Note{static_cast<int>(std::round(raw))};
}

}  // namespace mc
