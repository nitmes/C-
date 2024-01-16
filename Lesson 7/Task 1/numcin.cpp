#include <iostream>
#include "numcin.h"


int numcin::numcn(int num, int count)
{
    std::cout << "¬ведите число " << count << ": ";
    std::cin >> num;

    return num;
}