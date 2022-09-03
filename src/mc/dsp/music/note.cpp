// SPDX-License-Identifier: BSL-1.0

#pragma once

namespace mc {
namespace dsp {

constexpr Note::Note(uint8_t note) noexcept : _note(note) {}

constexpr Note::operator uint8_t() const noexcept { return _note; }

constexpr auto Note::operator++() noexcept -> Note&
{
    ++_note;
    return *this;
}

constexpr auto Note::operator++(int) noexcept -> Note
{
    auto old = *this;
    ++_note;
    return old;
}

constexpr auto Note::operator--() noexcept -> Note&
{
    --_note;
    return *this;
}

constexpr auto Note::operator--(int) noexcept -> Note
{
    auto old = *this;
    --_note;
    return old;
}

constexpr auto operator==(Note lhs, Note rhs) noexcept -> bool
{
    return static_cast<uint8_t>(lhs) == static_cast<uint8_t>(rhs);
}

constexpr auto operator!=(Note lhs, Note rhs) noexcept -> bool { return !(lhs == rhs); }

}  // namespace dsp
}  // namespace mc
