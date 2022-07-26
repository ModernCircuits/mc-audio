// SPDX-License-Identifier: BSL-1.0

#pragma once

#include <span>

namespace mc {
inline constexpr auto DynamicExtent = std::dynamic_extent;
template<typename T, std::size_t Extent = DynamicExtent>
using Span = std::span<T, Extent>;
}  // namespace mc
