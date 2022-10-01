// SPDX-License-Identifier: BSL-1.0

#include <mc/audio/music/keyboard/is_black_key.hpp>

#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

using namespace mc;

[[nodiscard]] static auto makeNote(int octave, int note) -> Note
{
    return Note{octave * 12 + note};
}

TEST_CASE("music/keyboard: isBlackKey", "[music]")
{
    auto octave = GENERATE(0, 1, 2, 3, 4, 5, 6, 7);

    REQUIRE(isBlackKey(makeNote(octave, 1)));   // C#/Db
    REQUIRE(isBlackKey(makeNote(octave, 3)));   // D#/Eb
    REQUIRE(isBlackKey(makeNote(octave, 6)));   // F#/Gb
    REQUIRE(isBlackKey(makeNote(octave, 8)));   // G#/Ab
    REQUIRE(isBlackKey(makeNote(octave, 10)));  // A#/Bb

    REQUIRE_FALSE(isBlackKey(makeNote(octave, 0)));   // C
    REQUIRE_FALSE(isBlackKey(makeNote(octave, 2)));   // D
    REQUIRE_FALSE(isBlackKey(makeNote(octave, 4)));   // E
    REQUIRE_FALSE(isBlackKey(makeNote(octave, 5)));   // F
    REQUIRE_FALSE(isBlackKey(makeNote(octave, 7)));   // G
    REQUIRE_FALSE(isBlackKey(makeNote(octave, 9)));   // A
    REQUIRE_FALSE(isBlackKey(makeNote(octave, 11)));  // B
}
