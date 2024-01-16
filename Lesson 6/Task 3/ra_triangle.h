#pragma once
#include "Triangle.h"

class ra_triangle : public Triangle {
protected:
    bool check() override;

public:
    ra_triangle(int a_s, int b_s, int c_s, int a_d, int b_d);
};