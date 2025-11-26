#pragma once
#include "AddArrayElement.h"
#include "CheckNumberType.h"

void CopyOddArraysElementsToAnotherOne(int ArrLength, int &ArrayLength2, int Arr[], int ArrDestination[])
{
    for (int i = 0; i < ArrLength; i++)
    {    
        if (CheckNumberType(Arr[i]) == enNumberType::Odd)
        {
            AddArrayElement(Arr[i], ArrayLength2, ArrDestination);
        }
    }
}
