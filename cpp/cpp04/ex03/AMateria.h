
#pragma once

#include <string>
#include "ICharacter.h"


class AMateria {
public:
    AMateria();
    AMateria(std::string const& type_);
    AMateria(const AMateria& other);
    virtual ~AMateria();
    AMateria& operator=(const AMateria& other);

    std::string const& getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target) = 0;

protected:
    std::string type;
};
