#pragma once
#include "Triangle.h"

class equil_triangle : public Triangle {
protected:
    bool check() override;

public:
    equil_triangle(int a_s);
};