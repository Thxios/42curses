
#include <iostream>
#include "Cat.h"


Cat::Cat(): Animal("Cat") {
    std::cout << "Cat Constructor" << std::endl;
}
Cat::Cat(const Cat& other): Animal(other) {
    std::cout << "Cat Constructor" << std::endl;
}
Cat::~Cat() {
    std::cout << "Cat Destructor" << std::endl;
}
Cat& Cat::operator=(const Cat& other) {
    Animal::operator=(other);
    return *this;
}


void Cat::makeSound() const {
    std::cout << "Cat: Meow Meow.." << std::endl;
}
