#pragma once
#include "RandomNumber.h"
#include "Swap.h"

void ShuffleArrayElements(int Length, int arr[])
{
    for (int i = 0; i < Length; i++)
    {
        Swap(arr[randomNumber(0, Length - 1)], arr[randomNumber(0, Length - 1)]);
    }
}
