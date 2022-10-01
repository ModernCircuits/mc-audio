// SPDX-License-Identifier: BSL-1.0

#include <mc/music/note.hpp>

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

TEST_CASE("music/note: operator-(Note, Note)", "[music]")
{
    using namespace mc;

    REQUIRE(Note{69} - Note{69} == Semitones{0});
    REQUIRE(Note{33} - Note{32} == Semitones{1});
    REQUIRE(Note{81} - Note{69} == Semitones{12});
}

TEST_CASE("music/note: operator+(Note, Semitones)", "[music]")
{
    using namespace mc;

    REQUIRE(Note{69} + Semitones{0} == Note{69});
    REQUIRE(Note{31} + Semitones{1} == Note{32});
    REQUIRE(Note{69} + Semitones{12} == Note{81});
}

TEST_CASE("music/note: operator-(Note, Semitones)", "[music]")
{
    using namespace mc;

    REQUIRE(Note{69} - Semitones{0} == Note{69});
    REQUIRE(Note{31} - Semitones{1} == Note{30});
    REQUIRE(Note{69} - Semitones{12} == Note{57});
}
