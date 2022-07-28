// SPDX-License-Identifier: BSL-1.0

#pragma once

#include <mc/dsp/svf/double_sampled.hpp>

#include <mc/core/type_traits.hpp>

namespace mc {
namespace dsp {
namespace svf {
struct DoubleSampledNotch : DoubleSampled<DoubleSampledNotch>
{
    auto output(Outputs const& s) -> float { return s.notch; }
};
}  // namespace svf
}  // namespace dsp
}  // namespace mc
