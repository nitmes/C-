#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    int n = 0;
    std::cout << "������� �����: ";
    std::cin >> n;
    if (n < 1) {
        std::cout << "����� ������ ���� ������ 0. \n";
        return 1;
    }
    int* fabo = new int[n + 1];
    fabo[0] = 0;
    if (n > 0) {
        fabo[1] = 1;
    }
    std::cout << "����� ���������: ";
    for (int i = 2; i <= n; ++i) { 
        fabo[i] = fabo[i - 1] + fabo[i - 2];
    }
    std::cout << fabo[n];
    delete[] fabo;
    return 0;
}
