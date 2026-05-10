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

bool IsPerfectNumber(int Number)
{
    int Sum = 0;
    for (int i = 1; i < Number; i++)
    {
        if (Number % i == 0)
        {
            Sum += i;
        }
    }
    return Sum == Number;
}

void PrintPerfectNumberFrom1toN(int Number)
{
    for (int i = 1; i <= Number; i++)
    {
        if (IsPerfectNumber(i))
        {
            cout << i << endl;
        }
    }
}

int main(void)
{
    PrintPerfectNumberFrom1toN(ReadPositiveNum("Enter a positive number"));
}