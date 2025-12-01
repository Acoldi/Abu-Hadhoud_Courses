#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include "FindDigitFrequency.h"

using namespace std;

void PrintAllFrequenciesOfAllDigits(int Number)
{
    int Frequency = 0;
    for (int i = 0; i < 10; i++)
    {
        Frequency = FindDigitFrequency(i, Number);
        if (Frequency > 0)
        {
            cout << "The frequency of " << i << " is " << Frequency << endl;
        }
    }
}
