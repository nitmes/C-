#include <iostream>

enum class seasons
{
	������,
	�������,
	����,
	������,
	���,
	����,
	����,
	������,
	��������,
	�������,
	������,
	�������
};
std::string enumtostring(seasons season) {
	switch (season) {
	case seasons::������: return "������";
	case seasons::�������: return "�������";
	case seasons::����: return "����";
	case seasons::������: return "������";
	case seasons::���: return "���";
	case seasons::����: return "����";
	case seasons::����: return "����";
	case seasons::������: return "������";
	case seasons::��������: return "��������";
	case seasons::�������: return "�������";
	case seasons::������: return "������";
	case seasons::�������: return "�������";
	}
}
int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	int usernum = 1;												
	do {
		std::cout << "������� ����� ������: ";
		std::cin >> usernum;
		if (usernum >= 1 && usernum <= 12) {
			seasons season = static_cast<seasons>(usernum - 1);
			std::cout << enumtostring(season) << "\n";
		}
		else {
			std::cout << "������������ ����� \n";
		}
	} while (usernum != 0);
	std::cout << "�� �������� \n";
	
	return 0;
}