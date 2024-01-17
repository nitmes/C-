#include <iostream>
#include "numcin.h"
#include "numresult.h"

#define MODE 2

#if !defined MODE || (MODE != 1 && MODE != 2)
#error "Необходимо установить MODE в 1 или 2"
#endif
int main(int argc, char** argv) {
    setlocale(LC_ALL, "Russian");

#ifdef MODE
#if MODE == 1
    std::cout << "Работа в тестовом режиме\n";
#elif MODE == 2
    std::cout << "Работа в боевом режиме\n";
    int num1 = 0;
    int num2 = 0;
    int count = 1;
    num1 = numcin::numcn(num1, count);
    ++count;
    num2 = numcin::numcn(num2, count);
    std::cout << "Результат сложения: " << numresult::numres(num1, num2) << std::endl;
#else
    std::cout << "Неизвестный режим. Завершение программы\n";
#endif
#endif

#ifndef MODE
    std::cout << std::endl << "Не определена константа MODE. \n";
#endif

    return 0;
}
