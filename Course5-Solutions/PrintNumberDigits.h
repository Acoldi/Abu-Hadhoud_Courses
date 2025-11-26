#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include "ReverseNumber.h"

using namespace std;

void PrintNumberDigits(int Number)
{
    int Remainder = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number /= 10;
        cout << Remainder << endl;
    }
}
