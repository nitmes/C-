#include <iostream>

int febo(int i) {
	if (i == 1) {
		return 0;
	}
	else if (i == 2) {
		return 1;
	}
	return febo(i - 1) + febo(i - 2);
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	int n = 0;
	std::cout << "Введите число:";
	std::cin >> n;
	std::cout << "Числа Фибоначчи: ";
	for (int i = 1; i <= n; ++i) {
		std::cout << febo(i) << " ";
	}
	return 0;
}