
#pragma once

#include <string>
#include "ClapTrap.h"


class FragTrap: virtual public ClapTrap {
public:
    FragTrap();
    FragTrap(const std::string& name_);
    FragTrap(const FragTrap& other);
    ~FragTrap();
    FragTrap& operator=(const FragTrap& other);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    
    void highFivesGuys();
};


