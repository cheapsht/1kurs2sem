#pragma once
#include <string>
#include <iostream>
#include "Color.h"

namespace graphics {
    /** @brief Класс Шрифт, хранит название, цвет и размер. */
    class Font {
    private:
        std::string name;
        Color color;
        int size;
    public:
        /**
         * @brief Конструктор шрифта.
         * @throws std::invalid_argument Если размер <= 0.
         */
        Font(const std::string& name = "Arial", const Color& color = Color(), int size = 12);

        const std::string& getName() const;
        const Color& getColor() const;
        int getSize() const;

        void setName(const std::string& name);
        void setColor(const Color& color);
        void setSize(int size);

        friend std::ostream& operator<<(std::ostream& os, const Font& f);
        friend std::istream& operator>>(std::istream& is, Font& f);
    };
}
