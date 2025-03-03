#include "Cat.hpp"

Cat::Cat() : brain(new Brain()) {
    type = "Cat";
    std::cout << "[Cat] Default constructor called." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "[Cat] Copy constructor called." << std::endl;
    type = other.type;
}

Cat &Cat::operator=(const Cat &other) {
    std::cout << "[Cat] Copy assignment operator called." << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        if (brain)
            delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "[Cat] Destructor called." << std::endl;
}

void Cat::makeSound() const {
    std::cout << "[Cat] Meow! Meow!" << std::endl;
}
