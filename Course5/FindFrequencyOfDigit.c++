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

int FindDigitFrequency(int Digit, int Number)
{
    int Remainder = 0, Counter = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number /= 10;
        if (Remainder == Digit)
            Counter += 1;
    }
    return Counter;
}

int main(void)
{
    int Number = ReadPositiveNum("Enter a number");
    int Digit = ReadPositiveNum("Digit to find it's Frequency");
    cout << "The frequency of " << Digit << " is " << FindDigitFrequency(Digit, Number);
}