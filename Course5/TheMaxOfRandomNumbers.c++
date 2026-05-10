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

int Max(int arr[100])
{
    int Max = 0;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] > Max)
        {
            Max = arr[i];
        }
    }
    return Max;
}

void PrintArray(int Length, int array[])
{
    for (int i = 0; i < Length; i++)
    {
        cout << " " << array[i];
    }
}

int main(void)
{
    srand((unsigned)time(NULL));
    int Size = 1;
    int array[100];
    FillArrayWithRandomNumbers(Size, array);
    PrintArray(Size, array);

    cout << endl << "The maximum number is:  " << Max(array);
}