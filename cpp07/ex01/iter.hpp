#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> // size_t

template <typename T, typename F>
void iter(T* array, std::size_t len, F func) {
    if (!array) return;
    for (std::size_t i = 0; i < len; ++i)
        func(array[i]);
}

template <typename T, typename F>
void iter(T const* array, std::size_t len, F func) {
    if (!array) return;
    for (std::size_t i = 0; i < len; ++i)
        func(array[i]);
}

#endif
