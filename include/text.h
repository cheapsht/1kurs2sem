#pragma once
#include "figure.h"
#include "point.h"
#include "font.h"
#include <string>
#include <iostream>

namespace graphics {
    /** @brief Класс Текст */
    class Text : public Figure {
    private:
        Point bottom_left;
        std::string message;
        Font font;
        void validate() const;

    public:
        Text();
        Text(const Point& pos, const std::string& msg, const Font& f);
        std::string ToString() const override;
        void read(std::istream& is) override;

        void setPosition(const Point& pos);
        void setMessage(const std::string& msg);
        void setFont(const Font& f);

        const Point& getPosition() const;
        const std::string& getMessage() const;
        const Font& getFont() const;

        /** @brief Статическая сериализация в строку. */
        static std::string ToString(const Text& txt);
        /** @brief Статический метод чтения из потока. */
        static Text readFromStream(std::istream& is);

        friend std::ostream& operator<<(std::ostream& os, const Text& txt);
        friend std::istream& operator>>(std::istream& is, Text& txt);
    };
}
