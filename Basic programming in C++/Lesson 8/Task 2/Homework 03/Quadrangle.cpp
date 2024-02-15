#include "Quadrangle.h"
#include "Exception.h"

Quadrangle::Quadrangle(int side_a, int side_b, int side_c, int side_d, int ang_a, int ang_b, int ang_c, int ang_d)
{
	name = "Четыреугольник";

	have4sides = true;

	this->side_a = side_a;
	this->side_b = side_b;
	this->side_c = side_c;
	this->side_d = side_d;

	this->ang_a = ang_a;
	this->ang_b = ang_b;
	this->ang_c = ang_c;
	this->ang_d = ang_d;

	if (ang_a + ang_b + ang_c + ang_d != 360)
	{
		throw Exception("Сумма углов не равна 360");
	}
};