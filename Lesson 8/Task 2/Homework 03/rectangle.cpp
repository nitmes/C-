#include "rectangle.h"
#include "Exception.h"

rectangle::rectangle(int side_a, int side_b, int side_c, int side_d, int ang_a, int ang_b, int ang_c, int ang_d) : Quadrangle(side_a, side_b, side_c, side_d, ang_a, ang_b, ang_c, ang_d) {
	Quadrangle::name = "Прямоугольник";
	
	if ((side_a != side_c || side_b != side_d) && (ang_a != 90 || ang_b != 90 || ang_c != 90 || ang_d != 90))
	{
		throw Exception("Ошибика стороны не равны попрано и нет ни одного угла 90 градусов");
	}

	if (side_a != side_c || side_b != side_d)
	{
		throw Exception("Ошибика стороны не равны попрано");
	}

	if (ang_a != 90 || ang_b != 90 || ang_c != 90 || ang_d != 90)
	{
		throw Exception("Ошибка нет ни одного угла 90 градусов");
	}
};