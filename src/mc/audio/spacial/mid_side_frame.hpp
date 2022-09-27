// SPDX-License-Identifier: BSL-1.0
#pragma once

namespace mc::dsp {
template<typename SampleType>
struct MidSideFrame
{
    SampleType mid{};
    SampleType side{};
};
}  // namespace mc::dsp
