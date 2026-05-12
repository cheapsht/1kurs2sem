#include "Color.h"
#include <sstream>

namespace graphics {

void Color::validate(const int r, const int g,const  int b) const {
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        throw std::invalid_argument("Color values must be in range [0, 255]");
    }
}

Color::Color(const int r, const int g,const  int b) {
    validate(r, g, b);
    this->r = static_cast<uint8_t>(r);
    this->g = static_cast<uint8_t>(g);
    this->b = static_cast<uint8_t>(b);
}

uint8_t Color::getR() const { return r; }
uint8_t Color::getG() const { return g; }
uint8_t Color::getB() const { return b; }

std::ostream& operator<<(std::ostream& os, const Color& c) {
    os << "(" << static_cast<int>(c.r) << "," << static_cast<int>(c.g) << "," << static_cast<int>(c.b) << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Color& c) {
    char ch;
    int r, g, b;
    is >> ch; // '('
    is >> r;
    is >> ch; // ','
    is >> g;
    is >> ch; // ','
    is >> b;
    is >> ch; // ')'
    c = Color(r, g, b);
    return is;
}

}
