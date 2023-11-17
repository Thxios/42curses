
#include "Weapon.h"


Weapon::Weapon(std::string type_): type(type_) {}


const std::string& Weapon::getType() const {
    return type;
}


void Weapon::setType(std::string newone) {
    type = newone;
}
