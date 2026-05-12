#pragma once
#include <iostream>
#include <cstdint>
#include <stdexcept>

namespace graphics {
    /** @brief Класс Цвет, хранит компоненты RGB в диапазоне [0, 255]. */
    class Color {
    private:
        uint8_t r, g, b;
        void validate(const int r, const int g, const int b) const;
    public:
        /**
         * @brief Конструктор цвета.
         */
        Color(const int r = 0, const int g = 0,const int b = 0);

        uint8_t getR() const;
        uint8_t getG() const;
        uint8_t getB() const;

        friend std::ostream& operator<<(std::ostream& os, const Color& c);
        friend std::istream& operator>>(std::istream& is, Color& c);
    };
}
