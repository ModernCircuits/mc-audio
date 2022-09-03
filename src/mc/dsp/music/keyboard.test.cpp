// SPDX-License-Identifier: BSL-1.0

#include <mc/dsp/music.hpp>

#include <catch2/catch_test_macros.hpp>

namespace dsp = mc::dsp;

TEST_CASE("dsp/music: isBlackKey", "[dsp][music]")
{
    REQUIRE(dsp::isBlackKey(dsp::Note{25}));  // C#1/Db1
    REQUIRE(dsp::isBlackKey(dsp::Note{27}));  // D#1/Eb1
    REQUIRE(dsp::isBlackKey(dsp::Note{27}));  // D#1/Eb1
    REQUIRE(dsp::isBlackKey(dsp::Note{30}));  // F#1/Gb1
    REQUIRE(dsp::isBlackKey(dsp::Note{32}));  // G#1/Ab1
    REQUIRE(dsp::isBlackKey(dsp::Note{34}));  // A#1/Bb1

    REQUIRE_FALSE(dsp::isBlackKey(dsp::Note{24}));  // C1
    REQUIRE_FALSE(dsp::isBlackKey(dsp::Note{26}));  // D1
    REQUIRE_FALSE(dsp::isBlackKey(dsp::Note{28}));  // E1
    REQUIRE_FALSE(dsp::isBlackKey(dsp::Note{29}));  // F1
    REQUIRE_FALSE(dsp::isBlackKey(dsp::Note{31}));  // G1
    REQUIRE_FALSE(dsp::isBlackKey(dsp::Note{33}));  // A1
}

TEST_CASE("dsp/music: isWhiteKey", "[dsp][music]")
{
    REQUIRE(dsp::isWhiteKey(dsp::Note{24}));  // C1
    REQUIRE(dsp::isWhiteKey(dsp::Note{26}));  // D1
    REQUIRE(dsp::isWhiteKey(dsp::Note{28}));  // E1
    REQUIRE(dsp::isWhiteKey(dsp::Note{29}));  // F1
    REQUIRE(dsp::isWhiteKey(dsp::Note{31}));  // G1
    REQUIRE(dsp::isWhiteKey(dsp::Note{33}));  // A1

    REQUIRE_FALSE(dsp::isWhiteKey(dsp::Note{25}));  // C#1/Db1
    REQUIRE_FALSE(dsp::isWhiteKey(dsp::Note{27}));  // D#1/Eb1
    REQUIRE_FALSE(dsp::isWhiteKey(dsp::Note{27}));  // D#1/Eb1
    REQUIRE_FALSE(dsp::isWhiteKey(dsp::Note{30}));  // F#1/Gb1
    REQUIRE_FALSE(dsp::isWhiteKey(dsp::Note{32}));  // G#1/Ab1
    REQUIRE_FALSE(dsp::isWhiteKey(dsp::Note{34}));  // A#1/Bb1
}
