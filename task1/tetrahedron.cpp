#include "tetrahedron.h"
#include <cmath>
#include <utility>
#include <cfloat>
/**
 * @brief Проверяет, образуют ли 4 точки действительный тетраэдр
 * @return true если точки не компланарны (образуют тетраэдр), false иначе
 */
bool Tetrahedron::isValid() const {
    Point3D vecAB = B - A;
    Point3D vecAC = C - A;
    Point3D vecAD = D - A;

    // Вычисляем смешанное произведение векторов (скалярное произведение AD на векторное произведение AB и AC)
    // Если смешанное произведение равно 0, то точки компланарны
    double crossX = vecAB.getY() * vecAC.getZ() - vecAB.getZ() * vecAC.getY();
    double crossY = vecAB.getZ() * vecAC.getX() - vecAB.getX() * vecAC.getZ();
    double crossZ = vecAB.getX() * vecAC.getY() - vecAB.getY() * vecAC.getX();
    double scalarTripleProduct = vecAD.getX() * crossX + vecAD.getY() * crossY + vecAD.getZ() * crossZ;
    return std::abs(scalarTripleProduct) > DBL_EPSILON;
}
/**
 * @brief Конструктор, инициализирующий тетраэдр заданными точками
 * @param a точка A
 * @param b точка B
 * @param c точка C
 * @param d точка D
 */
Tetrahedron::Tetrahedron(const Point3D& a, const Point3D& b,
                         const Point3D& c, const Point3D& d)
    : A(a), B(b), C(c), D(d)
{
    if (!isValid()) {
        throw std::invalid_argument("точки не образуют тетрайдер,тк они компланарны");
    }
}

/**
 * @brief Копирующий конструктор
 * @param other другой тетраэдр, значения которого копируются
 */
Tetrahedron::Tetrahedron(const Tetrahedron& other)
    : A(other.A), B(other.B), C(other.C), D(other.D)
{
}

/**
 * @brief Конструктор перемещения
 * @param other временный тетраэдр, из которого заимствуются точки
 */
Tetrahedron::Tetrahedron(Tetrahedron&& other) noexcept
    : A(std::move(other.A)), B(std::move(other.B)),
      C(std::move(other.C)), D(std::move(other.D))
{
}

/**
 * @brief Копирующий оператор присваивания
 * @param other другой тетраэдр, который копируем
 * @return ссылка на текущий объект
 */
Tetrahedron& Tetrahedron::operator=(const Tetrahedron& other)
{
    if (this != &other) {
        A = other.A;
        B = other.B;
        C = other.C;
        D = other.D;
      if (!isValid()) {
            throw std::invalid_argument("точки не образуют тетрайдер,тк они компланарны");
        }
    }
    return *this;
}

/**
 * @brief Перемещающий оператор присваивания
 * @param other временный тетраэдр
 * @return ссылка на текущий объект
 */
Tetrahedron& Tetrahedron::operator=(Tetrahedron&& other) noexcept
{
    if (this != &other) {
        A = std::move(other.A);
        B = std::move(other.B);
        C = std::move(other.C);
        D = std::move(other.D);
    }
    return *this;
}

/**
 * @brief Вычисляет площадь основания (грани ABC)
 * @return площадь треугольника ABC
 */
double Tetrahedron::getBaseArea() const {
    Point3D vecAB = B - A;
    Point3D vecAC = C - A;

    double cx = vecAB.getY() * vecAC.getZ() - vecAB.getZ() * vecAC.getY();
    double cy = vecAB.getZ() * vecAC.getX() - vecAB.getX() * vecAC.getZ();
    double cz = vecAB.getX() * vecAC.getY() - vecAB.getY() * vecAC.getX();

    return 0.5 * std::sqrt(cx * cx + cy * cy + cz * cz);
}
