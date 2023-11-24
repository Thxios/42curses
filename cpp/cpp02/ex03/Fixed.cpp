
#include <iostream>
#include <cmath>
#include "Fixed.h"


const int Fixed::NUM_FRATIONAL_BITS = 8;


Fixed::Fixed(): value(0) {
    // std::cout << "Default Constructor call" << std::endl;
}


Fixed::Fixed(const int n) {
    // std::cout << "Int Constructor call" << std::endl;
    value = n << NUM_FRATIONAL_BITS;
}


Fixed::Fixed(const float f) {
    // std::cout << "Float Constructor call" << std::endl;
    value = roundf(f * (1 << NUM_FRATIONAL_BITS));
}


Fixed::Fixed(const Fixed& other): value(other.getRawBits()) {
    // std::cout << "Copy Constructor call" << std::endl;
}


Fixed::~Fixed() {
    // std::cout << "Destructor call" << std::endl;
}


Fixed& Fixed::operator=(const Fixed& other) {
    // std::cout << "Copy Assignment Operator call" << std::endl;
    value = other.getRawBits();
    return *this;
}


int Fixed::getRawBits(void) const {
    // std::cout << "getRawBits call" << std::endl;
    return value;
}


void Fixed::setRawBits(int const raw) {
    // std::cout << "setRawBits call" << std::endl;
    value = raw;
}


float Fixed::toFloat(void) const {
    return (float)value / (1 << NUM_FRATIONAL_BITS);
}


int Fixed::toInt(void) const {
    return value >> NUM_FRATIONAL_BITS;
}


std::ostream& operator<<(std::ostream& out, const Fixed& f) {
    out << f.toFloat();
    return out;
}


bool Fixed::operator>(const Fixed& other) const {
    return getRawBits() > other.getRawBits();
}


bool Fixed::operator<(const Fixed& other) const {
    return getRawBits() < other.getRawBits();
}


bool Fixed::operator>=(const Fixed& other) const {
    return getRawBits() >= other.getRawBits();
}


bool Fixed::operator<=(const Fixed& other) const {
    return getRawBits() <= other.getRawBits();
}


bool Fixed::operator==(const Fixed& other) const {
    return getRawBits() == other.getRawBits();
}


bool Fixed::operator!=(const Fixed& other) const {
    return getRawBits() != other.getRawBits();
}



Fixed Fixed::operator+(const Fixed& other) const {
    Fixed tmp;
    tmp.setRawBits(getRawBits() + other.getRawBits());
    return tmp;
}


Fixed Fixed::operator-(const Fixed& other) const {
    Fixed tmp;
    tmp.setRawBits(getRawBits() - other.getRawBits());
    return tmp;
}


Fixed Fixed::operator*(const Fixed& other) const {
    Fixed tmp;
    tmp.setRawBits((int)(
        ((long)getRawBits() * other.getRawBits()) >> NUM_FRATIONAL_BITS
    ));
    return tmp;
}


Fixed Fixed::operator/(const Fixed& other) const {
    Fixed tmp;
    tmp.setRawBits((int)(
        ((long)getRawBits() << NUM_FRATIONAL_BITS) / other.getRawBits()
    ));
    return tmp;
}



Fixed& Fixed::operator++() {
    value++;
    return *this;
}


Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    value++;
    return tmp;
}


Fixed& Fixed::operator--() {
    value--;
    return *this;
}


Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    value--;
    return tmp;
}



Fixed& Fixed::min(Fixed& a, Fixed& b) {
    if (a > b)
        return b;
    else
        return a;
}


const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    if (a > b)
        return b;
    else
        return a;
}


Fixed& Fixed::max(Fixed& a, Fixed& b) {
    if (a < b)
        return b;
    else
        return a;

}


const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    if (a < b)
        return b;
    else
        return a;
}


