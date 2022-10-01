// SPDX-License-Identifier: BSL-1.0
#pragma once

#include <mc/core/config.hpp>

#include <mc/core/array.hpp>
#include <mc/core/cstddef.hpp>
#include <mc/core/vector.hpp>
#include <mc/music/note/note.hpp>

namespace mc {

/// \ingroup mc-music
template<size_t Size>
[[nodiscard]] constexpr auto makePianoNotes(Note lowestNote) -> Array<Note, Size>;

[[nodiscard]] constexpr auto makePianoNotes(size_t size, Note lowestNote) -> Vector<Note>;

}  // namespace mc

#include "make_piano_notes.cpp"  // NOLINT
