#include "newZombie.hpp"
#include "randomChump.hpp"

int main() {
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();

    randomChump("StackZombie");

    delete heapZombie;
    return 0;
}
