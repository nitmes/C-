#include "triangle.h"
// #include "figure.h"

triangle::triangle(int sideLengthA, int sideLengthB, int sideLengthC, int angleA, int angleB, int angleC)
{
	name = "Треугольник";

	have4sides = false;

	this->side_a = side_a;
	this->side_b = side_b;
	this->side_c = side_c;

	this->ang_a = ang_a;
	this->ang_b = ang_b;
	this->ang_c = ang_c;
}
