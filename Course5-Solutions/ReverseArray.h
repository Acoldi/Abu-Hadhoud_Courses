#pragma once

void ReverseArray(int Length, int arrSource[], int arrDestination[])
{
    for (int i = 0; i < Length; i++)
    {
        arrDestination[i] = arrSource[Length - 1 - i];
    }
}
