
#pragma once

#include "AMateria.h"


class Cure: public AMateria {
public:
    Cure();
    Cure(const Cure& other);
    virtual ~Cure();
    Cure& operator=(const Cure& other);

    virtual Cure* clone() const;
    virtual void use(ICharacter& target);
};
