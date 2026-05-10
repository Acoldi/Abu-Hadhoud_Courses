#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <time.h>
using namespace std;

enum enOddOrNot{Odd=1, Not=2};

enOddOrNot CheckNumberType(int number)
{
    int result = number % 2;
    if (result == 0)
    {
        return enOddOrNot::Not;  // it returns the corresponding number
    }
    else{
        return enOddOrNot::Odd;
    }
}

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

void CopyPrimeNumbersArraysToAnotherOne(int ArrLength, int &ArrayLength2, int Arr[], int ArrDestination[])
{
    for (int i = 0; i < ArrLength; i++)
    {    
        if (CheckNumberType(Arr[i]) == enOddOrNot::Odd)
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
    srand((unsigned)time(NULL));

    int Array[100];
    FillArrayWithRandomNumbers(ArrLength, Array);

    int CArray[100];
    CopyPrimeNumbersArraysToAnotherOne(ArrLength, Arr2Length, Array, CArray);

    cout << "Array 1: " << endl;
    PrintArray(ArrLength, Array);

    cout << "\nArrDestination odd numbers: " << endl;
    PrintArray(Arr2Length, CArray);
}