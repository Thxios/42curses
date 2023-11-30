
#pragma once

#include <string>
#include "Animal.h"
#include "Brain.h"


class Cat: public Animal {
public:
    Cat();
    Cat(const Cat& other);
    virtual ~Cat();
    Cat& operator=(const Cat& other);

    virtual void makeSound() const;

    void setIdea(int idx, const std::string& idea);
    void showIdeas() const;

private:
    Brain* brain;
};
