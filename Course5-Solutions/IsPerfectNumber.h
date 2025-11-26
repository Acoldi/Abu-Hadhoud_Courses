#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include "ReadPositiveNum.h"

using namespace std;

bool IsPerfectNumber(int Number)
{
    int Sum = 0;
    for (int i = 1; i < Number; i++)
    {
        if (Number % i == 0)
        {
            Sum += i;
        }
    }
    return Sum == Number;
}

void PrintResult()
{
    if (IsPerfectNumber(ReadPositiveNum("Enter a number")))
        cout << "PERFECT number\n";
    else
        cout << "IMPERFECT number\n";
}

