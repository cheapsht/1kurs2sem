#include <iostream>
#include "class.h"
#include "tetrahedron.h"
/**
* @brief точка входа в программу
* @return 0, если программа выполнена успешно
*/
int main() {
    Point3D A(1.0, 1.0, 1.0);
    Point3D B(1.0, -1.0, -1.0);
    Point3D C(-1.0, 1.0, -1.0);
    Point3D D(-1.0, -1.0, 1.0);

    Tetrahedron t(A, B, C, D);

    std::cout << "Площадь основания: " << t.getBaseArea() << std::endl;

    return 0;
}
