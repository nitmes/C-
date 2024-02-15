#include <iostream>

struct bankBalance {
	int number;
	std::string name;
	int balance;
};
void changebalance(bankBalance&b,int newbalance) {
	b.balance = newbalance;
}
int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	bankBalance b;
	int newbalance = 0;
	std::cout << "ВВедите номер счета: ";
	std::cin >> b.number; 
	std::cout << "Введите имя владельца: ";
	std::cin >> b.name;
	std::cout << "Введите баланс: ";
	std::cin >> b.balance;
	std::cout << "Введите новый баланс: ";
	std::cin >> newbalance;
	changebalance(b, newbalance);
	std::cout << "Ваш счет:" << "Номер счета - " << b.number << ", Имя владельца - " << b.name << ", Баланс - " << b.balance << "$ \n";
	return 0;
}