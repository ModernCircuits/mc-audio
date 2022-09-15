// SPDX-License-Identifier: BSL-1.0
#pragma once

#include <mc/core/config.hpp>

#include <mc/dsp/music/note.hpp>

namespace mc::dsp {

/// \ingroup mc-dsp-music
[[nodiscard]] constexpr auto isBlackKey(Note note) noexcept -> bool;

/// \ingroup mc-dsp-music
[[nodiscard]] constexpr auto isWhiteKey(Note note) noexcept -> bool;

}  // namespace mc::dsp

#include "keyboard.cpp"  // NOLINT
