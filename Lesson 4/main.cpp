#include <iostream>
#include <fstream>
#include <string>

class address {
private:
	std::string city;
	std::string streat;
	int number;
	int flat;
public:
	address(std::string city="Санкт-Петербург", std::string streat="Пушкинская", int number=123, int flat=1323) {
		this->city = city;
		this->streat = streat;
		this->number = number;
		this->flat = flat;
	}
	std::string ad() {
		std::string ad;
		ad = this->city + ", " + this->streat + ", " + std::to_string(this->number) + ", " + std::to_string(this->flat)+"\n";
		return(ad);
	}
};

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	int count=0;
	std::string city;
	std::string streat;
	int number;
	int flat;
	std::ifstream f;
	std::ofstream g;
	f.open("in.txt");
	g.open("out.txt");
	f >> count;
	address* addresses = new address[count];
	for (int i = 0; i < count; ++i) {
		f >> city;
		f >> streat;
		f >> number;
		f >> flat;
		addresses[i] = address(city, streat, number, flat);
	}
	for (int i = 0; i < count; ++i) {
		g << addresses[i].ad();
	}
	f.close();
	g.close();
	delete[] addresses;
	return 0;
}