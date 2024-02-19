#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    for (int i = 0; i < actual_size; ++i) {
        if (i < logical_size) {
            std::cout << arr[i] << " ";
        }
        else {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    setlocale(LC_ALL, "Russian");
    int actual_size, logical_size;
    std::cout << "������� ����������� ������ �������: ";
    std::cin >> actual_size;
    std::cout << "������� ���������� ������ �������: ";
    std::cin >> logical_size;
    if (actual_size <= logical_size) {
        std::cout << "������! \n";
        return 0;
    }
    int* dynamic_array = new int[actual_size];
    std::cout << "������� " << logical_size << " ��������� �������:" << std::endl;
    for (int i = 0; i < logical_size; ++i) {
        std::cin >> dynamic_array[i];

    }
    std::cout << "������������ ������: ";
    print_dynamic_array(dynamic_array, logical_size, actual_size);
    delete[] dynamic_array;
    return 0;
}
