#include <iostream>
#include <string>
#include "function.h"

int main() {
    setlocale(LC_ALL, "Russian");
    int x, y;
    int action;
    bool check = false;
    std::string operation;
    std::cout << "������� ������ �����: ";
    std::cin >> x;
    std::cout << "������� ������ �����: ";
    std::cin >> y;
    do {
        std::cout << "�������� �������� (1 - ��������, 2 ���������, 3 - ���������, 4 - �������, 5 - ���������� � �������): ";
        std::cin >> action;
        if (action <= 5 && action >= 1){
            check = true;
        }
        else
        {
            std::cout << "������! ��������� ����� �� ��������! \n";
        }
    } while (!check);
    if (action == 1){
        std::cout << x << " " << "����" << " " << y << " = " << add(x, y) << "\n";
    }
    else if (action == 2){
        std::cout << x << " " << "�����" << " " << y << " = " << sub(x, y) << "\n";
    }
    else if (action == 3){
        std::cout << x << " " << "��������" << " " << y << " = " << mul(x, y) << "\n";
    }
    else if (action == 4) {
        std::cout << x << " " << "������" << " " << y << " = " << divy(x, y) << "\n";
    }
    else{
        std::cout << x << " " << "� �������" << " " << y << " = " << exp(x, y) << "\n";
    };
}