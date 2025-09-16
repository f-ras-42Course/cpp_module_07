#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

// Template function to apply a function to each element of an array
template <typename T, typename Func>
void iter(T* arr, size_t len, Func func) {
	for (std::size_t i = 0; i < len; ++i)
		func(arr[i]);
}

// Overload for const arrays
template <typename T, typename Func>
void iter(const T* arr, size_t len, Func func) {
	for (std::size_t i = 0; i < len; ++i)
		func(arr[i]);
}
#endif
