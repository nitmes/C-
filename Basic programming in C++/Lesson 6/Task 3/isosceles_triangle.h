#pragma once
#include "Triangle.h"

class isosceles_triangle : public Triangle {
protected:
    bool check() override;

public:
    isosceles_triangle(int a_s, int b_s, int a_d, int b_d);
};