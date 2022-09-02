// SPDX-License-Identifier: BSL-1.0

#include <mc/core/array.hpp>
#include <mc/core/format.hpp>
#include <mc/dsp.hpp>

namespace dsp = mc::dsp;

auto makePianoNotes() -> std::array<dsp::Note, 88>
{
    auto notes = std::array<dsp::Note, 88>{};
    std::generate(begin(notes), end(notes), [n = dsp::Note{21}]() mutable { return n++; });
    return notes;
}

auto main() -> int
{
    auto const notes = makePianoNotes();
    for (auto original : notes) {
        auto const hertz = dsp::toHertz<float>(original);
        auto const note  = dsp::toNearestNote(hertz);
        mc::print(
            "note: {:03}\t frequency: {:.2f}\t isBlack: {}\n",
            static_cast<uint8_t>(note),
            hertz.count(),
            dsp::isBlackNote(original)
        );
    }

    return 0;
}
