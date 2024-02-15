#include <iostream>
#include "Quadrangle.h"


Quadrangle::Quadrangle(int a_s, int b_s, int c_s, int d_s, int a_d, int b_d, int c_d, int d_d)
    : a_s(a_s), b_s(b_s), c_s(c_s), d_s(d_s), a_d(a_d), b_d(b_d), c_d(c_d), d_d(d_d) {
    name = "Четырехугольник";
    count_sides = 4;
}

bool Quadrangle::check() {
    return (a_d + b_d + c_d + d_d) == 360;
}

bool Quadrangle::sqad() {
    return (a_s == b_s && b_s == c_s && c_s == d_s);
}

bool Quadrangle::parall() {
    return (a_s == c_s && b_s == d_s);
}

bool Quadrangle::degrees() {
    return (a_d == 90 && b_d == 90 && c_d == 90 && d_d == 90);
}

std::string Quadrangle::get_sides() {
    return ("a=" + std::to_string(a_s) + " " + "b=" + std::to_string(b_s) + " " + "c=" + std::to_string(c_s) + " " + "d=" + std::to_string(d_s) + "\n");
}

std::string Quadrangle::get_angles() {
    return ("A=" + std::to_string(a_d) + " " + "B=" + std::to_string(b_d) + " " + "C=" + std::to_string(c_d) + " " + "D=" + std::to_string(d_d) + "\n");
}

void Quadrangle::print_info() {
    Figure::print_info();
    std::cout << "Стороны: ";
    std::cout << get_sides();
    std::cout << "Углы: ";
    std::cout << get_angles() << "\n";
}
