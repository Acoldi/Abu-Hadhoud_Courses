#pragma once

int SumArrayValue(int Length, int arr[])
{
    int Sum = 0;
    for (int i = 0; i < Length; i++)
    {
        Sum += arr[i];
    }
    return Sum;
}

float AvgOfArray(int Length, int arr[])
{
    return (float) SumArrayValue(Length, arr) / Length;
}
