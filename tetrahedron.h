#pragma once
#include "class.h"

/**
 * @class Tetrahedron
 * @brief Класс, описывающий правильный тетраэдр
 */
class Tetrahedron
{
public:
    /**
     * @brief вычисляет площадь равностороннего треугольника по длине стороны
     * @param side длина стороны треугольника
     * @return площадь равностороннего треугольника
     */
    static double equilateralTriangleArea(double side);
};
