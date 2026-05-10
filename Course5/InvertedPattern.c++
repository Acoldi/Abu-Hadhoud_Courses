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

int PrintInvertedPattern(int Number)
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

int main(void)
{
    PrintInvertedPattern(ReadPositiveNum("Enter a number"));
}