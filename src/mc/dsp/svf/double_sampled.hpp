// SPDX-License-Identifier: BSL-1.0

#pragma once

/// \defgroup mc-dsp-units Units
/// Unit value types provided by the library.
/// \ingroup mc-dsp

#include <mc/dsp/units/frequency.hpp>

#include <mc/core/algorithm.hpp>
#include <mc/core/cmath.hpp>
#include <mc/core/functional.hpp>
#include <mc/core/numbers.hpp>
#include <mc/core/span.hpp>

namespace mc {
namespace dsp {
namespace svf {

// https://www.musicdsp.org/en/latest/Filters/92-state-variable-filter-double-sampled-stable.html
template<typename Derived>
struct DoubleSampled
{
    struct Outputs
    {
        float notch{0.0F};
        float low{0.0F};
        float high{0.0F};
        float band{0.0F};
    };

    DoubleSampled() = default;

    auto parameter(float fc, float q, float drive, float fs) noexcept -> void;
    auto operator()(float in) noexcept -> float;

private:
    auto processInternal(Outputs outs, float in) noexcept -> Outputs;
    Outputs _state{};

    float _drive{};
    float _damp{};
    float _freq{};
};

template<typename Derived>
inline auto
DoubleSampled<Derived>::parameter(float fc, float q, float drive, float fs) noexcept -> void
{
    auto const pi = (float)numbers::pi;

    // the fs*2 is because it's double sampled
    _freq = 2.0f * sin(pi * std::min(0.25f, fc / (fs * 2.0f)));
    _damp = std::min(
        2.0f * (1.0f - pow(q, 0.25f)),
        std::min(2.0f, 2.0f / _freq - _freq * 0.5f)
    );
    _drive = drive;
}

template<typename Derived>
inline auto DoubleSampled<Derived>::operator()(float in) noexcept -> float
{
    _state = processInternal(_state, in);
    return static_cast<Derived*>(this)->output(_state);
}

template<typename Derived>
inline auto DoubleSampled<Derived>::processInternal(Outputs o, float in) noexcept -> Outputs
{
    o.notch = in - _damp * o.band;
    o.high  = o.notch - o.low;
    o.band  = _freq * o.high + o.band - _drive * o.band * o.band * o.band;
    o.low   = o.low + _freq * o.band;

    o.notch *= 0.5f;
    o.high *= 0.5f;
    o.band *= 0.5f;
    o.low *= 0.5f;

    auto notch = in - _damp * o.band;
    auto low   = o.low + _freq * o.band;
    auto high  = o.notch - o.low;
    auto band  = _freq * o.high + o.band - _drive * o.band * o.band * o.band;

    o.notch += (0.5f * notch);
    o.high += (0.5f * high);
    o.band += (0.5f * band);
    o.low += (0.5f * low);

    return o;
}

}  // namespace svf
}  // namespace dsp
}  // namespace mc
