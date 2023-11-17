
#include <iostream>
#include "HumanB.h"


HumanB::HumanB(std::string name_)
: name(name_), weapon(NULL) {}


void HumanB::attack() {
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}


void HumanB::setWeapon(const Weapon& weapon_) {
    weapon = &weapon_;
}
