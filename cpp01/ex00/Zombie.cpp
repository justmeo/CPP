#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : _name(name) {
    // Optionally print a debug message or nothing at all
}

Zombie::~Zombie() {
    std::cout << _name << " is destroyed." << std::endl;
}

void Zombie::announce(void) const {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
