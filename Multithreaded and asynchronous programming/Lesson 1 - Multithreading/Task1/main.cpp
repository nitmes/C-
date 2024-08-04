#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

// Глобальные переменные для счетчика клиентов и синхронизации
int clientCounter = 0;
const int maxClients = 10;
std::mutex mtx;
std::condition_variable cv;
bool done = false;

void clientThread() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::unique_lock<std::mutex> lock(mtx);
        if (clientCounter < maxClients) {
            ++clientCounter;
            std::cout << "Client added. Total clients: " << clientCounter << std::endl;
        }
        if (clientCounter == maxClients) {
            done = true;
            cv.notify_all();
            break;
        }
    }
}

void operatorThread() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(2));

        std::unique_lock<std::mutex> lock(mtx);
        if (clientCounter > 0) {
            --clientCounter;
            std::cout << "Client served. Total clients: " << clientCounter << std::endl;
        }
        if (done && clientCounter == 0) {
            break;
        }
    }
}

int main() {
    std::thread t1(clientThread);
    std::thread t2(operatorThread);

    t1.join();
    t2.join();

    std::cout << "All clients have been served." << std::endl;
    return 0;
}
