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

int ReverseNumber(int Number)
{
    int Remainder = 0, ReversedNumber = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number /= 10;
        ReversedNumber = ReversedNumber * 10 + Remainder;  // Here we added the digit directly instead of converting to string.
        // The digit must be added to the right (in the single order) so we must get the place for the single digit then add it,
        // we do that by multiplying by 10.
    }
    return ReversedNumber;
}

int main(void)
{
    cout << ReverseNumber(ReadPositiveNum("Enter a positive number"));
}