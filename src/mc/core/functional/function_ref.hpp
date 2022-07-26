// SPDX-License-Identifier: BSL-1.0

#pragma once

#include <functional>
#include <memory>
#include <type_traits>
#include <utility>

namespace mc {

template<typename Signature>
class FunctionRef;

/// \brief Non-owning view of a callable.
///
/// - http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2019/p0792r4.html
/// - https://github.com/TartanLlama/function_ref
template<typename R, typename... Args>
class FunctionRef<R(Args...)>
{
private:
    using internal_signature_t = R (*)(void*, Args...);

    void* _obj{nullptr};
    internal_signature_t _callable{nullptr};

    template<typename F>
    inline static constexpr bool isInvocable = std::is_invocable_r_v<R, F&&, Args...>;

    template<typename F>
    using enableIfInvocable = std::enable_if_t<isInvocable<F>, int>;

    template<typename F>
    using enableIfInvocableAndNotFunctionRef
        = std::enable_if_t<!std::is_same_v<std::decay_t<F>, FunctionRef> && isInvocable<F>, int>;

public:
    /// \brief Constructs a FunctionRef referring to f.
    template<typename F, enableIfInvocableAndNotFunctionRef<F> = 0>
    FunctionRef(F&& f) noexcept
        : _obj(const_cast<void*>(reinterpret_cast<void const*>(addressof(f))))
        , _callable{
              +[](void* obj, Args... args) -> R {
                  auto* func = reinterpret_cast<std::add_pointer_t<F>>(obj);
                  return std::invoke(*func, std::forward<Args>(args)...);
              },
          }
    {}

    /// \brief Reassigns this FunctionRef to refer to f.
    template<typename F, enableIfInvocable<F> = 0>
    auto operator=(F&& f) noexcept -> FunctionRef&
    {
        _obj      = reinterpret_cast<void*>(addressof(f));
        _callable = +[](void* obj, Args... args) {
            auto* func = reinterpret_cast<std::add_pointer_t<F>>(obj);
            return std::invoke(*func, std::forward<Args>(args)...);
        };

        return *this;
    }

    FunctionRef(FunctionRef const& /*other*/) = default;

    auto operator=(FunctionRef const& /*other*/) -> FunctionRef& = default;

    /// Exchanges the values of `*this` and rhs.
    auto swap(FunctionRef& other) noexcept -> void
    {
        using std::swap;
        swap(_obj, other._obj);
        swap(_callable, other._callable);
    }

    /// Equivalent to return `invoke(f, std::forward<Args>(args)...);`, where f is the
    /// callable object referred to by `*this`, qualified with the same
    /// cv-qualifiers as the function type Signature.
    auto operator()(Args... args) const -> R { return _callable(_obj, std::forward<Args>(args)...); }
};

template<typename R, typename... Args>
FunctionRef(R (*)(Args...)) -> FunctionRef<R(Args...)>;

/// Exchanges the values of lhs and rhs. Equivalent to lhs.swap(rhs).
template<typename R, typename... Args>
auto swap(FunctionRef<R(Args...)>& lhs, FunctionRef<R(Args...)>& rhs) noexcept -> void
{
    lhs.swap(rhs);
}

}  // namespace mc