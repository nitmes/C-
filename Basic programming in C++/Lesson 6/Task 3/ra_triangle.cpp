#include "ra_Triangle.h"

bool ra_triangle::check() {
    return Triangle::check() && c_d == 90;
}

ra_triangle::ra_triangle(int a_s, int b_s, int c_s, int a_d, int b_d): Triangle(a_s, b_s, c_s, a_d, b_d, 90) {
    name = "Прямоугольный треугольник";
}