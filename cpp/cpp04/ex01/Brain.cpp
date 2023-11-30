
#include <iostream>
#include "Brain.h"


Brain::Brain() {
    std::cout << "Brain Constructor" << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain Copy Constructor" << std::endl;
    for (int i = 0; i < 100; i++) {
        ideas[i] = other.ideas[i];
    }
}

Brain::~Brain() {
    std::cout << "Brain Destructor" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    for (int i = 0; i < 100; i++) {
        ideas[i] = other.ideas[i];
    }
    return *this;
}


void Brain::setIdea(int idx, const std::string& idea) {
    if (0 <= idx && idx < 100) {
        ideas[idx] = idea; 
    }
}

void Brain::showIdeas() const {
    for (int i = 0; i < 100; i++) {
        std::cout << ideas[i] << " ";
    }
    std::endl(std::cout);
}


