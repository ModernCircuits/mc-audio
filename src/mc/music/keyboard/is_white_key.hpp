// SPDX-License-Identifier: BSL-1.0
#pragma once

#include <mc/music/note/note.hpp>

namespace mc {

/// \ingroup mc-music
[[nodiscard]] constexpr auto isWhiteKey(Note note) noexcept -> bool;

}  // namespace mc

#include "is_white_key.ipp"
