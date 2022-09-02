// SPDX-License-Identifier: BSL-1.0

#pragma once

#include <mc/dsp/music/note.hpp>
#include <mc/dsp/units/frequency.hpp>

#include <mc/core/span.hpp>

namespace mc::dsp {

/// \brief Get the frequency of a MIDI note.
/// \ingroup mc-dsp-music
/// \relates Note
template<typename T>
[[nodiscard]] constexpr auto toHertz(Note note) noexcept -> Hertz<T>;

/// \brief Get the frequency of MIDI notes.
/// \ingroup mc-dsp-music
/// \relates Note
template<typename T>
constexpr auto toHertz(span<Note const> notes, span<Hertz<T>> out) -> void;

}  // namespace mc::dsp

#include "to_hertz.impl.hpp"
