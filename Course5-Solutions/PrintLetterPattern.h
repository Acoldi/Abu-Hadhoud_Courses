#pragma once
#include <iostream>

using namespace std;

void PrintLetterPattern(int Number)
{
    for (int i = 65; i <= 64 + Number; i++)
    {
        for (int j = 0; j <= i - 65; j++)
        {
            cout << char(i);
        }
        cout << endl;
    }
}
