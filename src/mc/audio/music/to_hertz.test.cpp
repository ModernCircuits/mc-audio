// SPDX-License-Identifier: BSL-1.0

#include <mc/audio/music.hpp>

#include <catch2/catch_approx.hpp>
#include <catch2/catch_template_test_macros.hpp>

namespace dsp = mc::dsp;

TEMPLATE_TEST_CASE("audio/music: toHertz", "[dsp][music]", float, double)
{
    using T = TestType;

    static constexpr auto a1 = dsp::toHertz<T>(dsp::Note{33});
    REQUIRE(a1.count() == Catch::Approx(T(55)));  // A1

    REQUIRE(dsp::toHertz<T>(dsp::Note{33}).count() == Catch::Approx(T(55)));   // A1
    REQUIRE(dsp::toHertz<T>(dsp::Note{45}).count() == Catch::Approx(T(110)));  // A2
    REQUIRE(dsp::toHertz<T>(dsp::Note{57}).count() == Catch::Approx(T(220)));  // A3
    REQUIRE(dsp::toHertz<T>(dsp::Note{69}).count() == Catch::Approx(T(440)));  // A4
    REQUIRE(dsp::toHertz<T>(dsp::Note{81}).count() == Catch::Approx(T(880)));  // A5

    REQUIRE(dsp::toHertz<T>(dsp::Note{24}).count() == Catch::Approx(T(32.703)));    // C1
    REQUIRE(dsp::toHertz<T>(dsp::Note{36}).count() == Catch::Approx(T(65.406)));    // C2
    REQUIRE(dsp::toHertz<T>(dsp::Note{48}).count() == Catch::Approx(T(130.8127)));  // C3
    REQUIRE(dsp::toHertz<T>(dsp::Note{60}).count() == Catch::Approx(T(261.6255)));  // C4
    REQUIRE(dsp::toHertz<T>(dsp::Note{72}).count() == Catch::Approx(T(523.251)));   // C5
}
