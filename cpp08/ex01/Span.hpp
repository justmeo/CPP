#ifndef SPAN_HPP
#define SPAN_HPP

// Subject highlights:
// - Store max N integers (N passed to ctor).
// - addNumber(int)
// - shortestSpan() and longestSpan() throw if < 2 elements
// - Add a member to add a range via iterators (thousands of numbers).
// - Use STL containers/algorithms appropriately.
// - Orthodox Canonical Form (Module 02–09).

#include <vector>
#include <stdexcept>
#include <algorithm> // sort, min_element, etc.
#include <limits>    // numeric_limits
#include <cstdlib>   // size_t
#include <iterator>  // iterator_traits

class Span {
public:
    // Orthodox Canonical Form
    Span();
    explicit Span(unsigned int n);
    Span(Span const& other);
    Span& operator=(Span const& other);
    ~Span();

    // Core API
    void addNumber(int value);

    // Iterator-range bulk insert (templated; keep in header)
    template <typename InputIt>
    void addNumber(InputIt first, InputIt last) {
        typename std::iterator_traits<InputIt>::difference_type count = std::distance(first, last);
        if (_data.size() + count > _cap) {
            throw std::runtime_error("Span capacity would be exceeded");
        }
        _data.insert(_data.end(), first, last);
    }

    unsigned int shortestSpan() const; // throws if size < 2
    unsigned int longestSpan()  const; // throws if size < 2

    // Optional: helpers for testing
    std::size_t size() const { return _data.size(); }
    std::size_t capacity() const { return static_cast<std::size_t>(_cap); }

private:
    unsigned int   _cap;
    std::vector<int> _data;

    // Optional: validate enough elements
    void ensureAtLeastTwo() const;
};

#endif // SPAN_HPP