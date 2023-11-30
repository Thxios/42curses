
#include <iostream>
#include "Dog.h"


Dog::Dog(): Animal("Dog") {
    std::cout << "Dog Constructor" << std::endl;
    brain = new Brain();
}
Dog::Dog(const Dog& other): Animal(other) {
    std::cout << "Dog Constructor" << std::endl;
    brain = new Brain(*other.brain);
}
Dog::~Dog() {
    std::cout << "Dog Destructor" << std::endl;
    delete brain;
}
Dog& Dog::operator=(const Dog& other) {
    Animal::operator=(other);
    Brain* tmp = new Brain(*other.brain);
    delete brain;
    brain = tmp;
    return *this;
}


void Dog::makeSound() const {
    std::cout << "Dog: Woof! Woof!" << std::endl;
}


void Dog::setIdea(int idx, const std::string& idea) {
    if (brain) {
        brain->setIdea(idx, idea);
    }
}
void Dog::showIdeas() const {
    if (brain) {
        brain->showIdeas();
    }
}
