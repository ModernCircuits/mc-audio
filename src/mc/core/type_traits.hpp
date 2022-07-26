// SPDX-License-Identifier: BSL-1.0

#pragma once

#include <type_traits>

namespace mc {
template<typename Enum>
[[nodiscard]] constexpr auto toUnderlying(Enum e) noexcept -> std::underlying_type_t<Enum>
{
    return static_cast<std::underlying_type_t<Enum>>(e);
}
}  // namespace mc
