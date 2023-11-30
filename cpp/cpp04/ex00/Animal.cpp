
#include <iostream>
#include "Animal.h"


Animal::Animal() {
    std::cout << "Animal Constructor" << std::endl;
}
Animal::Animal(const std::string& type_): type(type_) {
    std::cout << "Animal Constructor" << std::endl;
}
Animal::Animal(const Animal& other): type(other.type) {
    std::cout << "Animal Constructor" << std::endl;
}
Animal::~Animal() {
    std::cout << "Animal Destructor" << std::endl;
}
Animal& Animal::operator=(const Animal& other) {
    type = other.type;
    return *this;
}


void Animal::makeSound() const {
    std::cout << "unknown animal makes sound" << std::endl;
}


std::string Animal::getType() const {
    return type;
}
