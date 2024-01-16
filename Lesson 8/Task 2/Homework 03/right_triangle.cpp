#include "right_triangle.h"
#include "triangle.h"
#include "Exception.h"

right_triangle::right_triangle(int side_a, int side_b, int side_c, int ang_a, int ang_b, int ang_c) : triangle(side_a, side_b, side_c, ang_a, ang_b, ang_c)
{
	triangle::name = "Прямоугольный треугольник";
	
	if (ang_c != 90)
	{
		throw Exception("Нет угла в 90 градусов");
	}

};