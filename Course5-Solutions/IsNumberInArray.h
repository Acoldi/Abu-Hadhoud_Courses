#pragma once
#include "FindNumberInArray.h"

bool IsNumberInArray(int Number, int Arr[], int Length)
{
    return FindNumberInArray(Number, Length, Arr) != -1;
}
