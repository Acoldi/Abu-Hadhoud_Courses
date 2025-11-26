#pragma once
#include "FindNumberInArray.h"
#include "IsNumberInArray.h"
#include "AddArrayElement.h"

void CopyDistinctArrayNumbers(int ArrLength, int &ArrayLength2, int Arr[], int ArrDestination[])
{
    for (int i = 0; i < ArrLength; i++)
    {    
        if (!IsNumberInArray(Arr[i], ArrDestination, ArrayLength2))
        {
            AddArrayElement(Arr[i], ArrayLength2, ArrDestination);
        }
    }
}
