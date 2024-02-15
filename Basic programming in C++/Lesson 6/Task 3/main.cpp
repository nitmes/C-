#include <iostream>
#include <string>
#include "Figure.h"
#include "Triangle.h"
#include "isosceles_triangle.h"
#include "ra_triangle.h"
#include "equil_triangle.h"
#include "Quadrangle.h"
#include "rectangle.h"
#include "square.h"
#include "paralle.h"
#include "rhomb.h"

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	Figure Figure1;//Фигура
	Figure1.print_info();
	Triangle triangle(10, 20, 30, 50, 60, 70);//Треугольник
	Figure* t = &triangle;
	t->print_info();
	ra_triangle r_triangle(10, 20, 30, 50, 60);//Прямоугольный
	Figure* ra_t = &r_triangle;
	ra_t->print_info();
	ra_triangle pra_triangle(10, 20, 30, 50, 40);//Прямоугольный
	Figure* pra_t = &pra_triangle;
	pra_t->print_info();
	isosceles_triangle isosceles_triangle(10, 20, 50, 60);//
	Figure* i_t = &isosceles_triangle;
	i_t->print_info();
	equil_triangle equil_triangle(30);//
	Figure* e_t = &equil_triangle;
	e_t->print_info();
	Quadrangle qudrangle(10, 20, 30, 40, 50, 60, 70, 80);//
	Figure* q = &qudrangle;
	q->print_info();
	rectangle rectangle(10, 20);//
	Figure* f_rectangle = &rectangle;
	f_rectangle->print_info();
	square square(20);//
	Figure* f_square = &square;
	f_square->print_info();
	paralle paralle(20, 30, 30, 40);//
	Figure* f_parallelogram = &paralle;
	f_parallelogram->print_info();
	rhomb rhomb(30, 30, 40);//
	Figure* f_rhomb = &rhomb;
	f_rhomb->print_info();
	return 0;
}