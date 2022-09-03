// SPDX-License-Identifier: BSL-1.0

#pragma once

#include <mc/core/config.hpp>

#include <mc/dsp/music/note.hpp>
#include <mc/dsp/units/frequency.hpp>

#include <mc/core/span.hpp>

namespace mc {
namespace dsp {

/// \brief Get the frequency of a MIDI note.
/// \ingroup mc-dsp-music
/// \relates Note
template<typename T>
MC_NODISCARD constexpr auto toHertz(Note note) noexcept -> Hertz<T>;

}  // namespace dsp
}  // namespace mc

#include "to_hertz.cpp"  // NOLINT
