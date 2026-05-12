#pragma once
#include <iostream>

namespace graphics {
    /** @brief Структура Точка, содержащая абсциссу и ординату. */
    struct Point {
        /** @brief Абсцисса точки */
        double x;
        /** @brief Абсцисса точки */
        double y;

        /**
         * @brief Конструктор точки
         * @param x Значение абсциссы
         * @param y Значение ординаты
         */
        Point(double const  x = 0.0, double const  y = 0.0);
    };

    /**
     * @brief Оператор вывода точки в поток
     * @param os Выходной поток
     * @param p Константная ссылка на точку
     * @return Ссылка на поток
     */
    std::ostream& operator<<(std::ostream& os, const Point& p);
     /**
     * @brief Оператор ввода точки из потока
     * @param is Входной поток
     * @param p Ссылка на точку
     * @return Ссылка на поток
     */
    std::istream& operator>>(std::istream& is, Point& p);
    /**
     * @brief Оператор сравнения точек на равенство
     * @param lhs Левый операнд
     * @param rhs Правый операнд
     * @return true, если точки равны
     */
    bool operator==(const Point& lhs, const Point& rhs);
    /**
     * @brief Оператор сравнения точек на неравенство
     * @param lhs Левый операнд
     * @param rhs Правый операнд
     * @return true, если точки не равны
     */
    bool operator!=(const Point& lhs, const Point& rhs);
}
