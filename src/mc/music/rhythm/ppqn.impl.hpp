// SPDX-License-Identifier: BSL-1.0
#pragma once

namespace mc {

constexpr PPQN::PPQN(double val, double reso) noexcept : _count{val}, _resolution{reso} {}

constexpr auto PPQN::count() const noexcept -> double { return _count; }

constexpr auto PPQN::resolution() const noexcept -> double { return _resolution; }

constexpr PPQN::operator double() const noexcept { return count(); }

constexpr auto toSeconds(PPQN const ppqn, double bpm) -> double
{
    auto const secondsPerBeat  = 60.0 / bpm;
    auto const secondsPerPulse = secondsPerBeat / ppqn.resolution();
    return secondsPerPulse * ppqn.count();
}

constexpr auto toSampleCount(PPQN const ppqn, double bpm, double sampleRate) -> double
{
    return toSeconds(ppqn, bpm) * sampleRate;
}

}  // namespace mc
