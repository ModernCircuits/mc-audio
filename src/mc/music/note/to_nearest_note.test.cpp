// SPDX-License-Identifier: BSL-1.0

#include <mc/audio/units.hpp>

#include <mc/music.hpp>

#include <catch2/catch_template_test_macros.hpp>

using namespace mc;

static_assert(Hertz<float>{440.0F}.count() == 440.0F);

TEMPLATE_TEST_CASE("music/note: toNearestNote", "[music]", float, double)
{
    using T = TestType;
    REQUIRE(toNearestNote(Hertz<T>(T(55))) == Note{33});   // A1
    REQUIRE(toNearestNote(Hertz<T>(T(110))) == Note{45});  // A2
    REQUIRE(toNearestNote(Hertz<T>(T(220))) == Note{57});  // A3
    REQUIRE(toNearestNote(Hertz<T>(T(440))) == Note{69});  // A4
    REQUIRE(toNearestNote(Hertz<T>(T(880))) == Note{81});  // A5

    REQUIRE(toNearestNote(Hertz<T>(T(32.703))) == Note{24});    // C1
    REQUIRE(toNearestNote(Hertz<T>(T(65.406))) == Note{36});    // C2
    REQUIRE(toNearestNote(Hertz<T>(T(130.8127))) == Note{48});  // C3
    REQUIRE(toNearestNote(Hertz<T>(T(261.6255))) == Note{60});  // C4
    REQUIRE(toNearestNote(Hertz<T>(T(523.251))) == Note{72});   // C5
}
