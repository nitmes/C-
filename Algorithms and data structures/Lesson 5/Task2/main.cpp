#include <iostream>
#include <cmath>

void print_pyramid(int* arr, int size) {
    int level = 1;
    int current = 2;
    int printed = 0;
    int parent = 0;
    std::cout << "0 root " << arr[printed++] << std::endl;
    while (printed < size) {
        int half = current / 2;
        for (int i = 0; i < current && printed < size; ++i) {
            if (printed <= half) {
                parent = (printed) / 2;
            }
            else {
                parent = (printed-1) / 2;
            }
            std::cout << level << " ";
            if (i % 2 == 0) {
                std::cout << "left (" << arr[parent] << ") " << arr[printed++] << std::endl;
            }
            else if (i % 2 != 0) {
                std::cout << "right (" << arr[parent] << ") " << arr[printed++] << std::endl;
            }
        }
        current *= 2;
        level++;
    }
}
void current_position(int* arr, int current) {
    int parent = (current - 1) / 2;
    int level = static_cast<int>(std::floor(std::log2(current + 1)));
        std::cout << level << " ";
        if (current == 0) {
            std::cout << "root " << arr[current] << std::endl;
        }
        else if (current % 2 != 0) {
            std::cout << "left (" << arr[parent] << ") " << arr[current] << std::endl;
        }
        else if (current % 2 == 0) {
            std::cout << "right (" << arr[parent] << ") " << arr[current] << std::endl;
        }
}
int travel(std::string command,int current,int size){
    int level = static_cast<int>(std::floor(std::log2(current + 1)));
    if (command == "right") {
        if (2 * current + 2 <= size) {
            return(2 * current + 2);
        }
        else {
            std::cout << "Ошибка! Отсутствует правый потомок \n";
            return(current);
        }
    }
    else if (command == "left") {
        if (2 * current + 1 <= size) {
            return(2 * current + 1);
        }
        else {
            std::cout << "Ошибка! Отсутствует левый потомок \n";
            return(current);
        }
    }
    else if (command == "up" ) {
        if ( current!= 0) {
            return((current-1)/2);
        }
        else {
            std::cout << "Ошибка! Отсутствует родитель \n";
            return(current);
        }
    }
}
int main(int argc, char** argv) {
    setlocale(LC_ALL, "Russian");
    int current_pos = 0;
    int arr[] = { 94, 67, 18, 44, 55, 12, 6, 42, };
    int size = sizeof(arr) / sizeof(arr[0]);
    std::string com="alala";
    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Пирамида: \n";
    print_pyramid(arr, size);
    std::cout << "Вы находитесь здесь: ";
    current_position(arr, current_pos);
    do {
        int newcurrent_pos = 0;
        std::cout << "Введите команду(up,right,left,exit): ";
        std::cin >> com;
        if (com == "up" || com == "right" || com == "left"||com=="exit") {
            newcurrent_pos = travel(com, current_pos, size);
            std::cout << "Вы находитесь здесь: ";
            current_position(arr, newcurrent_pos);
            current_pos = newcurrent_pos;
        }
        else {
            std::cout << "Неверная команда! \n";
            std::cout << "Вы находитесь здесь: ";
            current_position(arr, current_pos);
        }
    } while (com != "exit");
    return 0;
}
