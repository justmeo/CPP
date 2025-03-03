#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name)
    : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << me << " constructed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
    : ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called." << std::endl;
    *this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) 
{
    std::cout << "ScavTrap copy assignment operator called." << std::endl;
    if (this != &other) 
	{
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap() 
{
    std::cout << "ScavTrap " << me << " destructed." << std::endl;
}

void ScavTrap::attack(const std::string &target) 
{
    if (hitPoints == 0 || energyPoints == 0) 
	{
        std::cout << "ScavTrap " << me << " cannot attack (no hit points or energy left)." << std::endl;
        return;
    }
    std::cout << "ScavTrap " << me << " fiercely attacks " << target
              << ", causing " << attackDamage << " points of damage!" << std::endl;
    energyPoints--;
}

void ScavTrap::guardGate() 
{
    std::cout << "ScavTrap " << me << " is now in Gate keeper mode." << std::endl;
}
