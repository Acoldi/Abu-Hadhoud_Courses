#pragma once
#include <iostream>
#include <string>

using namespace std;

bool FindPassword(string Password)
{
    int counter = 0;
    string letters = "";
    for (int i = 65; i < 91; i++)
    {
        for (int j = 65; j < 91; j++)
        {
            for (int k = 65; k < 91; k++)
            {
                counter++;
                letters += char(i);
                letters += char(j);
                letters += char(k);
                cout << "Trial ["<< counter << "]: " << letters << endl;
                if (letters == Password)
                {
                    cout << "The password " << letters << " Found at trial " << counter << endl;
                    return 1;
                }
                letters = "";
            }
        }
    }
    return 0;
}
