#include <iostream>
#include <string>
#include "function.h"

int main() {
    setlocale(LC_ALL, "Russian");
    int x, y;
    int action;
    bool check = false;
    std::string operation;
    std::cout << "Введите первое число: ";
    std::cin >> x;
    std::cout << "Введите второе число: ";
    std::cin >> y;
    do {
        std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
        std::cin >> action;
        if (action <= 5 && action >= 1){
            check = true;
        }
        else
        {
            std::cout << "Ошибка! Введенное число не подходит! \n";
        }
    } while (!check);
    if (action == 1){
        std::cout << x << " " << "плюс" << " " << y << " = " << add(x, y) << "\n";
    }
    else if (action == 2){
        std::cout << x << " " << "минус" << " " << y << " = " << sub(x, y) << "\n";
    }
    else if (action == 3){
        std::cout << x << " " << "умножить" << " " << y << " = " << mul(x, y) << "\n";
    }
    else if (action == 4) {
        std::cout << x << " " << "делить" << " " << y << " = " << divy(x, y) << "\n";
    }
    else{
        std::cout << x << " " << "в степени" << " " << y << " = " << exp(x, y) << "\n";
    };
}