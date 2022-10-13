// SPDX-License-Identifier: BSL-1.0
#pragma once

namespace mc {

struct PPQN
{
    constexpr PPQN() = default;
    explicit constexpr PPQN(double val, double reso) noexcept;

    [[nodiscard]] constexpr auto count() const noexcept -> double;
    [[nodiscard]] constexpr auto resolution() const noexcept -> double;
    [[nodiscard]] constexpr explicit operator double() const noexcept;

private:
    double _count{0.0};
    double _resolution{0.0};
};

[[nodiscard]] constexpr auto toSeconds(PPQN ppqn, double bpm) -> double;
[[nodiscard]] constexpr auto toSampleCount(PPQN ppqn, double bpm, double sampleRate)
    -> double;

}  // namespace mc

#include "ppqn.impl.hpp"
