#ifndef EASYFIND_HPP
#define EASYFIND_HPP

// Subject: "Write a function template easyfind that accepts a type T.
// Assuming T is a container of integers, find the first occurrence of an int.
// If not found: either throw an exception or return an error value."
// Use STL algorithms & iterators (Module 08 allows them). No `using namespace`.

#include <algorithm> // std::find
#include <stdexcept> // std::runtime_error

// Non-const version returns iterator
template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::runtime_error("value not found");
    }
    return it;
}

// Const version returns const_iterator
template <typename T>
typename T::const_iterator easyfind(T const& container, int value) {
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::runtime_error("value not found");
    }
    return it;
}

#endif // EASYFIND_HPP