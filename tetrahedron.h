#pragma once
#include "class.h"

/**
 * @class Tetrahedron
 * @brief Класс, описывающий тетраэдр (4 точки в 3D пространстве)
 * и предоставляющий методы для работы с ним.
 */
class Tetrahedron
{
private:
    Point3D A, B, C, D;

public:
    /**
     * @brief Конструктор по умолчанию / с параметрами
     * @param a точка A (по умолчанию в начале координат)
     * @param b точка B (по умолчанию в начале координат)
     * @param c точка C (по умолчанию в начале координат)
     * @param d точка D (по умолчанию в начале координат)
     */
    Tetrahedron(const Point3D& a = Point3D(), const Point3D& b = Point3D(),
                const Point3D& c = Point3D(), const Point3D& d = Point3D());

    /**
     * @brief Копирующий конструктор
     * @param other другой тетраэдр, который копируем
     */
    Tetrahedron(const Tetrahedron& other);

    /**
     * @brief Перемещающий конструктор
     * @param other временный тетраэдр
     */
    Tetrahedron(Tetrahedron&& other) noexcept;

    /**
     * @brief Копирующий оператор присваивания
     * @param other другой тетраэдр, который копируем
     * @return ссылка на текущий объект
     */
    Tetrahedron& operator=(const Tetrahedron& other);

    /**
     * @brief Перемещающий оператор присваивания
     * @param other временный тетраэдр
     * @return ссылка на текущий объект
     */
    Tetrahedron& operator=(Tetrahedron&& other) noexcept;

    /**
     * @brief Вычисляет площадь основания (грани ABC)
     * @return площадь треугольника ABC
     */
    double getBaseArea() const;
};
