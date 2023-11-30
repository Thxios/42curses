
#include <iostream>
#include "WrongCat.h"


WrongCat::WrongCat(): WrongAnimal("WrongCat") {
    std::cout << "WrongCat Constructor" << std::endl;
    brain = new Brain();
}
WrongCat::WrongCat(const WrongCat& other)
: WrongAnimal(other), brain(other.brain) {
    std::cout << "WrongCat Constructor" << std::endl;
}
WrongCat::~WrongCat() {
    std::cout << "WrongCat Destructor" << std::endl;
    delete brain;
}
WrongCat& WrongCat::operator=(const WrongCat& other) {
    WrongAnimal::operator=(other);
    brain = other.brain;
    return *this;
}


void WrongCat::makeSound() const {
    std::cout << "WrongCat: Meow Meow.." << std::endl;
}


void WrongCat::setIdea(int idx, const std::string& idea) {
    if (brain) {
        brain->setIdea(idx, idea);
    }
}
void WrongCat::showIdeas() const {
    if (brain) {
        brain->showIdeas();
    }
}

