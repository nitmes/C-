#include "printFigure.h"
#include <iostream>
#include "Exception.h"
#include <exception>

void printFigure(figure* figure)
{
	std::cout << std::endl;
	std::cout << figure->get_name() << ":" << std::endl;

	std::cout << "Стороны: ";
	std::cout << " a = " << figure->get_side_a() << ", b = " << figure->get_side_b() << ", c = " << figure->get_side_c();
	if (figure->get_have4sides())
	{
		std::cout << ", d = " << figure->get_side_d() << std::endl;
	}
	else { std::cout << std::endl; }

	std::cout << "Углы: ";
	std::cout << " A = " << figure->get_ang_a() << ", B = " << figure->get_ang_b() << ", C = " << figure->get_ang_c();
	if (figure->get_have4sides()) { std::cout << ", D = " << figure->get_ang_d() << std::endl; }
	else { std::cout << std::endl; }
}