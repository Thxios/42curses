
#include <iostream>
#include "Ice.h"


Ice::Ice(): AMateria("ice") {}
Ice::Ice(const Ice& other): AMateria(other) {}
Ice::~Ice() {}

Ice& Ice::operator=(const Ice& other) {
    AMateria::operator=(other);
    return *this;
}


Ice* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}


