// SPDX-License-Identifier: BSL-1.0

#pragma once

#include <mc/dsp/svf/double_sampled.hpp>

#include <mc/core/type_traits.hpp>

namespace mc {
namespace dsp {
namespace svf {
struct DoubleSampledPeak : DoubleSampled<DoubleSampledPeak>
{
    auto output(Outputs const& s) -> float { return s.low - s.high; }
};
}  // namespace svf
}  // namespace dsp
}  // namespace mc
