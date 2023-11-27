
#include <iostream>
#include "ClapTrap.h"



ClapTrap::ClapTrap(): hp(10), energy(10), damage(0) {
    std::cout << "ClapTrap Default Constructor call" << std::endl;    
}

ClapTrap::ClapTrap(const std::string& name_)
: name(name_), hp(10), energy(10), damage(0) {
    std::cout << "ClapTrap Constructor call" << std::endl;    
}

ClapTrap::ClapTrap(const ClapTrap& other)
: name(other.name), hp(other.hp), energy(other.energy), damage(other.damage) {
    std::cout << "ClapTrap Copy Constructor call" << std::endl;    
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap Destructor call" << std::endl;    
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    name = other.name;
    hp = other.hp;
    energy = other.energy;
    damage = other.damage;
    return *this;
}


void ClapTrap::attack(const std::string& target) {
    if (hp <= 0) {
        std::cout << "ClapTrap " << name << " is out of hp" << std::endl;
        return;
    }
    if (energy <= 0) {
        std::cout << "ClapTrap " << name << " is out of energy" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " attacks " << target 
        << ", causing " << damage << " points of damage" << std::endl;
    energy--;
}


void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "ClapTrap " << name << " takes " 
        << amount << " points of damage" << std::endl;
    hp -= amount;
}


void ClapTrap::beRepaired(unsigned int amount) {
    if (hp <= 0) {
        std::cout << "ClapTrap " << name << " is out of hp" << std::endl;
        return;
    }
    if (energy <= 0) {
        std::cout << "ClapTrap " << name << " is out of energy" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " is repaired by " 
        << amount << " points" << std::endl;
    energy--;
    hp += amount;
}




