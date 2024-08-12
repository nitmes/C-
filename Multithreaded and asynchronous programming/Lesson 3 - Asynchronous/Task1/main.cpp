#include <iostream>
#include <vector>
#include <future>
#include <algorithm>

int find_min_index(const std::vector<int>& arr, int start, int end) {
    int min_index = start;
    for (int i = start + 1; i < end; ++i) {
        if (arr[i] < arr[min_index]) {
            min_index = i;
        }
    }
    return min_index;
}


void selection_sort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
        std::promise<int> promise;
        std::future<int> future = promise.get_future();
        std::thread([&promise, &arr, i, n]() {
            int min_index = find_min_index(arr, i, n);
            promise.set_value(min_index);
            }).detach();
            int min_index = future.get();
            std::swap(arr[i], arr[min_index]);
    }
}

int main() {
    std::vector<int> arr = { 103,75,64,34, 25,9, 12, 7,22, 11 };

    std::cout << "Initial array: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    selection_sort(arr);

    std::cout << "Sorted array: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
