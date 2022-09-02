// SPDX-License-Identifier: BSL-1.0

#include <mc/dsp.hpp>

#include <array>
#include <cstdio>

namespace dsp = mc::dsp;

auto main() -> int
{
    auto notes = std::array<dsp::Note, 88>{};
    std::generate(begin(notes), end(notes), [i = uint8_t{0}]() mutable { return dsp::Note{i++}; });

    for (auto original : notes) {
        auto const hertz = dsp::toHertz<float>(original);
        auto const note  = dsp::toNearestNote(hertz);
        std::printf("note: %d\tfreq: %f\n", static_cast<uint8_t>(note), hertz.count());
    }

    return 0;
}
