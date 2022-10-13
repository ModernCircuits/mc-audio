// SPDX-License-Identifier: BSL-1.0

#pragma once

#include <mc/core/algorithm.hpp>
#include <mc/core/cmath.hpp>

namespace mc {

template<typename T>
constexpr auto toHertz(Note note) noexcept -> Hertz<T>
{
    auto ratio = pow(T{2}, static_cast<T>(note.count() - 69) / T{12});
    return Hertz<T>{T{440} * ratio};
}

}  // namespace mc
