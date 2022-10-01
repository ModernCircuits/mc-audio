// SPDX-License-Identifier: BSL-1.0
#pragma once

#include <mc/core/config.hpp>

#include <mc/audio/music/note/note.hpp>

namespace mc {

/// \ingroup mc-audio-music
[[nodiscard]] constexpr auto isBlackKey(Note note) noexcept -> bool;

}  // namespace mc

#include "is_black_key.cpp"  // NOLINT
