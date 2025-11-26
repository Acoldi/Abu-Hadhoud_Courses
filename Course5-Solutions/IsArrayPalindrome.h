#pragma once

bool IsArrayPalindrome(int Length, int Array[])
{
    for (int i = 0; i < Length; i++)
    {
        if (Array[0 + i] != Array[Length - 1 - i])
            return false;
    }
    return true;
}
