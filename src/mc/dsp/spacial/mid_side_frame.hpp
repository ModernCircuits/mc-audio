// SPDX-License-Identifier: BSL-1.0
#pragma once

namespace mc {
namespace dsp {
template<typename SampleType>
struct MidSideFrame
{
    SampleType mid{};
    SampleType side{};
};
}  // namespace dsp
}  // namespace mc
