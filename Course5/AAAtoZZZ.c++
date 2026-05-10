#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int ReadPositiveNum(string Message)
{
    int num;
    do
    {
        cout << Message << ": ";
        cin >> num;
    } while (num <= 0);
    return num;
}

void PrintAAAtoZZZ(void)
{
    for (int i = 65; i < 91; i++)
    {
        for (int j = 65; j < 91; j++)
        {
            for (int k = 65; k < 91; k++)
            {
                cout << char(i) << char(j) << char(k) << endl;
            }
        }
    }
}

int main(void)
{
    PrintAAAtoZZZ();
}