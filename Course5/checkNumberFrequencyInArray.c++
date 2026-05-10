#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <time.h>
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

void ReadArrayOfInt(int &Length, int array[]) // Length is passed by reference because I want to change the value of
                                              // passed variable, hence I cannot (or am yet to learn) use the variable defined in a function from another funcion.
{
    Length = ReadPositiveNum("The number of elements you want to add");
    for (int i = 0; i < Length; i++)
    {
        array[i] = ReadPositiveNum(("Element [" + to_string(i) + "]"));
    }
}

void PrintArray(int Length, int array[])
{
    for (int i = 0; i < Length; i++)
    {
        cout << array[i] << " ";
    }
}

int TimesRepeated(int Element, int Array[], int Length)
{
    int Frequency = 0;
    for (int i = 0; i < Length; i++)
    {
        if (Array[i] == Element)
        {
            Frequency++;
        }
    }
    return Frequency;
} 

int main(void)
{
    int N=1, array[N], Frequency; // after we read N in the read array function it chenged here, too. By the way this approach is better than hadhoud's approach.
    ReadArrayOfInt(N, array);
    int NumberTocheck = ReadPositiveNum("Enter the number you watn to check");

    Frequency = TimesRepeated(NumberTocheck, array, N);
    cout << "Original array: ";
    PrintArray(N, array); cout << endl;
    
    cout << NumberTocheck << " is repeated " << Frequency
        << " time(s) " << endl;
}