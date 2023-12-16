#include <iostream>

class Counter {
private:
	int counter=1;
public:
	void set_counter(int counter) {
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
	Counter c;
	int counter = 0;
	std::string da;
	std::string status;
	std::cout << "�� ������ ������� ��������� �������� ��������? ������� y ��� n: ";
	std::cin >> da;
	if (da == "y") {
		std::cout << "������� ��������� �������� ��������: ";
		std::cin >> counter;
		c.set_counter(counter);
	}
	do {
		std::cout << "������� ������� ('+', '-', '=' ��� 'x'): ";
		std::cin >> status;
		if (status == "+" || status == "-" || status == "=" || status == "x") {
			c.changer(status);
		}
		else {
			std::cout << "�������� ����! \n";
		}
	} while (status != "x");
	return 0;
}