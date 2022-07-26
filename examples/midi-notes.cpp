// SPDX-License-Identifier: BSL-1.0

#include <mc/core.hpp>
#include <mc/dsp.hpp>

auto main() -> int
{
    auto notes = mc::Array<mc::dsp::MidiNote, 88>{};
    std::generate(begin(notes), end(notes), [i = uint8_t{0}]() mutable {
        return mc::dsp::MidiNote{i++};
    });

    for (auto original : notes) {
        auto const hertz = mc::dsp::toHertz<float>(original);
        auto const note  = mc::dsp::toMidiNote(hertz);
        std::printf("note: %d\tfreq: %f\n", static_cast<uint8_t>(note), hertz.count());
    }
    return 0;
}