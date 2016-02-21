#pragma once
#include <type_traits>

namespace python_like {
inline namespace v1 {

struct in_ {};
in_ in;
struct not_in_ {};
not_in_ not_in;

template <typename T, bool IsIn>
struct wrapper {
	wrapper(T&& t) : t_(std::forward<T>(t)) {}
	T t_;
};

template <typename T, typename InType, std::enable_if_t<std::is_same<InType, in_>::value || std::is_same<InType, not_in_>::value>* = 0>
auto operator<(T&& t, InType const& in) {
	return wrapper<T, std::is_same<InType, in_>::value>{std::forward<T>(t)};
}

template <typename T, bool IsIn, typename Container>
auto operator>(wrapper<T, IsIn> const& wrapper, Container const& container) {
	return (std::find(std::begin(container), std::end(container), wrapper.t_) != std::end(container)) == IsIn;
}
}
}