#pragma once

int CountOfEvenNumbersInArray(int Length, int Arr[])
{
    int count = 0;
    for (int i = 0; i < Length; i++)
    {
        if (Arr[i] % 2 == 0)
            count++;
    }
    return count;
}
