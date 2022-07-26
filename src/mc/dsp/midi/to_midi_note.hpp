// SPDX-License-Identifier: BSL-1.0

#pragma once

#include <mc/core/algorithm.hpp>
#include <mc/core/math.hpp>
#include <mc/core/span.hpp>
#include <mc/dsp/midi/note.hpp>
#include <mc/dsp/units/frequency.hpp>

namespace mc::dsp {

/// \brief Get MIDI note number for a given frequency
template<typename T>
auto toMidiNote(Hertz<T> frequency) -> MidiNote
{
    auto raw = T{12} * (std::log2(frequency.count()) - std::log2(T{440})) + T{69};
    return static_cast<MidiNote>(std::round(raw));
}

/// \brief Get MIDI note numbers for given frequencies
template<typename T>
auto toMidiNote(Span<Frequency<T> const> freq, Span<MidiNote> out) -> void
{
    std::transform(begin(freq), end(freq), begin(out), toMidiNote<T>);
}

}  // namespace mc::dsp
