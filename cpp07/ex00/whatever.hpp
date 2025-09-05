#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T& a, T& b) {
    T tmp = a; a = b; b = tmp;
}

template <typename T>
T const& min(T const& a, T const& b) {
    return (b <= a) ? b : a; // returns second when equal
}

template <typename T>
T const& max(T const& a, T const& b) {
    return (b >= a) ? b : a; // returns second when equal
}

#endif
