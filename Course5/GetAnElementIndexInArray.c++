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
    for (int i = 0; i < Length; i++)
    {
        array[i] = RandomNumber(0, 100);
    }
}

int FindNumberInArray(int Number, int Length, int Arr[])
{
    for (int i = 0; i < Length; i++)
    {
        if (Arr[i] == Number)
        {
            return i;
        }
    }
    return -1;
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
    int Arr[100];
    int Length = ReadPositiveNum("Enter the array length");

    FillArrayWithRandomNumbers(Length, Arr);
    PrintArray(Length, Arr);
    cout << endl;

    short NumberIndex = FindNumberInArray(ReadPositiveNum("Enter The number you eant to find"), Length, Arr);


    if (NumberIndex == -1)
    {
        cout << "The number not found :-(\n";
    }
    else
    {
        cout << "The Number found at position: " << NumberIndex << endl;
        cout << "The Number found at order: " << NumberIndex + 1 << endl;
    }
}