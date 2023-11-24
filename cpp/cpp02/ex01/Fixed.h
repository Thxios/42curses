
#pragma once

#include <iostream>


class Fixed {
public:
    Fixed();
    Fixed(const int n);
    Fixed(const float f);
    Fixed(const Fixed& other);
    ~Fixed();
    Fixed& operator=(const Fixed& other);

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;

private:
    int value;
    static const int NUM_FRATIONAL_BITS;

};


std::ostream& operator<<(std::ostream& out, const Fixed& f);

