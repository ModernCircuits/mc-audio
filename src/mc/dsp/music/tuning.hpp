// SPDX-License-Identifier: BSL-1.0

#pragma once

#include <mc/dsp/units/frequency.hpp>

#include <mc/core/cmath.hpp>

namespace mc::dsp {

/// \brief Convert a tuning deviation in fractions of a bin per octave
/// to a reference pitch frequency relative to A440.
///
/// This is useful if you are working in a non-A440 tuning system to
/// determine the reference pitch frequency given a tuning offset and
/// assuming equal temperament. By default, 12 bins per octave are used.
///
/// This method is the inverse of  `tuningFromA4`.
///
/// \param tuning Tuning deviation from A440 in fractional bins per octave.
/// \param binPerOctave Number of bins per octave.
///
/// \return Reference frequency corresponding to A4.
///
/// \ingroup mc-dsp-music
template<typename T>
auto tuningToA4(T tuning, int binPerOctave = 12)
{
    return T{440} * pow(T{2}, tuning / static_cast<T>(binPerOctave));
}

/// \brief Convert a reference pitch frequency to a tuning estimation,
/// in fractions of a bin per octave.
///
/// This is useful for determining the tuning deviation relative to A440
/// of a given frequency, assuming equal temperament. By default, 12 bins
/// per octave are used.
///
/// This method is the inverse of `tuningToA4`.
///
/// \param a4 Reference frequency corresponding to A4.
/// \param binPerOctave Number of bins per octave.
///
/// \return Tuning deviation from A440 in (fractional) bins per octave.
///
/// \ingroup mc-dsp-music
template<typename T>
auto tuningFromA4(Frequency<T> a4, int binPerOctave = 12)
{
    return static_cast<T>(binPerOctave) * (log2(a4) - log2(T{440}));
}

}  // namespace mc::dsp
