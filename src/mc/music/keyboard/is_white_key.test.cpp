// SPDX-License-Identifier: BSL-1.0

#include <mc/music/keyboard/is_white_key.hpp>

#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

using namespace mc;

[[nodiscard]] static auto makeNote(int octave, int note) -> Note
{
    return Note{octave * 12 + note};
}

TEST_CASE("music/keyboard: isWhiteKey", "[music]")
{
    auto octave = GENERATE(0, 1, 2, 3, 4, 5, 6, 7);

    REQUIRE(isWhiteKey(makeNote(octave, 0)));   // C
    REQUIRE(isWhiteKey(makeNote(octave, 2)));   // D
    REQUIRE(isWhiteKey(makeNote(octave, 4)));   // E
    REQUIRE(isWhiteKey(makeNote(octave, 5)));   // F
    REQUIRE(isWhiteKey(makeNote(octave, 7)));   // G
    REQUIRE(isWhiteKey(makeNote(octave, 9)));   // A
    REQUIRE(isWhiteKey(makeNote(octave, 11)));  // B

    REQUIRE_FALSE(isWhiteKey(makeNote(octave, 1)));   // C#/Db
    REQUIRE_FALSE(isWhiteKey(makeNote(octave, 3)));   // D#/Eb
    REQUIRE_FALSE(isWhiteKey(makeNote(octave, 6)));   // F#/Gb
    REQUIRE_FALSE(isWhiteKey(makeNote(octave, 8)));   // G#/Ab
    REQUIRE_FALSE(isWhiteKey(makeNote(octave, 10)));  // A#/Bb
}
