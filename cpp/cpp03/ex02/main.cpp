
#include <iostream>
#include "FragTrap.h"


int main() {
    FragTrap trap("James");

    trap.takeDamage(4);
    trap.beRepaired(3);
    trap.attack("John");
    trap.highFivesGuys();

    FragTrap trap2(trap);
    trap2.takeDamage(5);
}
