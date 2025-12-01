#pragma once
#include <iostream>

using namespace std;

void PrintInvertedLetterPattern(int Number)
{
    for (int i = Number - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << char(i + 65);
        }
        cout << endl;
    }
}
