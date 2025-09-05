#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template <typename T>
class Array {
private:
    T*        _data;
    unsigned  _size;

public:
    Array() : _data(0), _size(0) {}
    explicit Array(unsigned n) : _data(n ? new T[n]() : 0), _size(n) {}
    Array(Array const& other) : _data(0), _size(other._size) {
        if (_size) {
            _data = new T[_size];
            for (unsigned i = 0; i < _size; ++i) _data[i] = other._data[i];
        }
    }
    Array& operator=(Array const& other) {
        if (this != &other) {
            T* newData = (other._size ? new T[other._size] : 0);
            for (unsigned i = 0; i < other._size; ++i) newData[i] = other._data[i];
            delete[] _data;
            _data = newData;
            _size = other._size;
        }
        return *this;
    }
    ~Array() { delete[] _data; }

    unsigned size() const { return _size; }

    T& operator[](unsigned i) {
        if (i >= _size) throw std::out_of_range("Array index out of range");
        return _data[i];
    }

    T const& operator[](unsigned i) const {
        if (i >= _size) throw std::out_of_range("Array index out of range");
        return _data[i];
    }
};

#endif
