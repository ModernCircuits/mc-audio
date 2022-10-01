// SPDX-License-Identifier: BSL-1.0
#pragma once

#include <mc/core/config.hpp>

#include <mc/audio/music/note/note.hpp>

namespace mc {

/// \ingroup mc-audio-music
[[nodiscard]] constexpr auto isWhiteKey(Note note) noexcept -> bool;

}  // namespace mc

#include "is_white_key.cpp"  // NOLINT
