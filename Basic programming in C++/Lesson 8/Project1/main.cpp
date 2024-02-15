#include <iostream>
#include <string>
#include <exception>

int function(std::string str, int forbiddenLength){
    if (forbiddenLength == str.length()){
        throw std::length_error("Вы ввели слово запретной длины! До свидания");
    };
    return static_cast<int>(str.length());
};

int main() {
    setlocale(LC_ALL, "Russian");
    int length = 0;
    int forbiddenLength = 0;
    std::string str;
    bool check_length = false;
    do {
        std::cout << "Введите запретную длину: ";
        std::cin >> forbiddenLength;
        if (forbiddenLength > 0) {
            check_length = true;
        }
    } while (!check_length);
    try {
        do {
            std::cout << "Введите слово: "; 
            std::cin >> str;
            length = function(str, forbiddenLength);
            std::cout << "Длинна слова \"" << str << "\" равна " << length << std::endl;
        } while (forbiddenLength != length);
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}