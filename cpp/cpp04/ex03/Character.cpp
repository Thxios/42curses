
#include "Character.h"


Character::Character() {
    for (int i = 0; i < 4; i++) {
        slots[i] = NULL;
    }
}

Character::Character(const std::string& name_): name(name_) {
    for (int i = 0; i < 4; i++) {
        slots[i] = NULL;
    }
}

Character::Character(const Character& other): name(other.name) {
    for (int i = 0; i < 4; i++) {
        AMateria* tmp = NULL;
        if (other.slots[i]) {
            tmp = other.slots[i]->clone();
        }
        slots[i] = tmp;
    }
}

Character::~Character() {}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        name = other.name;
        for (int i = 0; i < 4; i++) {
            AMateria* tmp = NULL;
            if (other.slots[i]) {
                tmp = other.slots[i]->clone();
            }
            delete slots[i];
            slots[i] = tmp;
        }
    }
    return *this;
}


std::string const& Character::getName() const {
    return name;
}


void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (!slots[i]) {
            slots[i] = m;
            break;
        }
    }
}


void Character::unequip(int idx) {
    slots[idx] = NULL;
}


void Character::use(int idx, ICharacter& target) {
    if (slots[idx]) {
        slots[idx]->use(target);
    }
}




