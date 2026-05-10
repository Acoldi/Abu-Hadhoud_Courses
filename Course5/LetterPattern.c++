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

void PrintLetterPattern(int Number)
{
    for (int i = 65; i <= 64 + Number; i++)
    {
        for (int j = 0; j <= i - 65; j++)
        {
            cout << char(i);
        }
        cout << endl;
    }
}

int main(void)
{
    PrintLetterPattern(ReadPositiveNum("Enter a number"));
}