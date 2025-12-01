#pragma once
#include "IsPrime.h"

void CopyPrimrNumbersOfArray(int Length, int &Length2, int arrSource[], int arrDestination[])
{
    int counter = 0;
    for (int i = 0; i < Length; i++)
    {
        if (IsPrime(arrSource[i]) == enPrimeOrNot::prime)
        {
            arrDestination[counter] = arrSource[i];
            counter++;
        }
    }
    Length2 = counter; // Corrected Length2 assignment
}
