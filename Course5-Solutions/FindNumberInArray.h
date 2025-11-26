#pragma once

int FindNumberInArray(int Number, int Length, int Arr[])
{
    for (int i = 0; i < Length; i++)
    {
        if (Arr[i] == Number)
        {
            return i;
        }
    }
    return -1;
}
