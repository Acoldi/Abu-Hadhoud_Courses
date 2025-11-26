#pragma once

void SumArray(int Arr1[], int Arr2[], int arrDestination[], int Length)
{
    for (int i = 0; i < Length; i++)
    {
        arrDestination[i] = Arr1[i] + Arr2[i];
    }
}
