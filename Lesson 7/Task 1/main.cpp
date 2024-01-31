#include <iostream>

#define MODE 0
#ifndef MODE
#error "���������� ���������� MODE"
#endif
#if MODE == 0
void trainingMode() {
    std::cout << "������� � ������ ����������\n";
}
#elif MODE == 1
int add(int a, int b) {
    return a + b;
}
void battleMode() {
    std::cout << "������� � ������ ������\n";
}
#else
void unknownMode() {
    std::cout << "����������� �����. ���������� ������\n";
}
#endif
int main() {
    setlocale(LC_ALL, "Russian");
#ifdef MODE
#if MODE == 0
    trainingMode();  
#elif MODE == 1
    battleMode();
    int num1, num2;
    std::cout << "������� ������ �����: ";
    std::cin >> num1;
    std::cout << "������� ������ �����: ";
    std::cin >> num2;
    std::cout << "��������� ��������: " << add(num1, num2) << std::endl;
#else
    unknownMode();
#endif
#endif
    return 0;
}
