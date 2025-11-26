#pragma once
#include "ReadPositiveNum.h"
#include "AddArrayElement.h"

void AddArrayElements(int &Length, int Arr[])
{
    int AddMore = true;
    do
    {
        AddArrayElement(ReadPositiveNum("Enter a number: "), Length, Arr);
        AddMore = ReadPositiveNum("Do you want to add another element? (1/0)\n- ");
    }
    while (AddMore);
}

