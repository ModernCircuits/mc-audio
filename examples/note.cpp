// SPDX-License-Identifier: BSL-1.0

#include <mc/core/array.hpp>
#include <mc/core/numeric.hpp>
#include <mc/core/print.hpp>
#include <mc/music.hpp>

using namespace mc;

auto main() -> int
{
    auto const notes = makePianoNotes<88>(Note{21});
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
