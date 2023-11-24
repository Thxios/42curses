
#pragma once


class Fixed {
public:
    Fixed();
    Fixed(const Fixed& other);
    ~Fixed();
    Fixed& operator=(const Fixed& other);

    int getRawBits(void) const;
    void setRawBits(int const raw);

private:
    int value;
    static const int NUM_FRATIONAL_BITS;

};
