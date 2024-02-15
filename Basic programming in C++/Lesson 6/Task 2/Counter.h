#pragma once

class Counter {
private:
    int result;
public:
    Counter();
    Counter(int counter);
    void increase();
    void decrease();
    int output();
};
