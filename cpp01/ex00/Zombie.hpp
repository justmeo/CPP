#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
private:
    std::string _name;  // Each Zombie's name

public:
    // Constructor & Destructor
    Zombie(std::string name);
    ~Zombie();

    // Announce method
    void announce(void) const;
};

#endif
