    #include <iostream>

void quick_sort(int* arr, int left, int right) {
    if (left < right) {
        int pivot = arr[(left + right) / 2];
        int i = left;
        int j = right;
        while (i <= j) {
            while (arr[i] < pivot)
                i++;
            while (arr[j] > pivot)
                j--;
            if (i <= j) {
                std::swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }
        quick_sort(arr, left, j);
        quick_sort(arr, i, right);
    }
}

int main(int argc, char** argv) {
    int size = 10;
    int size2 = 15;
    int size3 = 18;
    int mass[10] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    int mass2[15] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    int mass3[18] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };

    quick_sort(mass, 0, size - 1);
    quick_sort(mass2, 0, size2 - 1);
    quick_sort(mass3, 0, size3 - 1);

    std::cout << "mass: ";
    for (int i = 0; i < size; ++i) {
        std::cout << mass[i] << " ";
    }
    std::cout << " \n";
    std::cout << "mass2: ";
    for (int i = 0; i < size2; ++i) {
        std::cout << mass2[i] << " ";
    }
    std::cout << " \n";
    std::cout << "mass3: ";
    for (int i = 0; i < size3; ++i) {
        std::cout << mass3[i] << " ";
    }
    std::cout << " \n";
    return 0;
}
