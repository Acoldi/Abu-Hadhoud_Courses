#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <time.h>
using namespace std;

int FindNumberInArray(int Number, int Length, int Arr[])
{
    for (int i = 0; i < Length; i++)
    {
        if (Arr[i] == Number)
        {
            return Arr[i];
        }
    }
    return -1;
}

bool IsNumberInArray(int Number, int Arr[], int Length)
{
    return FindNumberInArray(Number, Length, Arr) != -1;
}

void AddElementsManually(int &ArrLength, int array[])
{
    ArrLength = 10;
    array[0] = 10;
    array[1] = 10;
    array[2] = 10;
    array[3] = 50;
    array[4] = 50;
    array[5] = 70;
    array[6] = 70;
    array[7] = 70;
    array[8] = 90;
    array[9] = 10;
}

void AddArrayElement(int number, int &ArrLength, int Arr[])
{
    Arr[ArrLength] = number;
    ArrLength++;
}

void CopyDistinctArrayNumbers(int ArrLength, int &ArrayLength2, int Arr[], int ArrDestination[])
{
    for (int i = 0; i < ArrLength; i++)
    {   
        if (!IsNumberInArray(Arr[i], ArrDestination, ArrayLength2))
        {
            AddArrayElement(Arr[i], ArrayLength2, ArrDestination);
        }
    }
}

void PrintArray(int ArrLength, int array[])
{
    for (int i = 0; i < ArrLength; i++)
    {
        cout << array[i] << " " ;
    }
}


int main(void)
{
    int ArrLength = 0, Arr2Length = 0;

    int Array[100];
    AddElementsManually(ArrLength, Array);

    int CArray[100];
    CopyDistinctArrayNumbers(ArrLength, Arr2Length, Array, CArray);

    cout << "Array 1: " << endl;
    PrintArray(ArrLength, Array);

    cout << "\nArray 2 distinct numbers: " << endl;
    PrintArray(Arr2Length, CArray);
}