
#pragma once

#include <string>


class WrongAnimal {
public:
    WrongAnimal();
    WrongAnimal(const std::string& type_);
    WrongAnimal(const WrongAnimal& other);
    ~WrongAnimal();
    WrongAnimal& operator=(const WrongAnimal& other);

    void makeSound() const;
    std::string getType() const;

protected:
    std::string type;
};
