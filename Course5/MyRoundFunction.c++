#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <time.h>
using namespace std;

float GetFractionPart(float Number)
{
    return Number - int(Number);
}

int MyRound(float Number)
{
    int IntPart = int(Number);
    cout << "Int part is " << IntPart << endl;
    float Fraction = GetFractionPart(Number);

    cout << "The fraction is " << Fraction << endl;

    if (abs(Fraction) >= .5)
    {
        if (Number < 0)
            return --IntPart;
        else{
            return IntPart += 1;
        }
    }
    return IntPart;
}

float ReadNum(string Message)
{
    float num;
    cout << Message;
    cin >> num;
    return num;
}

int main(void)
{
    float Number = ReadNum("Enter a number: ");

    cout << "My round result: " << MyRound(Number) << endl;
    cout << "c++ round result: " << round(Number);

}