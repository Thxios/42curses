
#include "Point.h"



Point::Point(): x(0), y(0) {}
Point::Point(float x_, float y_): x(x_), y(y_) {}
Point::Point(Fixed x_, Fixed y_): x(x_), y(y_) {}
Point::Point(const Point& other): x(other.x), y(other.y) {}
Point::~Point() {}


Point& Point::operator=(const Point& other) {
    *(const_cast<Fixed*>(&x)) = other.x;
    *(const_cast<Fixed*>(&y)) = other.y;
    return *this;
}


Point Point::operator-(const Point& other) const {
    return Point(x - other.x, y - other.y);
}


Fixed Point::cross(const Point& other) const {
    return x*other.y - y*other.x;
}


bool checkSign(Fixed a, Fixed b) {
    if (a < Fixed(0) && b < Fixed(0))
        return true;
    else if (a > Fixed(0) && b > Fixed(0))
        return true;
    else
        return false;
}


Fixed ccw(Point a, Point b, Point c) {
    Point ab(b - a), ac(c - a);
    return ab.cross(ac);
}


bool bsp( Point const a, Point const b, Point const c, Point const point) {
    Fixed c1(ccw(a, b, point));
    Fixed c2(ccw(b, c, point));
    Fixed c3(ccw(c, a, point));
    return checkSign(c1, c2) && checkSign(c2, c3);
}
