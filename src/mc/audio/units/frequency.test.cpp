// SPDX-License-Identifier: BSL-1.0

#include <mc/audio/units/frequency.hpp>

#include <catch2/catch_approx.hpp>
#include <catch2/catch_template_test_macros.hpp>

using namespace mc;

TEMPLATE_TEST_CASE("audio/units: Frequency", "[units]", float, double)  // NOLINT
{
    using T = TestType;

    static constexpr auto const zero = Hertz<T>{T(0)};
    REQUIRE(zero.count() == T(0));
    REQUIRE(Kilohertz<T>{zero}.count() == T(0));

    static constexpr auto const kilo = Hertz<T>{T(1'000)};
    REQUIRE(kilo.count() == T(1'000));
    REQUIRE(frequencyCast<Kilohertz<T>>(kilo).count() == T(1));
}
