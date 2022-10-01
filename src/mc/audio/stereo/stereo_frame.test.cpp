// SPDX-License-Identifier: BSL-1.0

#include <mc/audio/stereo/stereo_frame.hpp>

#include <catch2/catch_template_test_macros.hpp>

using namespace mc;

TEMPLATE_TEST_CASE("audio/stereo: StereoFrame", "[stereo]", float, double)
{
    using T = TestType;
    STATIC_REQUIRE(std::is_same_v<typename StereoFrame<T>::SampleType, T>);
}

TEMPLATE_TEST_CASE("audio/stereo: operator+(StereoFrame)", "[stereo]", float, double)
{
    using T           = TestType;
    auto const result = StereoFrame<T>{T(1), T(2)} + T(1);
    REQUIRE(result.left == T(2));
    REQUIRE(result.right == T(3));
}

TEMPLATE_TEST_CASE("audio/stereo: operator-(StereoFrame)", "[stereo]", float, double)
{
    using T           = TestType;
    auto const result = StereoFrame<T>{T(1), T(2)} - T(1);
    REQUIRE(result.left == T(0));
    REQUIRE(result.right == T(1));
}

TEMPLATE_TEST_CASE("audio/stereo: operator*(StereoFrame)", "[stereo]", float, double)
{
    using T           = TestType;
    auto const result = StereoFrame<T>{T(1), T(2)} * T(2);
    REQUIRE(result.left == T(2));
    REQUIRE(result.right == T(4));
}

TEMPLATE_TEST_CASE("audio/stereo: operator/(StereoFrame)", "[stereo]", float, double)
{
    using T           = TestType;
    auto const result = StereoFrame<T>{T(1), T(2)} / T(2);
    REQUIRE(result.left == T(0.5));
    REQUIRE(result.right == T(1));
}

TEMPLATE_TEST_CASE("audio/stereo: operator+=(StereoFrame)", "[stereo]", float, double)
{
    using T     = TestType;
    auto result = StereoFrame<T>{T(1), T(2)};
    result += T(1);
    REQUIRE(result.left == T(2));
    REQUIRE(result.right == T(3));
}

TEMPLATE_TEST_CASE("audio/stereo: operator-=(StereoFrame)", "[stereo]", float, double)
{
    using T     = TestType;
    auto result = StereoFrame<T>{T(1), T(2)};
    result -= T(1);
    REQUIRE(result.left == T(0));
    REQUIRE(result.right == T(1));
}

TEMPLATE_TEST_CASE("audio/stereo: operator*=(StereoFrame)", "[stereo]", float, double)
{
    using T     = TestType;
    auto result = StereoFrame<T>{T(1), T(2)};
    result *= T(2);
    REQUIRE(result.left == T(2));
    REQUIRE(result.right == T(4));
}

TEMPLATE_TEST_CASE("audio/stereo: operator/=(StereoFrame)", "[stereo]", float, double)
{
    using T     = TestType;
    auto result = StereoFrame<T>{T(1), T(2)};
    result /= T(2);
    REQUIRE(result.left == T(0.5));
    REQUIRE(result.right == T(1));
}
