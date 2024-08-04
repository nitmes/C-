#include <iostream>
#include <vector>
#include <thread>
#include <random>
#include <chrono>
#include <iomanip>

// Функция для суммирования частей векторов
void vector_sum_part(const std::vector<int>& a, const std::vector<int>& b, std::vector<int>& c, size_t start, size_t end) {
    for (size_t i = start; i < end; ++i) {
        c[i] = a[i] + b[i];
    }
}

// Функция для выполнения суммирования с использованием заданного количества потоков
void parallel_vector_sum(const std::vector<int>& a, const std::vector<int>& b, std::vector<int>& c, size_t num_threads) {
    std::vector<std::thread> threads;
    size_t length = a.size();
    size_t block_size = length / num_threads;

    for (size_t i = 0; i < num_threads; ++i) {
        size_t start = i * block_size;
        size_t end = (i == num_threads - 1) ? length : (i + 1) * block_size;
        threads.emplace_back(vector_sum_part, std::cref(a), std::cref(b), std::ref(c), start, end);
    }

    for (auto& thread : threads) {
        thread.join();
    }
}

// Функция для создания случайного вектора
std::vector<int> create_random_vector(size_t size) {
    std::vector<int> vec(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 100);
    for (auto& el : vec) {
        el = dis(gen);
    }
    return vec;
}

int main() {
    std::vector<size_t> sizes = { 1000, 10000, 100000, 1000000 };
    std::vector<size_t> num_threads = {1, 2, 4, 8, 16 };

    std::cout << "Available hardware threads: " << std::thread::hardware_concurrency() << std::endl;

    // Заголовок таблицы
    std::cout << std::setw(10) << "Threads";
    for (const auto& size : sizes) {
        std::cout << std::setw(15) << size;
    }
    std::cout << std::endl;

    // Запуск тестов и вывод результатов
    for (const auto& threads : num_threads) {
        std::cout << std::setw(10) << threads;
        for (const auto& size : sizes) {
            std::vector<int> a = create_random_vector(size);
            std::vector<int> b = create_random_vector(size);
            std::vector<int> c(size);

            auto start_time = std::chrono::high_resolution_clock::now();
            parallel_vector_sum(a, b, c, threads);
            auto end_time = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time).count();

            std::cout << std::setw(15) << duration;
        }
        std::cout << std::endl;
    }

    return 0;
}
