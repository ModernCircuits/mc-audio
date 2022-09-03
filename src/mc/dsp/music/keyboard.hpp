// SPDX-License-Identifier: BSL-1.0
#pragma once

#include <mc/core/config.hpp>

#include <mc/dsp/music/note.hpp>

namespace mc {
namespace dsp {

/// \ingroup mc-dsp-music
MC_NODISCARD constexpr auto isBlackNote(Note note) noexcept -> bool;

/// \ingroup mc-dsp-music
MC_NODISCARD constexpr auto isWhiteNote(Note note) noexcept -> bool;

}  // namespace dsp
}  // namespace mc

#include "keyboard.cpp"  // NOLINT
