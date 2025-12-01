#pragma once
#include <iostream>

using namespace std;

void PrintNumberPattern(int Number)
{
    for (int i = 1; i <= Number; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
}
