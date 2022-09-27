// SPDX-License-Identifier: BSL-1.0

#include <mc/audio/units/decibel.hpp>

#include <catch2/catch_approx.hpp>
#include <catch2/catch_template_test_macros.hpp>

using namespace mc;

template<typename T>
static constexpr auto zeroDB = Decibel<T>{0};

TEMPLATE_TEST_CASE("audio/units: toDecibel", "[audio][units]", float, double)
{
    using T = TestType;
    STATIC_REQUIRE(toDecibel(T(1.0)).count() == T(0));

    REQUIRE(toDecibel(T(1.0)).count() == Catch::Approx(T(0)));
    REQUIRE(toDecibel(T(0.5)).count() == Catch::Approx(T(-6.02059)));
    REQUIRE(toDecibel(T(0.25)).count() == Catch::Approx(T(-12.04119)));
}

TEMPLATE_TEST_CASE("audio/units: toGain", "[audio][units]", float, double)
{
    using T = TestType;

    STATIC_REQUIRE(toGain(zeroDB<T>) == T(1));

    REQUIRE(toGain(zeroDB<T>) == Catch::Approx(T(1.0)));
    REQUIRE(toGain(Decibel{T(-6.02059)}) == Catch::Approx(T(0.5)));
    REQUIRE(toGain(Decibel{T(-12.04119)}) == Catch::Approx(T(0.25)));
}

TEMPLATE_TEST_CASE("audio/units: compare(Decibel,Decibel)", "[audio][units]", float, double)
{
    using T = TestType;
    STATIC_REQUIRE(zeroDB<T> == zeroDB<T>);
    STATIC_REQUIRE(zeroDB<T> != Decibel{T(1)});
    STATIC_REQUIRE(zeroDB<T> < Decibel{T(1)});
    STATIC_REQUIRE(zeroDB<T> <= Decibel{T(1)});
    STATIC_REQUIRE_FALSE(zeroDB<T> > Decibel{T(1)});
    STATIC_REQUIRE_FALSE(zeroDB<T> >= Decibel{T(1)});
}
