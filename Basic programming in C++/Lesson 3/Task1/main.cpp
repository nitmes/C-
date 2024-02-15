#include <iostream>

class calculator {
private :
	double num1;
	double num2;
public:
	double add() {
		return(this->num1 + this->num2);
	}
	double multiply() {
		return(this->num1 * this->num2);
	}
	double subtract_1_2() {
		return(this->num1 / this->num2);
	}
	double subtract_2_1() {
		return(this->num2 / this->num1);
	}
	double divide_1_2() {
		return(this->num1 - this->num2);
	}
	double divide_2_1() {
		return(this->num2 - this->num1);
	}
	bool set_num1(double num1) {
		if (num1 != 0) {
			this->num1 = num1;
			return true;
		}
		else {
			return false;
		}
	}
	bool set_num2(double num2) {
		if (num2 != 0) {
			this->num2 = num2;
			return true;
		}
		else {
			return false;
		}
	}
};
int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	calculator c;
	double num1 = 0;
	double num2 = 0;
	std::string exit;
	do {
		do {
			std::cout << "Введите num1: ";
			std::cin >> num1;
			if (num1 == 0) {
				std::cout << "Неверный ввод! \n";
			}
		} while (c.set_num1(num1) == false);
		do {
			std::cout << "Введите num2: ";
			std::cin >> num2;
			if (num2 == 0) {
				std::cout << "Неверный ввод! \n";
			}
		} while (c.set_num2(num2) == false);
		std::cout << "num1 + num2 = " << c.add() << "\n";
		std::cout << "num1 * num2 = " << c.multiply() << "\n";
		std::cout << "num1 / num2 = " << c.subtract_1_2() << "\n";
		std::cout << "num2 / num1 = " << c.subtract_2_1() << "\n";
		std::cout << "num1 - num2 = " << c.divide_1_2() << "\n";
		std::cout << "num2 - num1 = " << c.divide_2_1() << "\n";
		std::cout << "Введите 'exit' для выхода: ";
		std::cin >> exit;
	} while (exit != "exit");
	return 0;
}