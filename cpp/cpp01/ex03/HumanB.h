
#pragma once

#pragma once

#include <string>
#include "Weapon.h"


class HumanB {
public:
    HumanB(std::string name_);

    void attack();
    void setWeapon(const Weapon& weapon_);

private:
    std::string name;
    const Weapon* weapon;
};
