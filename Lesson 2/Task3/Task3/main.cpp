#include <iostream>

struct addres {
	std::string city;
	std::string streat;
	int number_home;
	int number_flat;
	int code;
};
void print(addres& b) {
	std::cout << "�����: " << b.city << "\n";
	std::cout << "�����: "<< b.streat << "\n";
	std::cout << "����� ����: "<< b.number_home << "\n";
	std::cout << "����� ��������: "<< b.number_flat<<"\n";
	std::cout << "������: "<< b.code<< "\n";
}
int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	addres Moscow = {"������","����������",12,564,343276};
	addres SPb = { "�����-���������","����",17,143,193414 };
	print(Moscow);
	print(SPb);
	return 0;
}