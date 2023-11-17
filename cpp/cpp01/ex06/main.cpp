
#include <iostream>
#include <string>
#include "Harl.h"




int main(int argc, char *argv[]) {

    if (argc != 2) {
        std::cout << "invalid number of args" << std::endl;
        return 0;
    }

    Harl harl;

    harl.complain(argv[1]);

}
