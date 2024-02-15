#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    int n = 0;
    std::cout << "Введите число: ";
    std::cin >> n;
    if (n < 1) {
        std::cout << "Число должно быть больше 0. \n";
        return 1;
    }
    int* fabo = new int[n + 1];
    fabo[0] = 0;
    if (n > 0) {
        fabo[1] = 1;
    }
    std::cout << "Числа Фибоначчи: ";
    for (int i = 2; i <= n; ++i) { 
        fabo[i] = fabo[i - 1] + fabo[i - 2];
    }
    std::cout << fabo[n];
    delete[] fabo;
    return 0;
}
