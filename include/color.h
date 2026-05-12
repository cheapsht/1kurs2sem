#pragma once
#include <iostream>
#include <cstdint>
#include <stdexcept>

namespace graphics {
    /** @brief Класс Цвет, хранит компоненты RGB в диапазоне [0, 255]. */
    class Color {
    private:
        uint8_t r, g, b;
    /**
         * @brief Валидация компонент цвета.
         * 
         * Проверяет, что все три компоненты (r, g, b) принадлежат диапазону [0, 255].
         * Если хотя бы одно значение выходит за пределы, выбрасывает исключение.
         * 
         * @param r Значение красной компоненты 
         * @param g Значение зелёной компоненты 
         * @param b Значение синей компоненты 
         */
        void validate(const int r, const int g, const int b) const;
    public:
        /**
         * @brief Конструктор цвета.
         * @param r Значение красной компоненты.
         * @param g Значение зеленой компоненты.
         * @param b Значение синей компоненты.
         */
        Color(const int r = 0, const int g = 0,const int b = 0);
        /** @brief Получение значения красной компоненты. */
        uint8_t getR() const;
        /** @brief Получение значения зеленой компоненты. */
        uint8_t getG() const;
        /** @brief Получение значения синей компоненты. */
        uint8_t getB() const;
        /**
         * @brief Оператор вывода цвета в поток.
         * @param os Выходной поток.
         * @param c Константная ссылка на объект цвета.
         * @return Ссылка на поток.
         */
        friend std::ostream& operator<<(std::ostream& os, const Color& c);
        /**
         * @brief Оператор ввода цвета из потока.
         * @param is Входной поток.
         * @param c Ссылка на объект цвета.
         * @return Ссылка на поток.
         */
        friend std::istream& operator>>(std::istream& is, Color& c);
    };
}
