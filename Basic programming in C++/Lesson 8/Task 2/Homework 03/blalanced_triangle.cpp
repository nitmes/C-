#include "blalanced_triangle.h"
#include "Exception.h"

blalanced_triangle::blalanced_triangle(int side_a, int side_b, int side_c, int ang_a, int ang_b, int ang_c) : triangle(side_a, side_b, side_c, ang_a, ang_b, ang_c)
{
	triangle::name = "�������������� �����������";

	if ((side_a != side_b && side_b != side_c) && (ang_a != ang_b && ang_b != ang_c))
	{
		throw Exception("������ ������ ��� ������� �� �����, �� ���� �� ����� �� ����� 60");
	}

	if (side_a != side_b && side_b != side_c)
	{
		throw Exception("������ ������ ��� ������� �� �����");
	}

	if (ang_a != ang_b && ang_b != ang_c)
	{
		throw Exception("�� ���� �� ����� �� ����� 60");
	}
};
