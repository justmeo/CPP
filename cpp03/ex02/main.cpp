#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() 
{
    ClapTrap ct("CT-1");
    ScavTrap st("ST-1");
    FragTrap ft("FT-1");

    std::cout << std::endl;

    ct.attack("Target A");
    st.attack("Target B");
    ft.attack("Target C");

    std::cout << std::endl;
    st.guardGate();
    ft.highFivesGuys();

    return 0;
}
