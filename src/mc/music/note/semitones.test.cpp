// SPDX-License-Identifier: BSL-1.0

#include <mc/music/note.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("music/note: compare(Semitones)", "[music]")
{
    using namespace mc;
    REQUIRE(Semitones{1} == Semitones{1});
    REQUIRE(Semitones{1} != Semitones{2});
    REQUIRE(Semitones{1} < Semitones{2});
    REQUIRE(Semitones{1} <= Semitones{2});
    REQUIRE_FALSE(Semitones{1} > Semitones{2});
    REQUIRE_FALSE(Semitones{1} >= Semitones{2});
}

TEST_CASE("music/note: operator++(Semitones)", "[music]")
{
    using namespace mc;

    auto note = Semitones{1};
    REQUIRE(note == Semitones{1});

    ++note;
    REQUIRE(note == Semitones{2});

    note++;
    REQUIRE(note == Semitones{3});
}

TEST_CASE("music/note: operator--(Semitones)", "[music]")
{
    using namespace mc;

    auto note = Semitones{4};
    REQUIRE(note == Semitones{4});

    --note;
    REQUIRE(note == Semitones{3});

    note--;
    REQUIRE(note == Semitones{2});
}
