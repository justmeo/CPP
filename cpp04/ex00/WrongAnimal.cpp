#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "[WrongAnimal] Default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type) {
    std::cout << "[WrongAnimal] Copy constructor called." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    std::cout << "[WrongAnimal] Copy assignment operator called." << std::endl;
    if (this != &other)
        type = other.type;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "[WrongAnimal] Destructor called." << std::endl;
}

std::string WrongAnimal::getType() const {
    return type;
}

void WrongAnimal::makeSound() const {
    std::cout << "[WrongAnimal] * wrong animal sound *" << std::endl;
}
