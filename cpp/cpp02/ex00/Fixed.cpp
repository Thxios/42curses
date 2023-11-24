
#include <iostream>
#include "Fixed.h"


const int Fixed::NUM_FRATIONAL_BITS = 8;


Fixed::Fixed(): value(0) {
    std::cout << "Default Constructor call" << std::endl;
}


Fixed::Fixed(const Fixed& other): value(other.getRawBits()) {
    std::cout << "Copy Constructor call" << std::endl;
}


Fixed::~Fixed() {
    std::cout << "Destructor call" << std::endl;
}


Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy Assignment Operator call" << std::endl;
    value = other.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits call" << std::endl;
    return value;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits call" << std::endl;
    value = raw;
}


