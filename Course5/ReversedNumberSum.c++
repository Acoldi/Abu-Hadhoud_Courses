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

int SumOfDigits(int Number)
{
    int Remainder = 0, Sum = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Sum += Remainder;
        Number /= 10;
    }
    return Sum;
}

int main(void)
{
    int num = ReadPositiveNum("Enter a positive number");
    cout << "The sum of the number "<< num  << " digits is " <<Of SumDigits(num);
}