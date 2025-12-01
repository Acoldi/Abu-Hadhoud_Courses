#pragma once
#include "AddArrayElement.h"

void CopyArrayUsingAddArrayElement(int ArrLength, int &ArrayLength2, int Arr[], int ArrDestination[])
{
    for (int i = 0; i < ArrLength; i++)
        AddArrayElement(Arr[i], ArrayLength2, ArrDestination);
}
