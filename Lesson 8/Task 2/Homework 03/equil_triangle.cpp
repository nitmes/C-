#include "equil_triangle.h"
#include "triangle.h"

equil_triangle::equil_triangle(int side_a, int side_b, int side_c, int ang_a, int ang_b, int ang_c) : triangle(side_a, side_b, side_c, ang_a, ang_b, ang_c)
{
	triangle::name = "�������������� �����������";

	if (side_a != side_c && ang_a != ang_c)
	{
		throw Exception("������ ���� �� ��� ������� �� ����� � ���� �� ��� ���� �� �����");
	}

	if (side_a != side_c)
	{
		throw Exception("������ ���� �� ��� ������� �� �����");
	}

	if (ang_a != ang_c)
	{
		throw Exception("������ ���� �� ��� ���� �� �����");
	}
};