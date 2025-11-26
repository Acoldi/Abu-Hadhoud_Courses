#pragma once

int CountOfPositiveNumbersInArray(int Length, int Arr[])
{
    int count = 0;
    for (int i = 0; i < Length; i++)
    {
        if (Arr[i] >= 0) // Assuming 0 is considered positive here
            count++;
    }
    return count;
}
