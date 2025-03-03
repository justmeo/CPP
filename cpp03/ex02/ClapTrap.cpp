#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name)
    : me(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << me << " constructed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) 
{
    std::cout << "ClapTrap copy constructor called." << std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap copy assignment operator called." << std::endl;
    if (this != &other) {
        me = other.me;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << me << " destructed." << std::endl;
}

void ClapTrap::attack(const std::string &target) 
{
    if (hitPoints == 0 || energyPoints == 0) 
	{
        std::cout << "ClapTrap " << me << " cannot attack (no hit points or energy left)." << std::endl;
        return;
    }
    std::cout << "ClapTrap " << me << " attacks " << target
              << ", causing " << attackDamage << " points of damage!" << std::endl;
    energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) 
{
    if (amount > hitPoints)
        hitPoints = 0;
    else
        hitPoints -= amount;
    std::cout << "ClapTrap " << me << " takes " << amount 
              << " points of damage. Hit points now: " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) 
{
    if (hitPoints == 0 || energyPoints == 0) 
	{
        std::cout << "ClapTrap " << me << " cannot be repaired (no hit points or energy left)." << std::endl;
        return;
    }
    hitPoints += amount;
    energyPoints--;
    std::cout << "ClapTrap " << me << " is repaired by " << amount 
              << " points. Hit points now: " << hitPoints << std::endl;
}
