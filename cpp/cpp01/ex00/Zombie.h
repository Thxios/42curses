
#pragma once

#include <string>


class Zombie {

public:
    Zombie(std::string name_);
    ~Zombie();

    void announce() const;

private:
    std::string name;

};


Zombie* newZombie(std::string name);
void randomChump(std::string name);
