
#include <iostream>
#include "ClapTrap.h"


int main() {
    ClapTrap trap("Doe");

    trap.takeDamage(4);
    trap.takeDamage(4);
    trap.beRepaired(3);
    trap.attack("John");
    trap.takeDamage(5);
    trap.attack("John");
}
