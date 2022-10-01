// SPDX-License-Identifier: BSL-1.0
#pragma once

#include <mc/core/config.hpp>

#include <mc/audio/music/keyboard/is_black_key.hpp>

namespace mc {

constexpr auto isWhiteKey(Note note) noexcept -> bool { return not isBlackKey(note); }

}  // namespace mc
