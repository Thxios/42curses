
#pragma once

#include <string>
#include "ICharacter.h"
#include "AMateria.h"


class Character: public ICharacter {
public:
    Character();
    Character(const std::string& name_);
    Character(const Character& other);
    virtual ~Character();
    Character& operator=(const Character& other);

    virtual std::string const& getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);

private:
    std::string name;
    AMateria* slots[4];
};

