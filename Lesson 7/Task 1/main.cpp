#include <iostream>
#include "numcin.h"
#include "numresult.h"

#define MODE 2
#if !defined MODE
#error "�� ����� �����, ���������� ���������� MODE"
#endif 

int main(int argc, char** argv) {
    setlocale(LC_ALL, "Russian");
#ifdef MODE
#if MODE == 1
    std::cout << "������� � ������ ������ \n";
#elif MODE == 2
    std::cout << "������� � �������� ������ \n";
    int num1 = 0;
    int num2 = 0;
    int count = 1;
    bool numMode = true;
    num1 = numcin::numcn(num1, count);
    ++count;
    num2 = numcin::numcn(num2, count);
    std::cout<< "��������� ��������: " << numresult::numres(num1, num2) << std::endl;
#else MODE
    std::cout << "����������� �����. ���������� ������ \n";
#endif 
#endif
#ifndef MODE
    std::cout << std::endl << "�� ��������� #error � �� ������ #define MODE. \n";
#endif
    return 0;
}