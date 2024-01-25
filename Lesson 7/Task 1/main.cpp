#include <iostream>
#include "numcin.h"
#include "numresult.h"

#define MODE 1

#if !defined MODE
#error "Необходимо установить MODE"
#endif
int main(int argc, char** argv) {
    setlocale(LC_ALL, "Russian");

#ifdef MODE
#if MODE == 0
    std::cout << "Работа в тестовом режиме\n";
#elif MODE == 1
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
    return 0;
}
