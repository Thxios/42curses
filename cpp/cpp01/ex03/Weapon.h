
#pragma once

#include <string>


class Weapon {
public:
    Weapon(std::string type_);

    const std::string& getType() const;
    void setType(std::string newone);

private:
    std::string type;
};
