// SPDX-License-Identifier: BSL-1.0

#pragma once

#include <mc/core/algorithm.hpp>
#include <mc/core/math.hpp>
#include <mc/core/span.hpp>
#include <mc/core/type_traits.hpp>
#include <mc/dsp/midi/note.hpp>
#include <mc/dsp/units/frequency.hpp>

namespace mc::dsp {

/// \brief Get the frequency of a MIDI note.
/// \ingroup group-midi
template<typename T>
auto toHertz(MidiNote note) -> Hertz<T>
{
    auto hz = T{440} * std::pow(T{2}, static_cast<T>(toUnderlying(note) - 69) / T{12});
    return Hertz<T>{hz};
}

/// \brief Get the frequency of MIDI notes.
/// \ingroup group-midi
template<typename T>
auto toHertz(Span<MidiNote const> notes, Span<Hertz<T>> out) -> void
{
    std::transform(begin(notes), end(notes), begin(out), toHertz<T>);
}

}  // namespace mc::dsp
