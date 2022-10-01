// SPDX-License-Identifier: BSL-1.0

#pragma once

namespace mc {

constexpr Note::Note(uint8_t note) noexcept : _val(note) {}

constexpr Note::operator uint8_t() const noexcept { return _val; }

constexpr Note::operator int() const noexcept { return static_cast<int>(_val); }

constexpr auto operator++(Note& note) noexcept -> Note&
{
    note = Note{static_cast<uint8_t>(static_cast<int>(note) + 1)};
    return note;
}

constexpr auto operator++(Note& note, int) noexcept -> Note
{
    auto old = note;
    ++note;
    return old;
}

constexpr auto operator--(Note& note) noexcept -> Note&
{
    note = Note{static_cast<uint8_t>(static_cast<int>(note) - 1)};
    return note;
}

constexpr auto operator--(Note& note, int) noexcept -> Note
{
    auto old = note;
    --note;
    return old;
}

constexpr auto operator==(Note lhs, Note rhs) noexcept -> bool
{
    return static_cast<int>(lhs) == static_cast<int>(rhs);
}

constexpr auto operator!=(Note lhs, Note rhs) noexcept -> bool { return !(lhs == rhs); }

constexpr auto operator<(Note lhs, Note rhs) noexcept -> bool
{
    return static_cast<int>(lhs) < static_cast<int>(rhs);
}

constexpr auto operator<=(Note lhs, Note rhs) noexcept -> bool
{
    return static_cast<int>(lhs) <= static_cast<int>(rhs);
}

constexpr auto operator>(Note lhs, Note rhs) noexcept -> bool
{
    return static_cast<int>(lhs) > static_cast<int>(rhs);
}

constexpr auto operator>=(Note lhs, Note rhs) noexcept -> bool
{
    return static_cast<int>(lhs) >= static_cast<int>(rhs);
}

}  // namespace mc

constexpr auto fmt::formatter<mc::Note>::parse(format_parse_context& ctx)
    -> decltype(ctx.begin())
{
    auto it  = ctx.begin();
    auto end = ctx.end();
    if (it != end && (*it == 'n' || *it == 'h')) { presentation = *it++; }
    if (it != end && *it != '}') { throw format_error("invalid format"); }
    return it;
}

template<typename FormatContext>
auto fmt::formatter<mc::Note>::format(mc::Note const& note, FormatContext& ctx) const
    -> decltype(ctx.out())
{
    auto number = static_cast<int>(note);
    if (presentation == 'n') { return fmt::format_to(ctx.out(), "{}", number); }
    return fmt::format_to(ctx.out(), "{}", number);
}
