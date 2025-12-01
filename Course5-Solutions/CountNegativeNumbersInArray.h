#pragma once

int CountOfNegativeNumbersInArray(int Length, int Arr[])
{
    int count = 0;
    for (int i = 0; i < Length; i++)
    {
        if (Arr[i] < 0)
            count++;
    }
    return count;
}
