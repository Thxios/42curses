
#pragma once

#include "Fixed.h"


class Point {
public:
    Point();
    Point(float x_, float y_);
    Point(Fixed x_, Fixed y_);
    Point(const Point& other);
    ~Point();
    Point& operator=(const Point& other);

    Point operator-(const Point& other) const;
    Fixed cross(const Point& other) const;

private:
    Fixed const x, y;
};


Fixed ccw(Point a, Point b, Point c);
bool bsp( Point const a, Point const b, Point const c, Point const point);
