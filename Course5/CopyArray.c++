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

int RandomNumber(int From, int To)
{
    int N;
    N = rand() % (To - From + 1) + From;
    return N;
}

void FillArrayWithRandomNumbers(int &Length, int array[])
{
    Length = ReadPositiveNum("Enter the array length");

    for (int i = 0; i < Length; i++)
    {
        array[i] = RandomNumber(0, 100);
    }
}

void CopyArray(int Length, int Arr[], int copy[])
{
    for (int i = 0; i < Length; i++)
    {
        copy[i] = Arr[i];
    }
}

void PrintArray(int Length, int array[])
{
    for (int i = 0; i < Length; i++)
    {
        cout << array[i] << " " ;
    }
}

int main(void)
{
    int Length = 1;

    int Array[100];

    int CArray[100];

    FillArrayWithRandomNumbers(Length, Array);

    CopyArray(Length, Array, CArray);

    cout << "Array 1: " << endl;
    PrintArray(Length, Array);

    cout << "\nArray 2 (copy): " << endl;
    PrintArray(Length, CArray);
}