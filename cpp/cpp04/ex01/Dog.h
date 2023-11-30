
#pragma once

#include <string>
#include "Animal.h"
#include "Brain.h"


class Dog: public Animal {
public:
    Dog();
    Dog(const Dog& other);
    virtual ~Dog();
    Dog& operator=(const Dog& other);

    virtual void makeSound() const;

    void setIdea(int idx, const std::string& idea);
    void showIdeas() const;

private:
    Brain* brain;
};
