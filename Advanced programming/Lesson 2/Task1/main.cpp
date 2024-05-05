#include <iostream>

class smart_array {
private:
    int* data; 
    int size;  
    int capacity;

public:
    smart_array(int initial_capacity) : size(0), capacity(initial_capacity) {
        data = new int[capacity];
    }
    void add_element(int element) {
        if (size >= capacity) {
            throw std::out_of_range("Array capacity exceeded");
        }
        data[size++] = element;
    }
    int get_element(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
    ~smart_array() {
        delete[] data;
    }
};

int main() {
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        std::cout << arr.get_element(1) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
