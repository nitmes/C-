#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

class address {
private:
    std::string city;
    std::string streat;
    int number;
    int flat;

public:
    address(std::string city = "Санкт-Петербург", std::string streat = "Пушкинская", int number = 123, int flat = 1323) {
        this->city = city;
        this->streat = streat;
        this->number = number;
        this->flat = flat;
    }

    std::string ad() const {
        return this->city + ", " + this->streat + ", " + std::to_string(this->number) + ", " + std::to_string(this->flat) + "\n";
    }

    std::string getCity() const {
        return this->city;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    std::ifstream f("in.txt");
    std::ofstream g("out.txt");

    if (!f.is_open() || !g.is_open()) {
        std::cerr << "Файл не открылся.\n";
        return 1;
    }

    int count = 0;
    f >> count;

    address* addresses = new address[count];

    for (int i = 0; i < count; ++i) {
        std::string city, streat;
        int number, flat;

        f >> city >> streat >> number >> flat;
        addresses[i] = address(city, streat, number, flat);
    }
    std::sort(addresses, addresses + count, [](const address& a, const address& b) {
        return a.getCity() < b.getCity();
        });

    for (int i = 0; i < count; ++i) {
        g << addresses[i].ad();
    }

    delete[] addresses;
    f.close();
    g.close();
    return 0;
}
