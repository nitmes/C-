#include <iostream>
#include "numcin.h"


int numcin::numcn(int num, int count)
{
    std::cout << "������� ����� " << count << ": ";
    std::cin >> num;

    return num;
}