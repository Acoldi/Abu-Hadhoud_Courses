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
void FillArrayWithRandomNumbers(int &ArrLength, int array[])
{
    ArrLength = ReadPositiveNum("Enter the length of the array");
    for (int i = 0; i < ArrLength; i++)
    {
        array[i] = RandomNumber(0, 10);
    }
}

void AddArrayElement(int number, int &ArrLength, int Arr[])
{
    Arr[ArrLength] = number;
    ArrLength++;
}

void CopyArrayUsingAddArrayElement(int ArrLength, int &ArrayLength2, int Arr[], int ArrDestination[])
{
    for (int i = 0; i < ArrLength; i++)
        AddArrayElement(Arr[i], ArrayLength2, ArrDestination);
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
    srand((unsigned)time(NULL));

    int Array[100];

    int CArray[100];

    FillArrayWithRandomNumbers(ArrLength, Array);

    cout << "Array 1: " << endl;
    PrintArray(ArrLength, Array);

    CopyArrayUsingAddArrayElement(ArrLength, Arr2Length, Array, CArray);

    cout << "\nArray 2 (ArrDestination): " << endl;
    PrintArray(ArrLength, CArray);
}