#include "Counter.h"

Counter::Counter() {
    result = 1;
}
Counter::Counter(int counter) {
    result = counter;
}
void Counter::increase() {
    result += 1;
}
void Counter::decrease() {
    result -= 1;
}
int Counter::output() {
    return result;
}