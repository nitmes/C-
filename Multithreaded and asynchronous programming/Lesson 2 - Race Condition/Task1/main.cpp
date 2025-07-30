#include <iostream>
#include <chrono>
#include <thread>

std::atomic<int> count = 0;

void client(const int max_count) {
    for (int i = 0; i < max_count; i++) {
        count.fetch_add(1);
        std::cout << "Queue(c): " << count << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void teller() {
    do {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        count.fetch_add(-1);
        std::cout << "Queue(t): " << count << std::endl;
    } while (count != 0);
}

int main()
{
    int general_count = 0;
    std::thread t1(client, 10);
    std::thread t2(teller);

    t1.join();
    t2.join();
}