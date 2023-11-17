
#include <iostream>
#include "Zombie.h"


int main() {

    std::cout << "===== 3 zombies =====" << std::endl;
    Zombie* zombies = zombieHorde(3, "Threeee");
    for (int i = 0; i < 3; i++) {
        zombies[i].announce();
    }
    delete[] zombies;
    std::cout << std::endl;
    

    std::cout << "===== 5 zombies =====" << std::endl;
    Zombie* zombies2 = zombieHorde(5, "Fiveeee");
    for (int i = 0; i < 5; i++) {
        zombies2[i].announce();
    }
    delete[] zombies2;
    std::cout << std::endl;
}

