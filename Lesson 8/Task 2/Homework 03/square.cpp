#include "square.h"
#include "Exception.h"

square::square(int side_a, int side_b, int side_c, int side_d, int ang_a, int ang_b, int ang_c, int ang_d) : Quadrangle(side_a, side_b, side_c, side_d, ang_a, ang_b, ang_c, ang_d) {
	Quadrangle::name = "�������";

	if ((side_a != side_b || side_b != side_c || side_c != side_d)
		&& (ang_a != 90 || ang_b != 90 || ang_c != 90 || ang_d != 90))
	{
		throw Exception("��� ������� �� ����� � ��� ���� �� 90 ��������");
	}

	if (side_a != side_b || side_b != side_c || side_c != side_d)
	{
		throw Exception("��� ������� �� �����");
	}

	if (ang_a != 90 || ang_b != 90 || ang_c != 90 || ang_d != 90)
	{
		throw Exception("��� ���� �� 90 ��������");
	}
}