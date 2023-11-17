
#include "Zombie.h"


Zombie* zombieHorde(int n, std::string name) {
    Zombie* zombies = new Zombie[n];

    for (int i = 0; i < n; i++) {
        zombies[i].SetName(name);
    }
    return zombies;
}
