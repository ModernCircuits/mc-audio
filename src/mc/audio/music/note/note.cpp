// SPDX-License-Identifier: BSL-1.0

#pragma once

namespace mc {

constexpr Note::Note(int note) noexcept : _val{static_cast<uint8_t>(note)} {}

constexpr auto Note::count() const noexcept -> int { return static_cast<int>(_val); }

constexpr Note::operator int() const noexcept { return count(); }

constexpr Note::operator uint8_t() const noexcept { return _val; }

constexpr auto operator++(Note& note) noexcept -> Note&
{
    note = Note{note.count() + 1};
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
    note = Note{note.count() - 1};
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
    return lhs.count() == rhs.count();
}

constexpr auto operator!=(Note lhs, Note rhs) noexcept -> bool { return !(lhs == rhs); }

constexpr auto operator<(Note lhs, Note rhs) noexcept -> bool
{
    return lhs.count() < rhs.count();
}

constexpr auto operator<=(Note lhs, Note rhs) noexcept -> bool
{
    return lhs.count() <= rhs.count();
}

constexpr auto operator>(Note lhs, Note rhs) noexcept -> bool
{
    return lhs.count() > rhs.count();
}

constexpr auto operator>=(Note lhs, Note rhs) noexcept -> bool
{
    return lhs.count() >= rhs.count();
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
    if (presentation == 'n') { return fmt::format_to(ctx.out(), "{}", note.count()); }
    return fmt::format_to(ctx.out(), "{}", note.count());
}
