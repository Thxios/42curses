
#include <iostream>
#include "DiamondTrap.h"


int main() {
    DiamondTrap trap("James");

    trap.takeDamage(4);
    trap.beRepaired(3);
    trap.attack("John");
    trap.guardGate();
    trap.highFivesGuys();
    trap.whoAmI();
}
