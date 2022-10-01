// SPDX-License-Identifier: BSL-1.0

#include <mc/core/array.hpp>
#include <mc/music/chord.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("music/chord: isMinor", "[music]")
{
    using namespace mc;

    REQUIRE(isMinor(Array<Note, 2>{Note{60}, Note{63}}));
    REQUIRE(isMinor(Array<Note, 3>{Note{60}, Note{63}, Note{67}}));

    REQUIRE_FALSE(isMinor({}));
    REQUIRE_FALSE(isMinor(Array<Note, 2>{}));
    REQUIRE_FALSE(isMinor(Array<Note, 3>{}));
    REQUIRE_FALSE(isMinor(Array<Note, 3>{Note{60}, Note{63}, Note{66}}));
    REQUIRE_FALSE(isMinor(Array<Note, 3>{Note{60}, Note{60}, Note{60}}));
}
