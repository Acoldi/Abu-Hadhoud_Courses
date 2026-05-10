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

int Myceil(float Number)
{
    if (GetFractionPart(Number) > 0)
    {
        int IntPart = int(Number);
        if (Number > 0)
            return ++IntPart;
        else
            return IntPart;
    }
    return Number;
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

    cout << "My ceil function result: " << Myceil(Number) << endl;
    cout << "c++ ceil result: " << ceil(Number);

}