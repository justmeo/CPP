#include "Zombie.hpp"

// Creates a zombie on the HEAP and returns its pointer.
Zombie* newZombie(std::string name) {
    Zombie* z = new Zombie(name);
    return z;
}
