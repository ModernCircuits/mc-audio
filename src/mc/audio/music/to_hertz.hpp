// SPDX-License-Identifier: BSL-1.0

#pragma once

#include <mc/core/config.hpp>

#include <mc/audio/music/note.hpp>
#include <mc/audio/units/frequency.hpp>

#include <mc/core/span.hpp>

namespace mc {

/// \brief Get the frequency of a MIDI note.
/// \ingroup mc-audio-music
/// \relates Note
template<typename T>
[[nodiscard]] constexpr auto toHertz(Note note) noexcept -> Hertz<T>;

}  // namespace mc

#include "to_hertz.cpp"  // NOLINT
