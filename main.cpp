#include <iostream>
#include <cmath>
#include "class.hpp"

using namespace std;
/**
 * @brief вычисляет евклидово расстояние между двумя точками в трёхмерном пространстве.
 * @param A первая точка
 * @param B вторая точка
 * @return расстояние между точками A и B.
 */
double distance(const Point3D& A, const Point3D& B);
/**
 * @brief вычисляет площадь равностороннего треугольника по длине стороны
 * @param side длина стороны треугольника
 * @return площадь равностороннего треугольника
 */
double equilateralTriangleArea(double side);
/**
* @brief точка входа в программу
* @return 0, если программа выполнена успешно
*/
int main()
{
    /*координаты точек правильного тетраедара,ребра равны 2*(2^0,5) */
    Point3D A(1,  1,  1);
    Point3D B(1, -1, -1);
    Point3D C(-1,  1, -1);
    Point3D D(-1, -1,  1);

    cout << "Точки правильного тетраэдра:" << endl;
    cout << "A: (" << A.getX() << ", " << A.getY() << ", " << A.getZ() << ")" << endl;
    cout << "B: (" << B.getX() << ", " << B.getY() << ", " << B.getZ() << ")" << endl;
    cout << "C: (" << C.getX() << ", " << C.getY() << ", " << C.getZ() << ")" << endl;
    cout << "D: (" << D.getX() << ", " << D.getY() << ", " << D.getZ() << ")" << endl;
    double side = distance(A, B);
    double area = equilateralTriangleArea(side);

    cout << "Длина ребра основания: " << side << endl;
    cout << "Площадь основания тетраэдра : " << area << endl;

    return 0;
}
double equilateralTriangleArea(double side)
{
    return (sqrt(3) / 4.0) * side * side;
}
double distance(const Point3D& A, const Point3D& B)
{
    Point3D vec = A - B;
    return sqrt(vec.getX() * vec.getX() +
                vec.getY() * vec.getY() +
                vec.getZ() * vec.getZ());
}
