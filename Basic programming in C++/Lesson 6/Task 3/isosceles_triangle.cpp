#include "isosceles_triangle.h"

bool isosceles_triangle::check() {
    return Triangle::check() && (a_s == c_s) && (a_d == c_d);
}

isosceles_triangle::isosceles_triangle(int a_s, int b_s, int a_d, int b_d): Triangle(a_s, b_s, a_s, a_d, b_d, a_d) {
    name = "Равнобедренный треугольник";
}