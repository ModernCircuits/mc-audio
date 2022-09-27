// SPDX-License-Identifier: BSL-1.0

#include <mc/audio.hpp>
#include <mc/core/array.hpp>
#include <mc/core/numeric.hpp>
#include <mc/core/print.hpp>

using namespace mc;

auto makePianoNotes() -> Array<dsp::Note, 88>
{
    auto notes = Array<dsp::Note, 88>{};
    std::iota(begin(notes), end(notes), dsp::Note{21});
    return notes;
}

auto main() -> int
{
    auto const notes = makePianoNotes();
    for (auto original : notes) {
        auto const hertz = dsp::toHertz<float>(original);
        auto const note  = dsp::toNearestNote(hertz);
        print(
            "note: {:n}\t frequency: {:.2f}\t isBlack: {}\n",
            note,
            hertz.count(),
            dsp::isBlackKey(original)
        );
    }

    return 0;
}
