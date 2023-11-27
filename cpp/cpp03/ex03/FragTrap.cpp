
#include <iostream>
#include "FragTrap.h"



FragTrap::FragTrap(): ClapTrap() {
    std::cout << "FragTrap Default Constructor call" << std::endl;
    hp = 100;
    energy = 100;
    damage = 30;   
}

FragTrap::FragTrap(const std::string& name_): ClapTrap(name_) {
    std::cout << "FragTrap Constructor call" << std::endl;    
    hp = 100;
    energy = 100;
    damage = 30;   
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other) {
    std::cout << "FragTrap Copy Constructor call" << std::endl;    
    name = other.name;
    hp = other.hp;
    energy = other.energy;
    damage = other.damage;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor call" << std::endl;    
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    name = other.name;
    hp = other.hp;
    energy = other.energy;
    damage = other.damage;
    return *this;
}


void FragTrap::attack(const std::string& target) {
    if (hp <= 0) {
        std::cout << "FragTrap " << name << " is out of hp" << std::endl;
        return;
    }
    if (energy <= 0) {
        std::cout << "FragTrap " << name << " is out of energy" << std::endl;
        return;
    }
    std::cout << "FragTrap " << name << " attacks " << target 
        << ", causing " << damage << " points of damage" << std::endl;
    energy--;
}


void FragTrap::takeDamage(unsigned int amount) {
    std::cout << "FragTrap " << name << " takes " 
        << amount << " points of damage" << std::endl;
    hp -= amount;
}


void FragTrap::beRepaired(unsigned int amount) {
    if (hp <= 0) {
        std::cout << "FragTrap " << name << " is out of hp" << std::endl;
        return;
    }
    if (energy <= 0) {
        std::cout << "FragTrap " << name << " is out of energy" << std::endl;
        return;
    }
    std::cout << "FragTrap " << name << " is repaired by " 
        << amount << " points" << std::endl;
    energy--;
    hp += amount;
}


void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << name << " highfives" << std::endl;
}



