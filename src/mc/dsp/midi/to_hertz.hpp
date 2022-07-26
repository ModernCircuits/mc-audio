// SPDX-License-Identifier: BSL-1.0

#pragma once

#include <mc/core/algorithm.hpp>
#include <mc/core/math.hpp>
#include <mc/core/span.hpp>
#include <mc/core/type_traits.hpp>
#include <mc/dsp/midi/note.hpp>

namespace mc::dsp {

/// \brief Get the frequency of a MIDI note.
template<typename T>
auto toHertz(MidiNote note) -> Frequency<T>
{
    return T{440} * std::pow(T{2}, static_cast<T>(toUnderlying(note) - 69) / T{12});
}

/// \brief Get the frequency of MIDI notes.
template<typename T>
auto toHertz(Span<MidiNote const> notes, Span<Frequency<T>> out) -> void
{
    std::transform(begin(notes), end(notes), begin(out), toHertz<T>);
}

}  // namespace mc::dsp
