#pragma once
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int SumOfDigits(int Number)
{
    int Remainder = 0, Sum = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Sum += Remainder;
        Number /= 10;
    }
    return Sum;
}
