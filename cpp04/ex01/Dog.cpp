#include "Dog.hpp"

Dog::Dog() : brain(new Brain()) {
    type = "Dog";
    std::cout << "[Dog] Default constructor called." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "[Dog] Copy constructor called." << std::endl;
    type = other.type;
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << "[Dog] Copy assignment operator called." << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        if (brain)
            delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "[Dog] Destructor called." << std::endl;
}

void Dog::makeSound() const {
    std::cout << "[Dog] Woof! Woof!" << std::endl;
}
