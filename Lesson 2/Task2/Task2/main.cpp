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
	std::cout << "������� ����� �����: ";
	std::cin >> b.number; 
	std::cout << "������� ��� ���������: ";
	std::cin >> b.name;
	std::cout << "������� ������: ";
	std::cin >> b.balance;
	std::cout << "������� ����� ������: ";
	std::cin >> newbalance;
	changebalance(b, newbalance);
	std::cout << "��� ����:" << "����� ����� - " << b.number << ", ��� ��������� - " << b.name << ", ������ - " << b.balance << "$ \n";
	return 0;
}