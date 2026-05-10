#include <iostream>
#include <string>
#include <math.h>
using namespace std;


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

int ReadPositiveNum(string Message)
{
    int num;
    do
    {
        cout << Message << ": "; cin >> num;
    } while (num <= 0);
    return num;
}

void PrintResult(int Number)
{
    cout << Number << " is ";
    if (IsPerfectNumber(Number))
        cout << "PERFECT number\n";
    else
        cout << "IMPERFECT number\n";
}

int main(void)
{
    PrintResult(ReadPositiveNum("Enter a positive number"));
}