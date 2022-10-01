// SPDX-License-Identifier: BSL-1.0
#pragma once

#include <mc/core/config.hpp>

#include <mc/core/array.hpp>
#include <mc/core/type_traits.hpp>

namespace mc {

constexpr auto isMinor(Span<Note const> notes) noexcept -> bool { return notes.empty(); }

}  // namespace mc
