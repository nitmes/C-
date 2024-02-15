#include <iostream>

int Finder(int* data, int x, int left, int right) {
    int result = -1; 
    while (left <= right) {
        int middle = (left + right) / 2;
        if (data[middle] > x) {
            result = middle;
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }
    return (result);
}


int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	int UserPoint = 0;
	int data[9] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
	//int data[9] = { 14, 16, 19, 33, 56, 56, 56, 69, 72 };
	std::cout << "Введите точку отсчета: ";
	std::cin >> UserPoint;
	std::cout << "Количество элементов в массиве больших, чем " << UserPoint << ": ";
    std::cout << 9-Finder(data, UserPoint, 0, 8) << std::endl;
}