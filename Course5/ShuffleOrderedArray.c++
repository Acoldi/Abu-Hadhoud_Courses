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

void FillArrayFrom1toN(int Length, int array[])
{
    for (int i = 0; i < Length; i++)
    {
        array[i] = i + 1;
    }
}

void ShuffleArrayElements(int Length, int arr[])
{
    for (int i = 0; i < Length; i++)
    {
        Swap(arr[RandomNumber(1, Length) - 1], arr[RandomNumber(1, Length) - 1]); // Here the swap function is doning all the work, where it 
                                                                      // Randomly chooses 2 indexes to swap their values, In a loop from the first index to the last.
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

    FillArrayFrom1toN(Length, Array);

    cout << "\nArray 1: " << endl;
    PrintArray(Length, Array);

    ShuffleArrayElements(Length, Array);
    cout << "\n\n Array 1 After Being Shuffled: " << endl;
    PrintArray(Length, Array);

    
}

