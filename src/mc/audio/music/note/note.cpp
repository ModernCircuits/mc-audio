// SPDX-License-Identifier: BSL-1.0

#pragma once

namespace mc {

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
    auto number = static_cast<std::uint8_t>(note);
    if (presentation == 'n') { return fmt::format_to(ctx.out(), "{}", number); }
    return fmt::format_to(ctx.out(), "{}", number);
}
