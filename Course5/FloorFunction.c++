#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <time.h>
using namespace std;

int MyFloor(float Number)
{
    int IntPart = int(Number);
    if (Number > 0)
        return IntPart;
    else
        return --IntPart;
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

    cout << "My floor function result: " << MyFloor(Number) << endl;
    cout << "c++ floor result: " << floor(Number);

}