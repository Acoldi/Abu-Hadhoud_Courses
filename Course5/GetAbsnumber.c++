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

float Abs(float Number)
{
    if (Number > 0)
        return Number;    
    else
        return Number*= -1;
}

int main(void)
{
    srand((unsigned) time(NULL));

    float NUmber = ReadNum("Enter a number: ");

    cout << "My abs result: " << Abs(NUmber) << endl;
    cout << "c++ abs result: : " << abs(NUmber);

}