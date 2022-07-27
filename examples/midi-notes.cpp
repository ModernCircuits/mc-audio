// SPDX-License-Identifier: BSL-1.0

#include <mc/core/config.hpp>
#include <mc/dsp.hpp>

#include <cstdio>

auto main() -> int
{
    auto notes = std::array<mc::dsp::MidiNote, 88>{};
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
