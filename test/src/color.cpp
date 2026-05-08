#include "Color.h"

namespace graphics {
    void Color::validate(int r, int g, int b) const {
        if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
            throw std::invalid_argument("Значения цвета должны быть в диапазоне [0, 255]");
        }
    }

    Color::Color(int r, int g, int b) {
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
        char bracket, comma;
        int r, g, b;
        is >> bracket >> r >> comma >> g >> comma >> b >> bracket;
        c = Color(r, g, b);  // Конструктор проверит и создаст объект
        return is;
    }
}
