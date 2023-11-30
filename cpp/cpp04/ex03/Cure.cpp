
#include <iostream>
#include "Cure.h"


Cure::Cure(): AMateria("cure") {}
Cure::Cure(const Cure& other): AMateria(other) {}
Cure::~Cure() {}

Cure& Cure::operator=(const Cure& other) {
    AMateria::operator=(other);
    return *this;
}


Cure* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}


