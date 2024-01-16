#pragma once
#pragma once
#include "Figure.h"

class Triangle : public Figure {
protected:
    int a_s;
    int b_s;
    int c_s;
    int a_d;
    int b_d;
    int c_d;

    bool check() override;

public:
    Triangle(int a_s, int b_s, int c_s, int a_d, int b_d, int c_d);
    std::string get_sides();
    std::string get_angles();
    void print_info() override;
};