#include "tetrahedron.h"
#include <cmath>

double Tetrahedron::equilateralTriangleArea(double side)
{
    return (sqrt(3) / 4.0) * side * side;
}
