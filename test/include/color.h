#pragma once
#include <iostream>
#include <cstdint>
#include <stdexcept>

namespace graphics {
    /**
     * @brief Класс Цвет, хранит компоненты RGB в диапазоне [0, 255].
     */
    class Color {
    private:
        uint8_t r, g, b;
        /** @brief Валидация компонент цвета. */
        void validate(int r, int g, int b) const;

    public:
        /**
         * @brief Конструктор цвета.
         */
        Color(int r = 0, int g = 0, int b = 0);

        uint8_t getR() const;
        uint8_t getG() const;
        uint8_t getB() const;

        friend std::ostream& operator<<(std::ostream& os, const Color& c);
        friend std::istream& operator>>(std::istream& is, Color& c);
    };
}
