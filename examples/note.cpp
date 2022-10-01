// SPDX-License-Identifier: BSL-1.0

#include <mc/core/array.hpp>
#include <mc/core/numeric.hpp>
#include <mc/core/print.hpp>
#include <mc/music.hpp>

using namespace mc;

auto makePianoNotes() -> Array<Note, 88>
{
    auto notes = Array<Note, 88>{};
    std::iota(begin(notes), end(notes), Note{21});
    return notes;
}

auto main() -> int
{
    auto const notes = makePianoNotes();
    for (auto original : notes) {
        auto const hertz = toHertz<float>(original);
        auto const note  = toNearestNote(hertz);
        print(
            "note: {:n}\t frequency: {:.2f}\t isBlack: {}\n",
            note,
            hertz.count(),
            isBlackKey(original)
        );
    }

    return 0;
}
