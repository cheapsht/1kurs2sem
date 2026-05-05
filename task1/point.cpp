#include "point.h"
#include <cmath>
/**
 * @brief конструктор, инициализирующий точку заданными координатами
 * @param x координата x
 * @param y координата y
 * @param z координата z
 */
Point3D::Point3D(double const x,const  double y, const double z)
    : x(x), y(y), z(z)
{
}
/**
 * @brief конструктор копирования
 * @param other другой объект Point3D, значения координат которого копируются
 */
Point3D::Point3D(const Point3D& other)
    : x(other.x), y(other.y), z(other.z)
{
}
/**
 * @brief конструктор перемещения
 * @param other временный объект Point3D, из которого заимствуются координаты
 */
Point3D::Point3D(Point3D&& other) noexcept
    : x(other.x), y(other.y), z(other.z)
{
}

double Point3D::getX() const { return x; }
double Point3D::getY() const { return y; }
double Point3D::getZ() const { return z; }

/**
 * @brief копирующий оператор присваивания
 * @param other другая точка, которую копируем
 * @return ссылка на текущий объект
 */
Point3D& Point3D::operator=(const Point3D& other)
{
    if (this != &other) {
        x = other.x;
        y = other.y;
        z = other.z;
    }
    return *this;
}

/**
 * @brief перемещающий оператор присваивания
 * @param other временная точка
 * @return ссылка на текущий объект
 */
Point3D& Point3D::operator=(Point3D&& other) noexcept
{
    if (this != &other) {
        x = other.x;
        y = other.y;
        z = other.z;
    }
    return *this;
}

/**
 * @brief оператор вычитания двух точек
 * @param other точка, вычитаемая из текущей
 * @return новый объект Point3D, представляющий разность координат
*/
Point3D Point3D::operator-(const Point3D& other) const
{
    return Point3D(other.x -x, other.y-y, other.z - z);
}
/**
 * @brief вычисляет евклидово расстояние между двумя точками в трёхмерном пространстве
 * @param A первая точка
 * @param B вторая точка
 * @return расстояние между точками A и B
 */
double Point3D::distance(const Point3D& A, const Point3D& B)
{
    Point3D vec = A - B;
    return sqrt(vec.getX() * vec.getX() +
                vec.getY() * vec.getY() +
                vec.getZ() * vec.getZ());
}
