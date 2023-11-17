
#pragma once

#include <string>


class Zombie {

public:
    Zombie();
    Zombie(std::string name_);
    ~Zombie();

    void announce() const;
    void SetName(std::string name_);

private:
    std::string name;

};


Zombie* zombieHorde(int n, std::string name);
