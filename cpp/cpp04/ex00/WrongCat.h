
#pragma once

#include <string>
#include "WrongAnimal.h"


class WrongCat: public WrongAnimal {
public:
    WrongCat();
    WrongCat(const WrongCat& other);
    virtual ~WrongCat();
    WrongCat& operator=(const WrongCat& other);

    virtual void makeSound() const;
};
