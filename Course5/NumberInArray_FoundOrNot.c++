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

bool IsFound(int Number, int Length, int Arr[])
{
    for (int i = 0; i < Length; i++)
    {
        if (Arr[i] == Number)
        {
            return 1;
        }
    }
    return 0;
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
    cout << "Array Elements\n";

    PrintArray(Length, Arr);
    cout << endl;

    int Number = ReadPositiveNum("the number you want to find");

    cout << "Number you are looking for: " << Number << endl;

    if (IsFound(Number, Length, Arr))
        cout << "Found\n";
    else
        cout << "Not Found\n"; 
}