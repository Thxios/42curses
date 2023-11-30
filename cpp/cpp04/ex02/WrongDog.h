
#pragma once

#include <string>
#include "WrongAnimal.h"
#include "Brain.h"


class WrongDog: public WrongAnimal {
public:
    WrongDog();
    WrongDog(const WrongDog& other);
    virtual ~WrongDog();
    WrongDog& operator=(const WrongDog& other);

    virtual void makeSound() const;

    void setIdea(int idx, const std::string& idea);
    void showIdeas() const;

private:
    Brain* brain;
};
