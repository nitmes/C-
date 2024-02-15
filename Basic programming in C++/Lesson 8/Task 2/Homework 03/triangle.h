#pragma once
#include "figure.h"

class triangle : public figure
{
public:
	triangle(int side_a, int side_b, int side_c, int ang_a, int ang_b, int ang_c);
};