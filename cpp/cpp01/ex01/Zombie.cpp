
#include <iostream>
#include "Zombie.h"


Zombie::Zombie() {}


Zombie::Zombie(std::string name_): name(name_) {}


Zombie::~Zombie() {
    std::cout << "destruct " << name << std::endl;
}


void Zombie::announce() const {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


void Zombie::SetName(std::string name_) {
    name = name_;
}
