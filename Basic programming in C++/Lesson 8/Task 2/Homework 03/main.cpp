#include <iostream>
#include <string>
#include <windows.h>
#include "figure.h"
#include "triangle.h"
#include "right_triangle.h"
#include "blalanced_triangle.h"
#include "equil_triangle.h"
#include "Quadrangle.h"
#include "rectangle.h"
#include "square.h"
#include "parale.h"
#include "romb.h"
#include "printFigure.h"
#include "Exception.h"



int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	try
	{
		triangle triangle(10, 20, 30, 50, 60, 70);
		printFigure(&triangle);
		std::cout << "������." << std::endl;
	}
	catch (const std::exception& Tr)
	{
		std::cerr << "����������� �� ��� ������. " << std::endl << "�������: ";
		std::cerr << Tr.what() << std::endl;
	}

	try
	{
		right_triangle right_triangle(10, 20, 30, 40, 50, 90);
		printFigure(&right_triangle);
		std::cout << "������." << std::endl;
	}
	catch (const std::exception& rT)
	{
		std::cerr << std::endl;
		std::cerr << "������������� ����������� �� ��� ������. " << std::endl << "�������: ";
		std::cerr << rT.what() << std::endl;
	}

	try
	{
		blalanced_triangle blalanced_triangle(11, 11, 11, 50, 80, 50);
		printFigure(&blalanced_triangle);
		std::cout << "������." << std::endl;
	}
	catch (const std::exception& iT)
	{
		std::cerr << std::endl;
		std::cerr << "�������������� ����������� �� ��� ������. " << std::endl << "�������: ";
		std::cerr << iT.what() << std::endl;
	}

	try
	{
		equil_triangle equil_triangle(11, 11, 11, 60, 60, 60);
		printFigure(&equil_triangle);
		std::cout << "������." << std::endl;
	}
	catch (const std::exception& eT)
	{
		std::cerr << std::endl;
		std::cerr << "�������������� ����������� �� ��� ������. " << std::endl << "�������: ";
		std::cerr << eT.what() << std::endl;
	}

	try
	{
		Quadrangle Quadrangle(10, 20, 30, 40, 90, 90, 100, 80);
		printFigure(&Quadrangle);
		std::cout << "������." << std::endl;
	}
	catch (const std::exception& q)
	{
		std::cerr << std::endl;
		std::cerr << "��������������� �� ��� ������. " << std::endl << "�������: ";
		std::cerr << q.what() << std::endl;
	}

	try
	{
		rectangle rectangle(10, 20, 10, 20, 90, 90, 90, 90);
		printFigure(&rectangle);
		std::cout << "������." << std::endl;
	}
	catch (const std::exception& r)
	{
		std::cerr << std::endl;
		std::cerr << "������������� �� ��� ������. " << std::endl << "�������: ";
		std::cerr << r.what() << std::endl;
	}

	try
	{
		square square(10, 10, 10, 10, 90, 90, 90, 90);
		printFigure(&square);
		std::cout << "������." << std::endl;
	}
	catch (const std::exception& s)
	{
		std::cerr << std::endl;
		std::cerr << "������� �� ��� ������. " << std::endl << "�������: ";
		std::cerr << s.what() << std::endl;
	}

	try
	{
		parale parale(10, 10, 10, 10, 90, 90, 90, 90);
		printFigure(&parale);
		std::cout << "������." << std::endl;
	}
	catch (const std::exception& s)
	{
		std::cerr << std::endl;
		std::cerr << "�������������� �� ��� ������. " << std::endl << "�������: ";
		std::cerr << s.what() << std::endl;
	}

	try
	{
		romb romb(10, 10, 10, 10, 80, 100, 80, 100);
		printFigure(&romb);
		std::cout << "������." << std::endl;
	}
	catch (const std::exception& s)
	{
		std::cerr << std::endl;
		std::cerr << "���� �� ��� ������. " << std::endl << "�������: ";
		std::cerr << s.what() << std::endl;
	}

	
}