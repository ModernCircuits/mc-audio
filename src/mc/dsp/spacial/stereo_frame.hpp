// SPDX-License-Identifier: BSL-1.0
#pragma once

namespace mc {
namespace dsp {
template<typename SampleType>
struct StereoFrame
{
    SampleType left{};
    SampleType right{};
};
}  // namespace dsp
}  // namespace mc
