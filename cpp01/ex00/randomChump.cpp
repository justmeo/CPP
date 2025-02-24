#include "Zombie.hpp"

// Creates a zombie on the STACK and immediately announces it.
void randomChump(std::string name) {
    Zombie z(name);   // Local (stack-allocated) object
    z.announce();     // Immediately calls announce()
}
