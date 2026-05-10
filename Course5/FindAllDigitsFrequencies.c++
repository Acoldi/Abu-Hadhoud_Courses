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

void PrintAllFrequenciesOfAllDigits(int Number)
{
    int Remainder = 0; 
    short Frequency = 0;
    for (int i = 0; i < 10; i++)
    {
        Frequency = FindDigitFrequency(i, Number);
    
        if (Frequency > 0)
        {
            cout << "The frequency of " << i << " is " << Frequency << endl;
        }
    }
}

int main(void)
{
    PrintAllFrequenciesOfAllDigits(ReadPositiveNum("Enter a number"));
}