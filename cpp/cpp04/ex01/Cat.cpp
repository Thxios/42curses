
#include <iostream>
#include "Cat.h"


Cat::Cat(): Animal("Cat") {
    std::cout << "Cat Constructor" << std::endl;
    brain = new Brain();
}
Cat::Cat(const Cat& other): Animal(other) {
    std::cout << "Cat Constructor" << std::endl;
    brain = new Brain(*other.brain);
}
Cat::~Cat() {
    std::cout << "Cat Destructor" << std::endl;
    delete brain;
}
Cat& Cat::operator=(const Cat& other) {
    Animal::operator=(other);
    Brain* tmp = new Brain(*other.brain);
    delete brain;
    brain = tmp;
    return *this;
}


void Cat::makeSound() const {
    std::cout << "Cat: Meow Meow.." << std::endl;
}


void Cat::setIdea(int idx, const std::string& idea) {
    brain->setIdea(idx, idea);
}
void Cat::showIdeas() const {
    brain->showIdeas();
}

