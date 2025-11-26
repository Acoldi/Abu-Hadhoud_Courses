#pragma once
#include <string>
#include "KeyGenerator.h"

void GenerateKeysInArray(int Length, string Arr[])
{
    for (int i = 0; i < Length; i++)
    {
        Arr[i] = GenerateKey(enCharType::CapitalLetter, 4);
    }
}
