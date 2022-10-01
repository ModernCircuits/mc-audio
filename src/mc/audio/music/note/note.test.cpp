// SPDX-License-Identifier: BSL-1.0

#include <mc/audio/music/note.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("music/note: compare(Note)", "[music]")
{
    using namespace mc;
    REQUIRE(Note{33} == Note{33});
    REQUIRE(Note{33} != Note{34});
    REQUIRE(Note{33} < Note{34});
    REQUIRE(Note{33} <= Note{34});
    REQUIRE_FALSE(Note{33} > Note{34});
    REQUIRE_FALSE(Note{33} >= Note{34});
}

TEST_CASE("music/note: operator++(Note)", "[music]")
{
    using namespace mc;

    auto note = Note{33};
    REQUIRE(note == Note{33});

    ++note;
    REQUIRE(note == Note{34});

    note++;
    REQUIRE(note == Note{35});
}

TEST_CASE("music/note: operator--(Note)", "[music]")
{
    using namespace mc;

    auto note = Note{33};
    REQUIRE(note == Note{33});

    --note;
    REQUIRE(note == Note{32});

    note--;
    REQUIRE(note == Note{31});
}
