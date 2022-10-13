// SPDX-License-Identifier: BSL-1.0

#include <mc/music/rhythm/ppqn.hpp>

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("music/rhythm: toSeconds(PPQN)", "[music]")  // NOLINT
{
    using namespace mc;

    REQUIRE(toSeconds(PPQN{0.0, 480}, 120.0) == Catch::Approx(0.0));
    REQUIRE(toSeconds(PPQN{120.0, 480}, 120.0) == Catch::Approx(0.125));
    REQUIRE(toSeconds(PPQN{240.0, 480}, 120.0) == Catch::Approx(0.25));

    REQUIRE(toSeconds(PPQN{0.0, 480}, 60.0) == Catch::Approx(0.0));
    REQUIRE(toSeconds(PPQN{120.0, 480}, 60.0) == Catch::Approx(0.25));
    REQUIRE(toSeconds(PPQN{240.0, 480}, 60.0) == Catch::Approx(0.5));
    REQUIRE(toSeconds(PPQN{480.0, 480}, 60.0) == Catch::Approx(1.0));
}

TEST_CASE("music/rhythm: toSampleCount(PPQN)", "[music]")  // NOLINT
{
    using namespace mc;

    REQUIRE(toSampleCount(PPQN{0.0, 480}, 120.0, 44'100.0) == Catch::Approx(0.0));
    REQUIRE(toSampleCount(PPQN{120.0, 480}, 120.0, 44'100.0) == Catch::Approx(5512.5));
    REQUIRE(toSampleCount(PPQN{240.0, 480}, 120.0, 44'100.0) == Catch::Approx(11'025.0));

    REQUIRE(toSampleCount(PPQN{0.0, 480}, 60.0, 44'100.0) == Catch::Approx(0.0));
    REQUIRE(toSampleCount(PPQN{120.0, 480}, 60.0, 44'100.0) == Catch::Approx(11'025.0));
    REQUIRE(toSampleCount(PPQN{240.0, 480}, 60.0, 44'100.0) == Catch::Approx(22'050.0));
    REQUIRE(toSampleCount(PPQN{480.0, 480}, 60.0, 44'100.0) == Catch::Approx(44'100.0));
}
