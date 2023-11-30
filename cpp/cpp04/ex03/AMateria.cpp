
#include "AMateria.h"


AMateria::AMateria() {}
AMateria::AMateria(std::string const& type_): type(type_) {}
AMateria::AMateria(const AMateria& other): type(other.type) {}
AMateria::~AMateria() {}

AMateria& AMateria::operator=(const AMateria& other) {
    type = other.type;
    return *this;
}


std::string const& AMateria::getType() const {
    return type;
}


