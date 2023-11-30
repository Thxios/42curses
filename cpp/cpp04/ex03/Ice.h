
#pragma once

#include "AMateria.h"


class Ice: public AMateria {
public:
    Ice();
    Ice(const Ice& other);
    virtual ~Ice();
    Ice& operator=(const Ice& other);

    virtual Ice* clone() const;
    virtual void use(ICharacter& target);
};
