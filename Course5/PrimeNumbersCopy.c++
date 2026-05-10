#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <time.h>
using namespace std;

enum enPrimeOrNot {prime = 1, NotPrime = 2};

enPrimeOrNot IsPrime(int Num)
{
    for (int i = 2; i <= Num / 2; i++)
    {
        if (Num % i == 0)
            return enPrimeOrNot::NotPrime;
    }
    return enPrimeOrNot::prime;
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

void FillArrayWithRandomNumbers(int &Length, int array[])
{
    Length = ReadPositiveNum("\nEnter the array length");

    for (int i = 0; i < Length; i++)
    {
        array[i] = RandomNumber(0, 100);
    }
}

void CopyPrimrNumbersOfArray(int Length, int &Length2, int arrSource[], int arrDestination[])
{
    int counter = 0;
    for (int i = 0; i < Length; i++)
    {
        if (IsPrime(arrSource[i]) == enPrimeOrNot::prime)
        {
            arrDestination[counter] = arrSource[i];
            counter++;
        }
    }
    Length2 = counter;
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
    srand((unsigned) time(NULL));
    
    int Length;
    int Array[100];

    int Length2;
    int CArray[100];

    FillArrayWithRandomNumbers(Length, Array);

    CopyPrimrNumbersOfArray(Length, Length2, Array, CArray);

    cout << "\nArray 1: " << endl;
    PrintArray(Length, Array);

    cout << "\n\nPrime Numbers of Array 1 (copy): " << endl;
    PrintArray(Length2, CArray);
}

