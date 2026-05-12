#pragma once
#include <iostream>

namespace graphics {
    /** @brief Структура Точка, содержащая абсциссу и ординату. */
    struct Point {
        double x;
        double y;

        /** @brief Конструктор точки. */
        Point(double const  x = 0.0, double const  y = 0.0);
    };

    /** @brief Оператор вывода точки в поток. */
    std::ostream& operator<<(std::ostream& os, const Point& p);
    /** @brief Оператор ввода точки из потока. */
    std::istream& operator>>(std::istream& is, Point& p);
    /** @brief Оператор сравнения точек на равенство. */
    bool operator==(const Point& lhs, const Point& rhs);
    bool operator!=(const Point& lhs, const Point& rhs);
}
