// SPDX-License-Identifier: BSL-1.0
#pragma once

#include <mc/core/numeric.hpp>

namespace mc {

template<size_t Size>
constexpr auto makePianoNotes(Note lowestNote) -> Array<Note, Size>
{
    auto notes = Array<Note, Size>{};
    std::iota(std::begin(notes), std::end(notes), lowestNote);
    return notes;
}

inline auto makePianoNotes(size_t size, Note lowestNote) -> Vector<Note>
{
    auto notes = Vector<Note>(size);
    std::iota(std::begin(notes), std::end(notes), lowestNote);
    return notes;
}

}  // namespace mc
