// SPDX-License-Identifier: BSL-1.0

#include <mc/music/chord.hpp>

#include <mc/core/array.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("music/chord: isMajor", "[music]")
{
    using namespace mc;

    REQUIRE(isMajor(Array<Note, 2>{Note{60}, Note{63}}));  // TODO(tobi): Fixme maybe?
    REQUIRE(isMajor(Array<Note, 3>{Note{60}, Note{64}, Note{67}}));

    REQUIRE_FALSE(isMajor({}));
    REQUIRE_FALSE(isMajor(Array<Note, 2>{}));
    REQUIRE_FALSE(isMajor(Array<Note, 3>{}));
    REQUIRE_FALSE(isMajor(Array<Note, 3>{Note{60}, Note{64}, Note{66}}));
    REQUIRE_FALSE(isMajor(Array<Note, 3>{Note{60}, Note{60}, Note{60}}));
}
