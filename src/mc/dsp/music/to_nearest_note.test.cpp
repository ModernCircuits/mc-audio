// SPDX-License-Identifier: BSL-1.0

#include <mc/dsp/music.hpp>
#include <mc/dsp/units.hpp>

#include <catch2/catch_template_test_macros.hpp>

namespace dsp = mc::dsp;

static_assert(dsp::Hertz<float>{440.0F}.count() == 440.0F);

TEMPLATE_TEST_CASE("dsp/music: toNearestNote", "[dsp][music]", float, double)
{
    using T = TestType;
    REQUIRE(dsp::toNearestNote(dsp::Hertz<T>(T(55))) == dsp::Note{33});   // A1
    REQUIRE(dsp::toNearestNote(dsp::Hertz<T>(T(110))) == dsp::Note{45});  // A2
    REQUIRE(dsp::toNearestNote(dsp::Hertz<T>(T(220))) == dsp::Note{57});  // A3
    REQUIRE(dsp::toNearestNote(dsp::Hertz<T>(T(440))) == dsp::Note{69});  // A4
    REQUIRE(dsp::toNearestNote(dsp::Hertz<T>(T(880))) == dsp::Note{81});  // A5

    REQUIRE(dsp::toNearestNote(dsp::Hertz<T>(T(32.703))) == dsp::Note{24});    // C1
    REQUIRE(dsp::toNearestNote(dsp::Hertz<T>(T(65.406))) == dsp::Note{36});    // C2
    REQUIRE(dsp::toNearestNote(dsp::Hertz<T>(T(130.8127))) == dsp::Note{48});  // C3
    REQUIRE(dsp::toNearestNote(dsp::Hertz<T>(T(261.6255))) == dsp::Note{60});  // C4
    REQUIRE(dsp::toNearestNote(dsp::Hertz<T>(T(523.251))) == dsp::Note{72});   // C5
}
