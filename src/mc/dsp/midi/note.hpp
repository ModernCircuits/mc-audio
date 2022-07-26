// SPDX-License-Identifier: BSL-1.0

#pragma once

#include <mc/core/math.hpp>
#include <mc/core/span.hpp>
#include <mc/core/type_traits.hpp>
#include <mc/dsp/midi/frequency.hpp>

#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>

namespace mc::dsp {

enum struct MidiNote : uint8_t
{};

/// \brief Get the frequency of a MIDI note.
template<typename T>
auto toHertz(MidiNote note) -> Frequency<T>
{
    return T{440} * std::pow(T{2}, static_cast<T>(toUnderlying(note) - 69) / T{12});
}

/// \brief Get the frequency of MIDI notes.
template<typename T>
auto toHertz(Span<MidiNote const> notes, Span<Frequency<T>> out) -> void
{
    std::transform(begin(notes), end(notes), begin(out), toHertz<T>);
}

/// \brief Get MIDI note number for a given frequency
template<typename T>
auto toMidiNote(Frequency<T> frequency) -> MidiNote
{
    auto raw = T{12} * (std::log2(frequency) - std::log2(T{440})) + T{69};
    return static_cast<MidiNote>(std::round(raw));
}

/// \brief Get MIDI note numbers for given frequencies
template<typename T>
auto toMidiNote(Span<Frequency<T> const> freq, Span<MidiNote> out) -> void
{
    std::transform(begin(freq), end(freq), begin(out), toMidiNote<T>);
}

[[nodiscard]] constexpr auto isBlackMidiNote(MidiNote note) noexcept -> bool
{
    auto const noteNumber = static_cast<unsigned>(toUnderlying(note));
    return ((1U << (noteNumber % 12U)) & 0x054a) != 0U;
}

[[nodiscard]] constexpr auto isWhiteMidiNote(MidiNote note) noexcept -> bool
{
    return !isBlackMidiNote(note);
}

}  // namespace mc::dsp
