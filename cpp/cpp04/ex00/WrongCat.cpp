
#include <iostream>
#include "WrongCat.h"


WrongCat::WrongCat(): WrongAnimal("WrongCat") {
    std::cout << "WrongCat Constructor" << std::endl;
}
WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other) {
    std::cout << "WrongCat Constructor" << std::endl;
}
WrongCat::~WrongCat() {
    std::cout << "WrongCat Destructor" << std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat& other) {
    WrongAnimal::operator=(other);
    return *this;
}


void WrongCat::makeSound() const {
    std::cout << "WrongCat: Meow Meow.." << std::endl;
}
