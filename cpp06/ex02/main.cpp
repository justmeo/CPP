#include "identify.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    std::srand(std::time(NULL));

    for (int i = 0; i < 5; ++i) {
        Base* base = generate();
        identify(base);
        identify(*base);
        delete base;
    }

    return 0;
}
