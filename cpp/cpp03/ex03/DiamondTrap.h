
#pragma once

#include <string>
#include "ScavTrap.h"
#include "FragTrap.h"


class DiamondTrap: public ScavTrap, public FragTrap {
public:
    DiamondTrap();
    DiamondTrap(const std::string& name_);
    DiamondTrap(const DiamondTrap& other);
    ~DiamondTrap();
    DiamondTrap& operator=(const DiamondTrap& other);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    void whoAmI();

private:
    std::string name;
};


