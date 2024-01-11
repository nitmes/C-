#include <iostream>

class Counter {
private:
	int counter;
public:
	Counter(int counter) {
		this->counter = counter;
	}
	void changer(std::string status) {
		if (status == "+") {
			this->counter += 1;
		}
		else if (status == "-") {
			this->counter -= 1;
		}
		else if (status == "=") {
			std::cout << this->counter << "\n";
		}
	}
};
int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	int counter = 1;
	Counter c(counter);
	std::string status;
	std::string da;
	std::cout << "�� ������ ������� ��������� �������� ��������? ������� y ��� n: ";
	std::cin >> da;
	if (da == "y") {
		std::cout << "������� ��������� �������� ��������: ";
		std::cin >> counter;
	}
	Counter g(counter);
	do {
		std::cout << "������� ������� ('+', '-', '=' ��� 'x'): ";
		std::cin >> status;
		if (status == "+" || status == "-" || status == "=" || status == "x") {
			if (da == "y") {
				g.changer(status);
			}
			else {
				c.changer(status);
			}
		}
		else {
			std::cout << "�������� ����! \n";
		}
	} while (status != "x");
	return 0;
}