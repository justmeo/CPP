#include "ClapTrap.hpp"

int main()
{
    ClapTrap ct("CT-1");
    ct.attack("Target A");
    ct.takeDamage(3);
    ct.beRepaired(2);
    return 0;
}
