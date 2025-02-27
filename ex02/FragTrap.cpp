#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name)
    : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " constructed." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
    : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called." << std::endl;
    *this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    std::cout << "FragTrap copy assignment operator called." << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _name << " destructed." << std::endl;
}

void FragTrap::attack(const std::string &target) {
    if (_hitPoints == 0 || _energyPoints == 0) {
        std::cout << "FragTrap " << _name << " cannot attack (no hit points or energy left)." << std::endl;
        return;
    }
    std::cout << "FragTrap " << _name << " attacks " << target
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name << " requests: High Fives, Guys!" << std::endl;
}
