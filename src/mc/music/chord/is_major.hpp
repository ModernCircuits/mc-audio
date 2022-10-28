// SPDX-License-Identifier: BSL-1.0
#pragma once

#include <mc/music/note/note.hpp>

#include <mc/core/span.hpp>

namespace mc {

/// \ingroup mc-music
[[nodiscard]] constexpr auto isMajor(Span<Note const> notes) noexcept -> bool;

}  // namespace mc

#include "is_major.ipp"
