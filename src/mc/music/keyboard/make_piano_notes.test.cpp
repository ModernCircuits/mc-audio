// SPDX-License-Identifier: BSL-1.0

#include <mc/music/keyboard/make_piano_notes.hpp>

#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

using namespace mc;

TEST_CASE("music/keyboard: makePianoNotes(size,lowest)", "[music]")
{
    auto const size  = GENERATE(as<size_t>{}, 55, 88);
    auto const notes = makePianoNotes(size, Note{21});
    REQUIRE(notes.size() == size);
    REQUIRE(notes[0] == Note{21});
}

TEST_CASE("music/keyboard: makePianoNotes<Size>(lowest)", "[music]")
{
    REQUIRE(makePianoNotes<55>(Note{21}).size() == 55);
    REQUIRE(makePianoNotes<55>(Note{21})[0] == Note{21});

    REQUIRE(makePianoNotes<88>(Note{21}).size() == 88);
    REQUIRE(makePianoNotes<88>(Note{21})[0] == Note{21});
}
