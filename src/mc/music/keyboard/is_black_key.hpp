// SPDX-License-Identifier: BSL-1.0
#pragma once

#include <mc/music/note/note.hpp>

namespace mc {

/// \ingroup mc-music
[[nodiscard]] constexpr auto isBlackKey(Note note) noexcept -> bool;

}  // namespace mc

#include "is_black_key.impl.hpp"
