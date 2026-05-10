#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <time.h>
using namespace std;

void Swap(int &A, int &B)  // A and B here are just aliases to the passed variables, thus they point to the same chunck of memory.
{
    int Temp = A;
    A = B;
    B = Temp;
}

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

void ReverseArray(int Length, int arrSource[], int arrDestination[])
{
    for (int i = 0; i < Length; i++)
    {
        arrDestination[i] = arrSource[Length - 1 - i]; // The reason we subtract 1 from Length is because we don't end the index of the array at Length but At length - 1, because we started from 0.
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

    FillArrayWithRandomNumbers(Length, Array);

    cout << "\nArray 1: " << endl;
    PrintArray(Length, Array);

    ReverseArray(Length, Array, Array2);
    cout << "\n\nArray 1 After Being Reversed: " << endl;
    PrintArray(Length, Array2);
}

