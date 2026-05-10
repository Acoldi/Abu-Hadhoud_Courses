#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int ReadPositiveNum(string Message)
{
    int num;
    do
    {
        cout << Message << ": "; cin >> num;
    } while (num <= 0);
    return num;
}

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

int main(void)
{
    PrintNumberPattern(ReadPositiveNum("Enter a number"));
}