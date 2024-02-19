#include <iostream>

void print_dynamic_array(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void append_to_dynamic_array(int*& arr, int& logical_size, int& actual_size, int new_element) {
    if (logical_size < actual_size) {
        arr[logical_size] = new_element;
        logical_size++;
    }
    else {
        int new_actual_size = actual_size * 2;
        int* new_arr = new int[new_actual_size];
        for (int i = 0; i < logical_size; ++i) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        actual_size = new_actual_size;
        arr[logical_size] = new_element;
        logical_size++;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    int actual_size, logical_size;
    std::cout << "Введите фактический размер массива: ";
    std::cin >> actual_size;

    std::cout << "Введите логический размер массива: ";
    std::cin >> logical_size;

    if (logical_size > actual_size) {
        std::cout << "Ошибка: логический размер массива не может превышать его фактический размер." << std::endl;
        return 0;
    }

    int* dynamic_array = new int[actual_size];

    std::cout << "Введите " << logical_size << " элементов массива:" << std::endl;
    for (int i = 0; i < logical_size; ++i) {
        std::cout << "Введите arr[" << i << "]: ";
        std::cin >> dynamic_array[i];
    }

    std::cout << "Динамический массив: ";
    print_dynamic_array(dynamic_array, logical_size);

    int new_element;
    do {
        std::cout << "Введите элемент для добавления в конец или 0 для завершения: ";
        std::cin >> new_element;
        if (new_element != 0) {
            append_to_dynamic_array(dynamic_array, logical_size, actual_size, new_element);
            std::cout << "Обновленный динамический массив: ";
            print_dynamic_array(dynamic_array, logical_size);
        }
    } while (new_element != 0);

    std::cout << "Спасибо! Окончательный массив: ";
    print_dynamic_array(dynamic_array, logical_size);

    delete[] dynamic_array;
    return 0;
}
