#include <iostream>
#include "Figure.h"


Figure::Figure() : name("������") {}

std::string Figure::get_name() {
    return name;
}

void Figure::print_info() {
    std::cout << name << ": \n";
    if (check()) {
        std::cout << "���������� \n";
    }
    else {
        std::cout << "������������ \n";
    }
    std::cout << "���������� ������: " << count_sides << "\n";
    if (count_sides == 0) {
        std::cout << "\n";
    }
}

bool Figure::check() {
    return count_sides == 0;
}