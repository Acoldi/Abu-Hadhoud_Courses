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
    for (int i = 0; i < Length; i++)
    {
        array[i] = RandomNumber(0, 100);
    }
}

void SumArray(int Arr1[], int Arr2[], int arrDestination[], int Length)
{
    for (int i = 0; i < Length; i++)
    {
        arrDestination[i] = Arr1[i] + Arr2[i];
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
    srand((unsigned) time(NULL));
    
    int Length;
    Length = ReadPositiveNum("\nEnter the array length");

    int Array[100];

    int Array2[100];

    int Array3[100];

    FillArrayWithRandomNumbers(Length, Array);
    FillArrayWithRandomNumbers(Length, Array2);

    cout << "\nArray 1: " << endl;
    PrintArray(Length, Array);

    cout << "\n\nArray 2: " << endl;
    PrintArray(Length, Array2);

    SumArray(Array, Array2, Array3, Length);
    cout << "\n\nSum of array 1 and array 2: " << endl;
    PrintArray(Length, Array3);
}

