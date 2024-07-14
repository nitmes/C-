#include <iostream>

class functor {
    int CountMulThree;
    int SumNums; 

public:
    functor(const int sumNums = 0, const int countMulThree = 0)
        : SumNums(sumNums), CountMulThree(countMulThree) {}

    void operator()(int num) { // определение оператора круглых скобок
        if (num % 3 == 0) {
            CountMulThree++;
        }
        SumNums += num;
    }

    void printResults() const {
        std::cout << "Sum of numbers: " << SumNums << std::endl;
        std::cout << "Count of multiples of three: " << CountMulThree << std::endl;
    }
};

int main() {
    int userNum = 0;
    functor f(0, 0);
    do {
        std::cout << "Enter num or 0 to exit: ";
        std::cin >> userNum;
        if (userNum != 0) {
            f(userNum);
        }
    } while (userNum != 0);

    f.printResults();

    return 0;
}
