#include <iostream>
#include <cmath>
#include "class.hpp"

using namespace std;
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
