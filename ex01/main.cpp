#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap ct("CT-1");
    ct.attack("Target A");
    ct.takeDamage(3);
    ct.beRepaired(2);

    std::cout << std::endl;

    ScavTrap st("ST-1");
    st.attack("Target B");
    st.takeDamage(5);
    st.beRepaired(4);
    st.guardGate();

    return 0;
}
