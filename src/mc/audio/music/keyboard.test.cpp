// SPDX-License-Identifier: BSL-1.0

#include <mc/audio/music.hpp>

#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

namespace dsp = mc::dsp;

static auto makeNote(int octave, int note) -> dsp::Note
{
    return dsp::Note{static_cast<uint8_t>(octave * 12 + note)};
}

TEST_CASE("audio/music: isBlackKey", "[dsp][music]")
{
    auto octave = GENERATE(0, 1, 2, 3, 4, 5, 6, 7);

    REQUIRE(dsp::isBlackKey(makeNote(octave, 1)));   // C#/Db
    REQUIRE(dsp::isBlackKey(makeNote(octave, 3)));   // D#/Eb
    REQUIRE(dsp::isBlackKey(makeNote(octave, 6)));   // F#/Gb
    REQUIRE(dsp::isBlackKey(makeNote(octave, 8)));   // G#/Ab
    REQUIRE(dsp::isBlackKey(makeNote(octave, 10)));  // A#/Bb

    REQUIRE_FALSE(dsp::isBlackKey(makeNote(octave, 0)));   // C
    REQUIRE_FALSE(dsp::isBlackKey(makeNote(octave, 2)));   // D
    REQUIRE_FALSE(dsp::isBlackKey(makeNote(octave, 4)));   // E
    REQUIRE_FALSE(dsp::isBlackKey(makeNote(octave, 5)));   // F
    REQUIRE_FALSE(dsp::isBlackKey(makeNote(octave, 7)));   // G
    REQUIRE_FALSE(dsp::isBlackKey(makeNote(octave, 9)));   // A
    REQUIRE_FALSE(dsp::isBlackKey(makeNote(octave, 11)));  // B
}

TEST_CASE("audio/music: isWhiteKey", "[dsp][music]")
{
    auto octave = GENERATE(0, 1, 2, 3, 4, 5, 6, 7);

    REQUIRE(dsp::isWhiteKey(makeNote(octave, 0)));   // C
    REQUIRE(dsp::isWhiteKey(makeNote(octave, 2)));   // D
    REQUIRE(dsp::isWhiteKey(makeNote(octave, 4)));   // E
    REQUIRE(dsp::isWhiteKey(makeNote(octave, 5)));   // F
    REQUIRE(dsp::isWhiteKey(makeNote(octave, 7)));   // G
    REQUIRE(dsp::isWhiteKey(makeNote(octave, 9)));   // A
    REQUIRE(dsp::isWhiteKey(makeNote(octave, 11)));  // B

    REQUIRE_FALSE(dsp::isWhiteKey(makeNote(octave, 1)));   // C#/Db
    REQUIRE_FALSE(dsp::isWhiteKey(makeNote(octave, 3)));   // D#/Eb
    REQUIRE_FALSE(dsp::isWhiteKey(makeNote(octave, 6)));   // F#/Gb
    REQUIRE_FALSE(dsp::isWhiteKey(makeNote(octave, 8)));   // G#/Ab
    REQUIRE_FALSE(dsp::isWhiteKey(makeNote(octave, 10)));  // A#/Bb
}
