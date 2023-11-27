
#include <iostream>
#include "Fixed.h"
#include "Point.h"

int main( void ) {

    {
        Point a(3, 4);
        Point b(0, 0);
        Point c(4, 0);
        Point x(2, 2);
        Point y(0, 1);
        Point z(3.5f, 2.0f);

        std::cout << "IN   " << bsp(a, b, c, x) << std::endl;
        std::cout << "OUT  " << bsp(a, b, c, y) << std::endl;
        std::cout << "EDGE " << bsp(a, b, c, z) << std::endl;
    }
    {
        Point a(2, 2);
        Point b(0, 5);
        Point c(4, 4);
        Point x(1, 4);
        Point y(1, 5);
        Point z(3, 3);

        std::cout << "IN   " << bsp(a, b, c, x) << std::endl;
        std::cout << "OUT  " << bsp(a, b, c, y) << std::endl;
        std::cout << "EDGE " << bsp(a, b, c, z) << std::endl;
    }
    return 0;

}
