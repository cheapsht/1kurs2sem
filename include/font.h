#pragma once
#include <string>
#include <iostream>
#include "Color.h"
namespace graphics {
    /** @brief Класс Шрифт, хранит название, цвет и размер */
    class Font {
    private:
        /** @brief Название шрифта */
        std::string name;
        /** @brief цвет шрифта */
        Color color;
        /** @brief размер шрифта */
        int size;
    public:
        /**
         * @brief Конструктор шрифта
         * @param name Название шрифта
         * @param color Цвет шрифта
         * @param size Размер шрифта
         */
        Font(const std::string& name = "Arial", const Color& color = Color(),const  int size = 12);
        /** @brief Получение названия шрифта */
        const std::string& getName() const;
        /** @brief Получение цвета шрифта */
        const Color& getColor() const;
        /** @brief Получение размера шрифта */
        int getSize() const;
        /** @brief Установка названия шрифта */
        void setName(const std::string& name);
        /** @brief Установка цвета шрифта */
        void setColor(const Color& color);
        /** @brief Установка размера шрифта */
        void setSize(const int size);
        /**
         * @brief Оператор вывода шрифта в поток
         * @param os Выходной поток
         * @param f Константная ссылка на объект шрифта
         * @return Ссылка на поток
         */
        friend std::ostream& operator<<(std::ostream& os, const Font& f);
        /**
         * @brief Оператор ввода шрифта из потока
         * @param is Входной поток
         * @param f Ссылка на объект шрифта
         * @return Ссылка на поток
         */
        friend std::istream& operator>>(std::istream& is, Font& f);
    };
}
