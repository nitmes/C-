#include "parale.h"
#include "Exception.h"

parale::parale(int side_a, int side_b, int side_c, int side_d, int ang_a, int ang_b, int ang_c, int ang_d) : Quadrangle(side_a, side_b, side_c, side_d, ang_a, ang_b, ang_c, ang_d) {
	Quadrangle::name = "Параллелограм";

	if ((side_a != side_c || side_b != side_d)
		&& (ang_a != ang_c || ang_b != ang_d))
	{
		throw Exception("Ошибка нет попарно равных сторон и нет попарно равных углов");
	}

	if (side_a != side_c || side_b != side_d)
	{
		throw Exception("Ошибка нет попарно равных сторон");
	}

	if (ang_a != ang_c || ang_b != ang_d)
	{
		throw Exception("Ошибка нет попарно равных углов");
	}
}