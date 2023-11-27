
#pragma once

#include <string>
#include "ClapTrap.h"


class ScavTrap: virtual public ClapTrap {
public:
    ScavTrap();
    ScavTrap(const std::string& name_);
    ScavTrap(const ScavTrap& other);
    ~ScavTrap();
    ScavTrap& operator=(const ScavTrap& other);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void guardGate();
};


