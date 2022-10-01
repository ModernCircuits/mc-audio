// SPDX-License-Identifier: BSL-1.0

#include <mc/audio/music.hpp>

#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

using namespace mc;

[[nodiscard]] static auto makeNote(int octave, int note) -> Note
{
    return Note{static_cast<uint8_t>(octave * 12 + note)};
}

TEST_CASE("music: isBlackKey", "[music]")
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

TEST_CASE("music: isWhiteKey", "[music]")
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
