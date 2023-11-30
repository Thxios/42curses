
#include <iostream>
#include "Dog.h"


Dog::Dog(): Animal("Dog") {
    std::cout << "Dog Constructor" << std::endl;
}
Dog::Dog(const Dog& other): Animal(other) {
    std::cout << "Dog Constructor" << std::endl;
}
Dog::~Dog() {
    std::cout << "Dog Destructor" << std::endl;
}
Dog& Dog::operator=(const Dog& other) {
    Animal::operator=(other);
    return *this;
}


void Dog::makeSound() const {
    std::cout << "Dog: Woof! Woof!" << std::endl;
}
