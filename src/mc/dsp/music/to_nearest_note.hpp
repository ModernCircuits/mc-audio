// SPDX-License-Identifier: BSL-1.0

#pragma once

#include <mc/dsp/music/note.hpp>
#include <mc/dsp/units/frequency.hpp>

#include <mc/core/algorithm.hpp>
#include <mc/core/cmath.hpp>
#include <mc/core/span.hpp>

namespace mc {
namespace dsp {

/// \brief Get MIDI note number for a given frequency
/// \ingroup mc-dsp-music
template<typename T>
auto toNearestNote(Hertz<T> frequency) -> Note
{
    auto raw = T{12} * (log2(frequency.count()) - log2(T{440})) + T{69};
    return Note{static_cast<std::uint8_t>(std::round(raw))};
}

/// \brief Get MIDI note numbers for given frequencies
/// \ingroup mc-dsp-music
template<typename T>
auto toNearestNote(Span<Frequency<T> const> freq, Span<Note> out) -> void
{
    std::transform(begin(freq), end(freq), begin(out), toNearestNote<T>);
}

}  // namespace dsp
}  // namespace mc
