
#pragma once

#include <string>


class Harl {
public:
    void complain(std::string level);

private:
    void debug();
    void info();
    void warning();
    void error();
};


