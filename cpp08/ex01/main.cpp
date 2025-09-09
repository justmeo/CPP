#include <iostream>
#include <vector>
#include "Span.hpp"

// Subject sample (should print 2 then 14):
/*
int main() {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}
*/

int main() {
    // 1) Reproduce the subject example above.
    std::cout << "=== Subject Example ===" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    } catch (std::exception const& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // 2) Add a large test with >= 10,000 numbers.
    std::cout << "\n=== Large Test (10,000 numbers) ===" << std::endl;
    try {
        Span largeSpan(10000);
        for (int i = 0; i < 10000; ++i) {
            largeSpan.addNumber(i * 2);
        }
        std::cout << "Size: " << largeSpan.size() << std::endl;
        std::cout << "Shortest span: " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << largeSpan.longestSpan() << std::endl;
    } catch (std::exception const& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // 3) Test iterator-range addNumber(first, last).
    std::cout << "\n=== Iterator Range Test ===" << std::endl;
    try {
        std::vector<int> nums;
        for (int i = 100; i < 110; ++i) {
            nums.push_back(i);
        }
        
        Span rangeSpan(15);
        rangeSpan.addNumber(nums.begin(), nums.end());
        std::cout << "Added " << rangeSpan.size() << " numbers via iterators" << std::endl;
        std::cout << "Shortest span: " << rangeSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << rangeSpan.longestSpan() << std::endl;
    } catch (std::exception const& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // 4) Test exceptions: overflow, and spans with < 2 elements.
    std::cout << "\n=== Exception Tests ===" << std::endl;
    
    // Test overflow
    try {
        Span small(2);
        small.addNumber(1);
        small.addNumber(2);
        small.addNumber(3); // should throw
    } catch (std::exception const& e) {
        std::cout << "Overflow caught: " << e.what() << std::endl;
    }
    
    // Test iterator overflow
    try {
        Span small2(3);
        std::vector<int> tooMany;
        for (int i = 0; i < 5; ++i) {
            tooMany.push_back(i);
        }
        small2.addNumber(tooMany.begin(), tooMany.end()); // should throw
    } catch (std::exception const& e) {
        std::cout << "Iterator overflow caught: " << e.what() << std::endl;
    }
    
    // Test spans with < 2 elements
    try {
        Span empty(5);
        empty.shortestSpan(); // should throw
    } catch (std::exception const& e) {
        std::cout << "Empty span caught: " << e.what() << std::endl;
    }
    
    try {
        Span single(5);
        single.addNumber(42);
        single.longestSpan(); // should throw
    } catch (std::exception const& e) {
        std::cout << "Single element span caught: " << e.what() << std::endl;
    }

    return 0;
}