#pragma once
#include <iostream>
#include "ReadPositiveNum.h"
#include "RandomNumber.h"

using namespace std;

void FillArrayWithRandomNumbers(int &Length, int array[])
{
    Length = ReadPositiveNum("Enter the array length");
    for (int i = 0; i < Length; i++)
    {
        array[i] = randomNumber(0, 100);
    }
}
