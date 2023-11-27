
#include <iostream>
#include "ScavTrap.h"


int main() {
    ScavTrap trap("James");

    trap.takeDamage(4);
    trap.beRepaired(3);
    trap.attack("John");
    trap.guardGate();
}
