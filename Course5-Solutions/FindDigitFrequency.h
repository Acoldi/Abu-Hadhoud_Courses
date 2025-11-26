#pragma once
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int FindDigitFrequency(int Digit, int Number)
{
    int Remainder = 0, Counter = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number /= 10;
        if (Remainder == Digit)
            Counter += 1;
    }
    return Counter;
}
