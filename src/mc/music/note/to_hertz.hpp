// SPDX-License-Identifier: BSL-1.0
#pragma once

#include <mc/audio/units/frequency.hpp>

#include <mc/music/note/note.hpp>

namespace mc {

/// \brief Get the frequency of a MIDI note.
/// \ingroup mc-music
/// \relates Note
template<typename T>
[[nodiscard]] constexpr auto toHertz(Note note) noexcept -> Hertz<T>;

}  // namespace mc

#include "to_hertz.impl.hpp"
