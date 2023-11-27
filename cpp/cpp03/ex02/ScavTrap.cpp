
#include <iostream>
#include "ScavTrap.h"



ScavTrap::ScavTrap(): ClapTrap() {
    std::cout << "ScavTrap Default Constructor call" << std::endl;
    hp = 100;
    energy = 50;
    damage = 20;   
}

ScavTrap::ScavTrap(const std::string& name_): ClapTrap(name_) {
    std::cout << "ScavTrap Constructor call" << std::endl;    
    hp = 100;
    energy = 50;
    damage = 20;   
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other) {
    std::cout << "ScavTrap Copy Constructor call" << std::endl;    
    name = other.name;
    hp = other.hp;
    energy = other.energy;
    damage = other.damage;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor call" << std::endl;    
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    name = other.name;
    hp = other.hp;
    energy = other.energy;
    damage = other.damage;
    return *this;
}


void ScavTrap::attack(const std::string& target) {
    if (hp <= 0) {
        std::cout << "ScavTrap " << name << " is out of hp" << std::endl;
        return;
    }
    if (energy <= 0) {
        std::cout << "ScavTrap " << name << " is out of energy" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << name << " attacks " << target 
        << ", causing " << damage << " points of damage" << std::endl;
    energy--;
}


void ScavTrap::takeDamage(unsigned int amount) {
    std::cout << "ScavTrap " << name << " takes " 
        << amount << " points of damage" << std::endl;
    hp -= amount;
}


void ScavTrap::beRepaired(unsigned int amount) {
    if (hp <= 0) {
        std::cout << "ScavTrap " << name << " is out of hp" << std::endl;
        return;
    }
    if (energy <= 0) {
        std::cout << "ScavTrap " << name << " is out of energy" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << name << " is repaired by " 
        << amount << " points" << std::endl;
    energy--;
    hp += amount;
}


void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " guardgate" << std::endl;
}



