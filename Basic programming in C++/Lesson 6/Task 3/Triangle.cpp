#include <iostream>
#include "Triangle.h"

Triangle::Triangle(int a_s, int b_s, int c_s, int a_d, int b_d, int c_d)
    : a_s(a_s), b_s(b_s), c_s(c_s), a_d(a_d), b_d(b_d), c_d(c_d) {
    name = "Треугольник";
    count_sides = 3;
    status = check();
}

bool Triangle::check() {
    return (a_d + b_d + c_d) == 180;
}

std::string Triangle::get_sides() {
    return ("a=" + std::to_string(a_s) + " " + "b=" + std::to_string(b_s) + " " + "c=" + std::to_string(c_s) + "\n");
}

std::string Triangle::get_angles() {
    return ("A=" + std::to_string(a_d) + " " + "B=" + std::to_string(b_d) + " " + "C=" + std::to_string(c_d) + "\n");
}

void Triangle::print_info() {
    Figure::print_info();
    std::cout << "Стороны: ";
    std::cout << get_sides();
    std::cout << "Углы: ";
    std::cout << get_angles() << "\n";
}