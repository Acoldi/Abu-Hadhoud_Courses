#pragma once
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

void PrintReversedNumber(int number)
{
    while (number > 0)
    {
        cout << number % 10 << endl;
        number /= 10;
    }
}
