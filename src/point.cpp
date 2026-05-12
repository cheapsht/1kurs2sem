#include "Point.h"
#include <cmath>
#include <limits>

namespace graphics {

Point::Point(double x, double y) : x(x), y(y) {}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Point& p) {
    char ch;
    is >> ch; // '('
    is >> p.x;
    is >> ch; // ','
    is >> p.y;
    is >> ch; // ')'
    return is;
}

bool operator==(const Point& lhs, const Point& rhs) {
    return std::abs(lhs.x - rhs.x) < std::numeric_limits<double>::epsilon() && 
           std::abs(lhs.y - rhs.y) < std::numeric_limits<double>::epsilon();
}
}
bool operator!=(const Point& lhs, const Point& rhs) {
    return !(lhs == rhs);

}
