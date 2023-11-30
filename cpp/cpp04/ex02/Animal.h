
#pragma once

#include <string>


class Animal {
public:
    Animal();
    Animal(const std::string& type_);
    Animal(const Animal& other);
    virtual ~Animal();
    Animal& operator=(const Animal& other);

    virtual void makeSound() const = 0;
    virtual std::string getType() const;

protected:
    std::string type;
};
