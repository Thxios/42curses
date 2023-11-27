
#pragma once

#include <string>


class ClapTrap {
public:
    ClapTrap();
    ClapTrap(const std::string& name_);
    ClapTrap(const ClapTrap& other);
    ~ClapTrap();
    ClapTrap& operator=(const ClapTrap& other);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

protected:
    std::string name;
    int hp, energy, damage;
};


