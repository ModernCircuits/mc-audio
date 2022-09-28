// SPDX-License-Identifier: BSL-1.0

#include <mc/audio/music.hpp>

#include <catch2/catch_approx.hpp>
#include <catch2/catch_template_test_macros.hpp>

using namespace mc;

TEMPLATE_TEST_CASE("music: toHertz", "[music]", float, double)
{
    using T = TestType;

    static constexpr auto a1 = toHertz<T>(Note{33});
    REQUIRE(a1.count() == Catch::Approx(T(55)));  // A1

    REQUIRE(toHertz<T>(Note{33}).count() == Catch::Approx(T(55)));   // A1
    REQUIRE(toHertz<T>(Note{45}).count() == Catch::Approx(T(110)));  // A2
    REQUIRE(toHertz<T>(Note{57}).count() == Catch::Approx(T(220)));  // A3
    REQUIRE(toHertz<T>(Note{69}).count() == Catch::Approx(T(440)));  // A4
    REQUIRE(toHertz<T>(Note{81}).count() == Catch::Approx(T(880)));  // A5

    REQUIRE(toHertz<T>(Note{24}).count() == Catch::Approx(T(32.703)));    // C1
    REQUIRE(toHertz<T>(Note{36}).count() == Catch::Approx(T(65.406)));    // C2
    REQUIRE(toHertz<T>(Note{48}).count() == Catch::Approx(T(130.8127)));  // C3
    REQUIRE(toHertz<T>(Note{60}).count() == Catch::Approx(T(261.6255)));  // C4
    REQUIRE(toHertz<T>(Note{72}).count() == Catch::Approx(T(523.251)));   // C5
}
