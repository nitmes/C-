#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include <algorithm>
#include <iterator>

template<typename Iterator, typename Function>
void parallel_for_each(Iterator first, Iterator last, Function func, std::size_t min_block_size = 1000) {
    std::size_t distance = std::distance(first, last);

    if (distance <= min_block_size) {
        std::for_each(first, last, func);
    }
    else {
        Iterator mid = first;
        std::advance(mid, distance / 2);
        std::future<void> first_half = std::async(std::launch::async, parallel_for_each<Iterator, Function>, first, mid, func, min_block_size);
        parallel_for_each(mid, last, func, min_block_size);
        first_half.get();
    }
}


int main() {
    std::vector<int> vec(10000, 5);
    parallel_for_each(vec.begin(),vec.end(), [](int& n) { n *= 13; },1000);
   
    std::cout << "First element: " << vec[0] << std::endl;
    std::cout << "Last element: " << vec.back() << std::endl;

    return 0;
}
