
#include <iostream>
#include "WrongDog.h"


WrongDog::WrongDog(): WrongAnimal("WrongDog") {
    std::cout << "WrongDog Constructor" << std::endl;
}
WrongDog::WrongDog(const WrongDog& other): WrongAnimal(other) {
    std::cout << "WrongDog Constructor" << std::endl;
}
WrongDog::~WrongDog() {
    std::cout << "WrongDog Destructor" << std::endl;
}
WrongDog& WrongDog::operator=(const WrongDog& other) {
    WrongAnimal::operator=(other);
    return *this;
}


void WrongDog::makeSound() const {
    std::cout << "WrongDog: Woof! Woof!" << std::endl;
}
