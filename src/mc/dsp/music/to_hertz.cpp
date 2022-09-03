// SPDX-License-Identifier: BSL-1.0

#pragma once

#include <mc/core/algorithm.hpp>
#include <mc/core/cmath.hpp>

namespace mc {
namespace dsp {

template<typename T>
constexpr auto toHertz(Note note) noexcept -> Hertz<T>
{
    auto ratio = std::pow(T{2}, static_cast<T>(static_cast<uint8_t>(note) - 69) / T{12});
    return Hertz<T>{T{440} * ratio};
}

}  // namespace dsp
}  // namespace mc
