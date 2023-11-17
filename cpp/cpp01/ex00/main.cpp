
#include <iostream>
#include "Zombie.h"


int main() {
    std::cout << "===== newZombie =====" << std::endl;
    Zombie* zombie = newZombie("ByNew");
    zombie->announce();
    delete zombie;
    std::cout << std::endl;

    std::cout << "===== newZombie =====" << std::endl;
    randomChump("ByRandomChump");
    std::cout << std::endl;
}

