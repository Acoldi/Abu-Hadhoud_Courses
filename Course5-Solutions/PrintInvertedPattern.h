#pragma once
#include <iostream>

using namespace std;

void PrintInvertedPattern(int Number)
{
    for (int i = Number; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
}
