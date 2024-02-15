#include <iostream>

#define MODE 0
#ifndef MODE
#error "Необходимо установить MODE"
#endif
#if MODE == 0
void trainingMode() {
    std::cout << "Работаю в режиме тренировки\n";
}
#elif MODE == 1
int add(int a, int b) {
    return a + b;
}
void battleMode() {
    std::cout << "Работаю в боевом режиме\n";
}
#else
void unknownMode() {
    std::cout << "Неизвестный режим. Завершение работы\n";
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
    std::cout << "Введите первое число: ";
    std::cin >> num1;
    std::cout << "Введите второе число: ";
    std::cin >> num2;
    std::cout << "Результат сложения: " << add(num1, num2) << std::endl;
#else
    unknownMode();
#endif
#endif
    return 0;
}
