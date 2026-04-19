#pragma once
/**
 * @class Point3D
 * @brief Класс, описывающий  точку в 3-мерном пространстве тетраэдра,
 * хранит координаты x, y, z и предоставляет базовые операции
 * для работы с точками.
 */
class Point3D
{
private:
/**
* @brief x координата X
* @brief  y координата Y
* @brief z координата Z
*/
double x,y,z;

public:
/**
* @brief Конструктор по умолчанию / с параметрами
* @param x Координата X (по умолчанию 0)
* @param y Координата Y (по умолчанию 0)
* @param z Координата Z (по умолчанию 0)
*/
Point3D(double x = 0, double y = 0, double z = 0);
/**
* @brief копирующий конструктор
* @param other другая точка, которую копируем
*/
Point3D(const Point3D& other);
/**
* @brief перемещающий конструктор
* @param other временная точка
*/
Point3D(Point3D&& other) noexcept;
/**
* @brief возвращает координату x
* @return значение координаты x
*/
double getX() const;
/**
* @brief возвращает координату y
* @return значение координаты y
*/
double getY() const;
/**
* @brief возвращает координату z
* @return значение координаты z
*/
double getZ() const;
/**
* @brief возвращает вектор от текущей точки к `other` (this → other).
* @param otherк коонечная точка вектора
* @return вектор между точками
*/
Point3D operator-(const Point3D& other) const;
};
