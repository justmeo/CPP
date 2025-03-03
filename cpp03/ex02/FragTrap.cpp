#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name)
    : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << me << " constructed." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
    : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called." << std::endl;
    *this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other) 
{
    std::cout << "FragTrap copy assignment operator called." << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap() 
{
    std::cout << "FragTrap " << me << " destructed." << std::endl;
}

void FragTrap::attack(const std::string &target) 
{
    if (hitPoints == 0 || energyPoints == 0) 
	{
        std::cout << "FragTrap " << me << " cannot attack (no hit points or energy left)." << std::endl;
        return;
    }
    std::cout << "FragTrap " << me << " attacks " << target
              << ", causing " << attackDamage << " points of damage!" << std::endl;
    energyPoints--;
}

void FragTrap::highFivesGuys(void) 
{
    std::cout << "FragTrap " << me << " requests: High Fives, Guys!" << std::endl;
}
