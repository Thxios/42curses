
#pragma once

#include <string>
#include "Animal.h"


class Cat: public Animal {
public:
    Cat();
    Cat(const Cat& other);
    virtual ~Cat();
    Cat& operator=(const Cat& other);

    virtual void makeSound() const;
};
