#pragma once

#include <ostream>

struct Point {
    int x;
    int y;

    friend std::ostream &operator<<(std::ostream &os, const Point &point) {
        os << "x: " << point.x << " y: " << point.y;
        return os;
    }
};
