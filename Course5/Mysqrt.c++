#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <time.h>
using namespace std;

float ReadNum(string Message)
{
    float num;
    cout << Message;
    cin >> num;
    return num;
}

float MySqrt(float Number)
{
    return pow(Number, 0.5);
}

int main(void)
{
    float Number = ReadNum("Enter a number: ");

    cout << "My sqrt function result: " << MySqrt(Number) << endl;
    cout << "c++ sqrt result: " << sqrt(Number);

}