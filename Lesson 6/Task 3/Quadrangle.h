#pragma once
#include "Figure.h"

class Quadrangle : public Figure {
protected:
    int a_s, b_s, c_s, d_s;
    int a_d, b_d, c_d, d_d;

    virtual bool check();
    bool sqad();
    bool parall();
    bool degrees();

public:
    Quadrangle(int a_s, int b_s, int c_s, int d_s, int a_d, int b_d, int c_d, int d_d);
    std::string get_sides();
    std::string get_angles();
    void print_info() override;
};
