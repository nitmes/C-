#pragma once
#include "triangle.h"
#include "Exception.h"

class equil_triangle : public triangle
{
public:
	equil_triangle(int side_a, int side_b, int side_c, int ang_a, int ang_b, int ang_c);
};