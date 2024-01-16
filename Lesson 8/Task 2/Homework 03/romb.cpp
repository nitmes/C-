#include "romb.h"
#include "Exception.h"

romb::romb(int side_a, int side_b, int side_c, int side_d, int ang_a, int ang_b, int ang_c, int ang_d) : Quadrangle(side_a, side_b, side_c, side_d, ang_a, ang_b, ang_c, ang_d) {
	Quadrangle::name = "Ромб";

	if ((side_a != side_b || side_b != side_c || side_c != side_d)
		&& (ang_a != ang_c || ang_b != ang_d))
	{
		throw Exception("Нет равных противоположных сторон и нет равных противоположных углов");
	}

	if (side_a != side_b || side_b != side_c || side_c != side_d)
	{
		throw Exception("Нет равных противоположных сторон");
	}

	if (ang_a != ang_c || ang_b != ang_d)
	{
		throw Exception("Нет равных противоположных углов");
	}

};