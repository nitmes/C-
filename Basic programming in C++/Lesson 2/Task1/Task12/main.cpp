#include <iostream>

enum class seasons
{
	Январь,
	Февраль,
	Март,
	Апрель,
	Май,
	Июнь,
	Июль,
	Август,
	Сентябрь,
	Октябрь,
	Ноябрь,
	Декабрь
};
std::string enumtostring(seasons season) {
	switch (season) {
	case seasons::Январь: return "Январь";
	case seasons::Февраль: return "Февраль";
	case seasons::Март: return "Март";
	case seasons::Апрель: return "Апрель";
	case seasons::Май: return "Май";
	case seasons::Июнь: return "Июнь";
	case seasons::Июль: return "Июль";
	case seasons::Август: return "Август";
	case seasons::Сентябрь: return "Сентябрь";
	case seasons::Октябрь: return "Октябрь";
	case seasons::Ноябрь: return "Ноябрь";
	case seasons::Декабрь: return "Декабрь";
	}
}
int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	int usernum = 1;												
	do {
		std::cout << "Введите номер месяца: ";
		std::cin >> usernum;
		if (usernum >= 1 && usernum <= 12) {
			seasons season = static_cast<seasons>(usernum - 1);
			std::cout << enumtostring(season) << "\n";
		}
		else {
			std::cout << "Неправильный номер \n";
		}
	} while (usernum != 0);
	std::cout << "До свидания \n";
	
	return 0;
}