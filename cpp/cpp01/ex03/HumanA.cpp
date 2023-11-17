
#include <iostream>
#include "HumanA.h"


HumanA::HumanA(std::string name_, const Weapon& weapon_)
: name(name_), weapon(weapon_) {}


void HumanA::attack() {
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
