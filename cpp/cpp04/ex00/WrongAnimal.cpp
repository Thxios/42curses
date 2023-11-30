
#include <iostream>
#include "WrongAnimal.h"


WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal Constructor" << std::endl;
}
WrongAnimal::WrongAnimal(const std::string& type_): type(type_) {
    std::cout << "WrongAnimal Constructor" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& other): type(other.type) {
    std::cout << "WrongAnimal Constructor" << std::endl;
}
WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal Destructor" << std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    type = other.type;
    return *this;
}


void WrongAnimal::makeSound() const {
    std::cout << "unknown WrongAnimal makes sound" << std::endl;
}


std::string WrongAnimal::getType() const {
    return type;
}
