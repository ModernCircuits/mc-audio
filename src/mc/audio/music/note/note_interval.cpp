// SPDX-License-Identifier: BSL-1.0

#pragma once

namespace mc {

constexpr NoteInterval::NoteInterval(uint8_t val) noexcept : _val(val) {}

constexpr NoteInterval::operator uint8_t() const noexcept { return _val; }

constexpr auto NoteInterval::operator++() -> NoteInterval&
{
    ++_val;
    return *this;
}

constexpr auto NoteInterval::operator++(int) -> NoteInterval
{
    auto old = *this;
    ++_val;
    return old;
}

constexpr auto NoteInterval::operator--() -> NoteInterval&
{
    --_val;
    return *this;
}

constexpr auto NoteInterval::operator--(int) -> NoteInterval
{
    auto old = *this;
    --_val;
    return old;
}

constexpr auto operator==(NoteInterval lhs, NoteInterval rhs) -> bool
{
    return static_cast<uint8_t>(lhs) == static_cast<uint8_t>(rhs);
}

constexpr auto operator!=(NoteInterval lhs, NoteInterval rhs) -> bool
{
    return !(lhs == rhs);
}

constexpr auto operator<(NoteInterval lhs, NoteInterval rhs) -> bool
{
    return static_cast<uint8_t>(lhs) < static_cast<uint8_t>(rhs);
}

constexpr auto operator<=(NoteInterval lhs, NoteInterval rhs) -> bool
{
    return static_cast<uint8_t>(lhs) <= static_cast<uint8_t>(rhs);
}

constexpr auto operator>(NoteInterval lhs, NoteInterval rhs) -> bool
{
    return static_cast<uint8_t>(lhs) > static_cast<uint8_t>(rhs);
}

constexpr auto operator>=(NoteInterval lhs, NoteInterval rhs) -> bool
{
    return static_cast<uint8_t>(lhs) >= static_cast<uint8_t>(rhs);
}

}  // namespace mc
