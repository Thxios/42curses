
#include <iostream>
#include "WrongDog.h"


WrongDog::WrongDog(): WrongAnimal("WrongDog") {
    std::cout << "WrongDog Constructor" << std::endl;
    brain = new Brain();
}
WrongDog::WrongDog(const WrongDog& other)
: WrongAnimal(other), brain(other.brain) {
    std::cout << "WrongDog Constructor" << std::endl;
}
WrongDog::~WrongDog() {
    std::cout << "WrongDog Destructor" << std::endl;
    delete brain;
}
WrongDog& WrongDog::operator=(const WrongDog& other) {
    WrongAnimal::operator=(other);
    brain = other.brain;
    return *this;
}


void WrongDog::makeSound() const {
    std::cout << "WrongDog: Woof! Woof!" << std::endl;
}


void WrongDog::setIdea(int idx, const std::string& idea) {
    if (brain) {
        brain->setIdea(idx, idea);
    }
}
void WrongDog::showIdeas() const {
    if (brain) {
        brain->showIdeas();
    }
}

