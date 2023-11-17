
#pragma once

#include <string>
#include "Weapon.h"


class HumanA {
public:
    HumanA(std::string name_, const Weapon& weapon_);

    void attack();

private:
    std::string name;
    const Weapon& weapon;
};
