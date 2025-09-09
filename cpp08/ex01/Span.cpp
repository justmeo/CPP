#include "Span.hpp"
#include <iostream>   // optional for debug

Span::Span() : _cap(0), _data() {}

Span::Span(unsigned int n) : _cap(n), _data() {
    _data.reserve(n);
}

Span::Span(Span const& other) : _cap(other._cap), _data(other._data) {}

Span& Span::operator=(Span const& other) {
    if (this != &other) {
        _cap  = other._cap;
        _data = other._data;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int value) {
    if (_data.size() >= _cap) {
        throw std::runtime_error("Span is at maximum capacity");
    }
    _data.push_back(value);
}

void Span::ensureAtLeastTwo() const {
    if (_data.size() < 2) {
        throw std::runtime_error("Span must contain at least 2 elements");
    }
}

unsigned int Span::shortestSpan() const {
    ensureAtLeastTwo();
    
    std::vector<int> sorted = _data;
    std::sort(sorted.begin(), sorted.end());
    
    unsigned int minSpan = static_cast<unsigned int>(sorted[1] - sorted[0]);
    for (std::size_t i = 2; i < sorted.size(); ++i) {
        unsigned int span = static_cast<unsigned int>(sorted[i] - sorted[i-1]);
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
}

unsigned int Span::longestSpan() const {
    ensureAtLeastTwo();
    
    std::vector<int>::const_iterator minIt = std::min_element(_data.begin(), _data.end());
    std::vector<int>::const_iterator maxIt = std::max_element(_data.begin(), _data.end());
    
    return static_cast<unsigned int>(*maxIt - *minIt);
}