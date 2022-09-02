// SPDX-License-Identifier: BSL-1.0

#pragma once

#include <mc/dsp/music/note.hpp>
#include <mc/dsp/units/frequency.hpp>

#include <mc/core/algorithm.hpp>
#include <mc/core/cmath.hpp>
#include <mc/core/span.hpp>
#include <mc/core/type_traits.hpp>

namespace mc::dsp {

/// \brief Get the frequency of a MIDI note.
/// \ingroup mc-dsp-music
/// \relates Note
template<typename T>
auto toHertz(Note note) -> Hertz<T>
{
    auto hz = T{440} * std::pow(T{2}, static_cast<T>(static_cast<uint8_t>(note) - 69) / T{12});
    return Hertz<T>{hz};
}

/// \brief Get the frequency of MIDI notes.
/// \ingroup mc-dsp-music
/// \relates Note
template<typename T>
auto toHertz(span<Note const> notes, span<Hertz<T>> out) -> void
{
    std::transform(begin(notes), end(notes), begin(out), toHertz<T>);
}

}  // namespace mc::dsp
