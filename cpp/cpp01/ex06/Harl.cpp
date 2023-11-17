
#include <iostream>
#include "Harl.h"


void Harl::complain(std::string level) {
    static std::string levels[4]
        = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    int level_idx = -1;
    for (int i = 0; i < 4; i++) {
        if (level == levels[i]) {
            level_idx = i;
            break;
        }
    }

    switch (level_idx) {
    case 0:
        std::cout << "[ DEBUG ]" << std::endl;
        debug();
        std::cout << std::endl;

    case 1:
        std::cout << "[ INFO ]" << std::endl;
        info();
        std::cout << std::endl;

    case 2:
        std::cout << "[ WARNING ]" << std::endl;
        warning();
        std::cout << std::endl;

    case 3:
        std::cout << "[ ERROR ]" << std::endl;
        error();
        std::cout << std::endl;
        break;
    
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    }
}


void Harl::debug() {
    std::cout << "I love having extra bacon for my"
                 " 7XL-double-cheese-triple-pickle-specialketchup burger."
                 " I really do!" << std::endl;
}


void Harl::info() {
    std::cout << "I cannot believe adding extra bacon costs more money."
                 " You didn't put enough bacon in my burger!"
                 " If you did, I wouldn't be asking for more!" << std::endl;

}


void Harl::warning() {
    std::cout << "I think I deserve to have some extra bacon for free."
                 " I've been coming for years "
                 " whereas you started working here since last month." << std::endl;

}


void Harl::error() {
    std::cout << "This is unacceptable!"
                 " I want to speak to the manager now." << std::endl;

}




