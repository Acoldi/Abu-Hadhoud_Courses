#pragma once

void AddArrayElement(int number, int &Length, int Arr[])
{
    Arr[Length] = number;
    Length++;
}
