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

void PrintReversedNumber(int number)
{
    while (number > 0)
    {
        cout << number % 10 << endl;
        number /= 10;
    }
}

int main(void)
{
    PrintReversedNumber(ReadPositiveNum("Enter a number"));
}