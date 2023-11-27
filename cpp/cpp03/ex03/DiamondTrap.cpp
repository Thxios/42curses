
#include <iostream>
#include "DiamondTrap.h"



DiamondTrap::DiamondTrap(): ClapTrap() {
    std::cout << "DiamondTrap Default Constructor call" << std::endl;
    hp = 100;
    energy = 50;
    damage = 30;   
}

DiamondTrap::DiamondTrap(const std::string& name_)
: ClapTrap(name_ + "_clap_name"), ScavTrap(), FragTrap() {
    std::cout << "DiamondTrap Constructor call" << std::endl;  
    name = name_;
    hp = 100;
    energy = 50;
    damage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
: ClapTrap(other), ScavTrap(other), FragTrap(other) {
    std::cout << "DiamondTrap Copy Constructor call" << std::endl;    
    name = other.name;
    hp = other.hp;
    energy = other.energy;
    damage = other.damage;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap Destructor call" << std::endl;    
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    name = other.name;
    ClapTrap::name = other.ClapTrap::name;
    hp = other.hp;
    energy = other.energy;
    damage = other.damage;
    return *this;
}


void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}


void DiamondTrap::takeDamage(unsigned int amount) {
    std::cout << "DiamondTrap " << name << " takes " 
        << amount << " points of damage" << std::endl;
    hp -= amount;
}


void DiamondTrap::beRepaired(unsigned int amount) {
    if (hp <= 0) {
        std::cout << "DiamondTrap " << name << " is out of hp" << std::endl;
        return;
    }
    if (energy <= 0) {
        std::cout << "DiamondTrap " << name << " is out of energy" << std::endl;
        return;
    }
    std::cout << "DiamondTrap " << name << " is repaired by " 
        << amount << " points" << std::endl;
    energy--;
    hp += amount;
}



void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap - name: " << name
    << ", clap_name: " << ClapTrap::name 
    << ", hp: " << hp << ", energy: " << energy << ", atk: " << damage << std::endl;
}



