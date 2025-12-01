#pragma once

int MaxInArray(int arr[], int Length)
{
    int Max = 0;
    for (int i = 0; i < Length; i++)
    {
        if (arr[i] > Max)
        {
            Max = arr[i];
        }
    }
    return Max;
}

int MinInArray(int arr[], int Length)
{
    int Min = arr[0];
    for (int i = 0; i < Length ; i++)
    {
        if (arr[i] < Min)
        {
            Min = arr[i];
        }
    }
    return Min;
}
