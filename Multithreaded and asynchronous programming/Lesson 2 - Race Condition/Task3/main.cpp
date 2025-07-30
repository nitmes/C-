#include <iostream>
#include <mutex>
#include <vector>
#include <thread>
#include <chrono>

class Data {
private:
    int value;
public:
    Data (int input_val) : value(input_val) {}
    ~Data () {}
    int getVal() {return this->value;}
    void setVal(int _a) {this->value = _a;}
    std::mutex mutex;
};

void swapLock(Data& _a, Data& _b) {
    std::lock (_a.mutex, _b.mutex);
    std::lock_guard<std::mutex> lck_guard1 (_a.mutex, std::adopt_lock);
    std::lock_guard<std::mutex> lck_guard2 (_b.mutex, std::adopt_lock);
    int temp = _a.getVal();
    _a.setVal(_b.getVal());
    _b.setVal(temp);
}

void swapScopedLock(Data& _a, Data& _b) {
    std::lock(_a.mutex, _b.mutex);  // Блокируем оба мьютекса
    std::lock_guard<std::mutex> lock_a(_a.mutex, std::adopt_lock);
    std::lock_guard<std::mutex> lock_b(_b.mutex, std::adopt_lock);
    int temp = _a.getVal();
    _a.setVal(_b.getVal());
    _b.setVal(temp);
}

void swapUniqueLock (Data& _a, Data& _b) {
    std::unique_lock<std::mutex> unq_lock1 (_a.mutex, std::defer_lock);
    std::unique_lock<std::mutex> unq_lock2 (_b.mutex, std::defer_lock);
    std::lock (unq_lock1, unq_lock2);
    int temp = _a.getVal();
    _a.setVal(_b.getVal());
    _b.setVal(temp);
}

enum TYPE {SL,SSL,SUL};
void swapper (Data& _a, Data& _b, TYPE code, int timer);

int main() {
    Data a_data(13), b_data(37);

    std::cout << "Before swapLock: a_data = " << a_data.getVal() << ", b_data = " << b_data.getVal() << std::endl;
    swapLock(a_data, b_data);
    std::cout << "After swapLock: a_data = " << a_data.getVal() << ", b_data = " << b_data.getVal() << std::endl;
    std::cout << std::endl;

    a_data.setVal(31), b_data.setVal(49);
    std::cout << "Before swapScopedLock: a_data = " << a_data.getVal() << ", b_data = " << b_data.getVal() << std::endl;
    swapScopedLock(a_data, b_data);
    std::cout << "After swapScopedLock: a_data = " << a_data.getVal() << ", b_data = " << b_data.getVal() << std::endl;
    std::cout << std::endl;

    a_data.setVal(73), b_data.setVal(97);
    std::cout << "Before swapUniqueLock: a_data = " << a_data.getVal() << ", b_data = " << b_data.getVal() << std::endl;
    swapUniqueLock(a_data, b_data);
    std::cout << "After swapUniqueLock: a_data = " << a_data.getVal() << ", b_data = " << b_data.getVal() << std::endl;
    std::cout << std::endl;
    return 0;
}

void swapper (Data& _a, Data& _b, TYPE code, int timer) {
    switch (code) {
    case SL:
        std::this_thread::sleep_for(std::chrono::milliseconds(timer));
        swapLock(_a, _b);
        break;

    case SSL:
        std::this_thread::sleep_for(std::chrono::milliseconds(timer));
        swapScopedLock(_a, _b);
        break;

    case SUL:
        std::this_thread::sleep_for(std::chrono::milliseconds(timer));
        swapUniqueLock(_a, _b);
        break;
    
    default:
        break;
    }
}