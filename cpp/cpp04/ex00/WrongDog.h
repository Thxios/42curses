
#pragma once

#include <string>
#include "WrongAnimal.h"


class WrongDog: public WrongAnimal {
public:
    WrongDog();
    WrongDog(const WrongDog& other);
    virtual ~WrongDog();
    WrongDog& operator=(const WrongDog& other);

    virtual void makeSound() const;
};
