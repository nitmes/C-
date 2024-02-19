#include <iostream>

void print_pyramid(int* arr, int size) {
    int level = 0;
    int current = 1;
    int printed = 0;
    while (printed < size) {
        for (int i = 0; i < current && printed < size; ++i) {
            std::cout <<level<<" ";
            if (i % 2 == 0) {
                std::cout << "left (" << arr[printed++] << ")" << std::endl;
            }
            else {
                std::cout << "right (" << arr[printed++] << ")" << std::endl;
            }
        }
        current *= 2;
        level++;
    }
}

int main(int argc, char** argv) {
    setlocale(LC_ALL, "Russian");
    int arr[] = { 94, 67, 18, 44, 55, 12, 6, 42, };
    int size = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] <<" ";
    }
    std::cout << "\n";
    std::cout << "Пирамида: \n";
    print_pyramid(arr, size);
    return 0;
}
