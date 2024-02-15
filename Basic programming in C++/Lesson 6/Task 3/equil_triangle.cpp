#include "equil_triangle.h"

bool equil_triangle::check() {
    return Triangle::check() && (a_s == b_s && b_s == c_s) && (a_d == 60 && b_d == 60 && c_d == 60);
}

equil_triangle::equil_triangle(int a_s) : Triangle(a_s, a_s, a_s, 60, 60, 60) {
    name = "Равносторонний треугольник";
}
