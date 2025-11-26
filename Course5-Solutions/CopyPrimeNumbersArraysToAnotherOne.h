#pragma once
#include "AddArrayElement.h"
#include "IsPrime.h"

void CopyPrimeNumbersArraysToAnotherOne(int ArrLength, int &ArrayLength2, int Arr[], int ArrDestination[])
{
    for (int i = 0; i < ArrLength; i++)
    {    
        if (IsPrime(Arr[i]) == enPrimeOrNot::prime)
        {
            AddArrayElement(Arr[i], ArrayLength2, ArrDestination);
        }
    }
}
