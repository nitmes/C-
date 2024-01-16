#include <iostream>
#include "numcin.h"
#include "numresult.h"

#define MODE 2
#if !defined MODE
#error "Не задан режим, необходимо установить MODE"
#endif 

int main(int argc, char** argv) {
    setlocale(LC_ALL, "Russian");
#ifdef MODE
#if MODE == 1
    std::cout << "Работаю в боевом режиме \n";
#elif MODE == 2
    std::cout << "Работаю в тестовом режиме \n";
    int num1 = 0;
    int num2 = 0;
    int count = 1;
    bool numMode = true;
    num1 = numcin::numcn(num1, count);
    ++count;
    num2 = numcin::numcn(num2, count);
    std::cout<< "Результат сложения: " << numresult::numres(num1, num2) << std::endl;
#else MODE
    std::cout << "Неизвестный режим. Завершение работы \n";
#endif 
#endif
#ifndef MODE
    std::cout << std::endl << "Не определен #error и не указан #define MODE. \n";
#endif
    return 0;
}