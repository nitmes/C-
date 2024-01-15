#include <iostream>

class Counter {
private:
	int counter;
public:
	Counter() {
		this->counter = 1;
	}
	Counter(int counter) {
		this->counter = counter;
	}
	void increase() {
		this->counter += 1;
	}
	void decrease() {
		this->counter -= 1;
	}
	int output() {
		 return(this->counter);
	}
};
int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	int counter = 0;
	std::string status;
	std::string da; 
	std::cout << "�� ������ ������� ��������� �������� ��������? ������� y ��� n: ";
	std::cin >> da;
	if (da == "y") {
		std::cout << "������� ��������� �������� ��������: ";
		std::cin >> counter;
	}
	else if (da == "n") {
		counter = 1;
	}
	do {
		std::cout << "������� ������� ('+', '-', '=' ��� 'x'): ";
		std::cin >> status;
		Counter g(counter);
		if (status == "+") {
			g.increase();
		}
		else if (status == "-") {
			g.decrease();
		}
		else if (status == "=") {
			std::cout<<g.output()<<"\n";
		}
		else {
			std::cout << "�������� ����! \n";
		}
	} while (status != "x");
	return 0;
}