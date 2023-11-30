
#pragma once

#include <string>
#include "WrongAnimal.h"
#include "Brain.h"


class WrongCat: public WrongAnimal {
public:
    WrongCat();
    WrongCat(const WrongCat& other);
    virtual ~WrongCat();
    WrongCat& operator=(const WrongCat& other);

    virtual void makeSound() const;

    void setIdea(int idx, const std::string& idea);
    void showIdeas() const;

private:
    Brain* brain;
};
