#include "iter.hpp"
#include <iostream>
#include <string>

void printInt(int const& x) {
    std::cout << x << " ";
}

void incrementInt(int& x) {
    ++x;
}

template <typename T>
void printElement(T const& x) {
    std::cout << x << " ";
}

template <typename T>
void printElementWrapper(T const& x) {
    printElement(x); // Call the templated function inside the wrapper
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    iter(arr, 5, printInt);
    std::cout << std::endl;

    iter(arr, 5, incrementInt);
    iter(arr, 5, printInt);
    std::cout << std::endl;

    std::string strArr[] = {"hello", "world", "!"};
    iter(strArr, 3, printElementWrapper<std::string>); // Use the wrapper function
    std::cout << std::endl;

    return 0;
}
