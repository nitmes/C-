#include <iostream>
#include "Counter.h"

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	int counter = 0;
	Counter g;
	std::string status;
	std::string da;
	std::cout << "�� ������ ������� ��������� �������� ��������? ������� y ��� n: ";
	std::cin >> da;
	if (da == "y") {
		std::cout << "������� ��������� �������� ��������: ";
		std::cin >> counter;
		g = Counter(counter);
	}
	else if (da == "n") {
		counter = 1;
	}
	do {
		std::cout << "������� ������� ('+', '-', '=' ��� 'x'): ";
		std::cin >> status;
		if (status == "+") {
			g.increase();
		}
		else if (status == "-") {
			g.decrease();
		}
		else if (status == "=") {
			std::cout << g.output() << "\n";
		}
		else {
			std::cout << "�������� ����! \n";
		}
	} while (status != "x");
	return 0;
}