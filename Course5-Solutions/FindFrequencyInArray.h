#pragma once
#include <iostream>
#include <string>
#include "ReadPositiveNum.h"

using namespace std;

void ReadArrayOfInt(int &Length, int array[])
{
    Length = ReadPositiveNum("The number of elements you want to add");
    for (int i = 0; i < Length; i++)
    {
        array[i] = ReadPositiveNum(("Element [" + to_string(i) + "]"));
    }
}

void PrintArray(int Length, int array[])
{
    for (int i = 0; i < Length; i++)
    {
        cout << array[i] << " ";
    }
}

int TimesRepeated(int Element, int Array[], int Length)
{
    int Frequency = 0;
    for (int i = 0; i < Length; i++)
    {
        if (Array[i] == Element)
        {
            Frequency++;
        }
    }
    return Frequency;
}
