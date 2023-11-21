#include <iostream>

struct addres {
	std::string city;
	std::string streat;
	int number_home;
	int number_flat;
	int code;
};
void print(addres& b) {
	std::cout << "Город: " << b.city << "\n";
	std::cout << "Улица: "<< b.streat << "\n";
	std::cout << "Номер дома: "<< b.number_home << "\n";
	std::cout << "Номер квартиры: "<< b.number_flat<<"\n";
	std::cout << "Индекс: "<< b.code<< "\n";
}
int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	addres Moscow = {"Москва","Пушкинская",12,564,343276};
	addres SPb = { "Санкт-Петербург","Мира",17,143,193414 };
	print(Moscow);
	print(SPb);
	return 0;
}