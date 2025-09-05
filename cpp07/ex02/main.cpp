#include "Array.hpp"
#include <iostream>
#include <string>

int main() {
    Array<int> a;
    std::cout << "Size of a: " << a.size() << std::endl;

    Array<int> b(5);
    for (unsigned i = 0; i < b.size(); ++i) b[i] = i * 2;
    for (unsigned i = 0; i < b.size(); ++i) std::cout << b[i] << " ";
    std::cout << std::endl;

    Array<int> c = b;
    b[0] = 99;
    std::cout << "c[0]: " << c[0] << ", b[0]: " << b[0] << std::endl;

    Array<std::string> d(3);
    d[0] = "Hello";
    d[1] = "World";
    d[2] = "!";
    for (unsigned i = 0; i < d.size(); ++i) std::cout << d[i] << " ";
    std::cout << std::endl;

    try {
        std::cout << b[10] << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
