#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <time.h>
using namespace std;

int RandomNumber(int From, int To)
{
    int N;
    N = rand() % (To - From + 1) + From;
    return N;
}

int ReadPositiveNum(string Message)
{
    int num;
    do
    {
        cout << Message;
        cin >> num;
    } while (num < 0);
    return num;
}

void FillArrayWithRandomNumbers(int &ArrLength, int array[])
{
    ArrLength = ReadPositiveNum("Enter the length of the array: ");
    for (int i = 0; i < ArrLength; i++)
    {
        array[i] = RandomNumber(0, 100);
    }
}

void PrintArray(int ArrLength, int array[])
{
    for (int i = 0; i < ArrLength; i++)
    {
        cout << array[i] << " " ;
    }
}

int CountOfOddNumbersInArray(int Length, int Arr[])
{
    int count = 0;
    for (int i = 0; i < Length; i++)
    {
        if (Arr[i] % 2 == 0)
            count++;
    }
    return count;
}

int main(void)
{
    srand((unsigned) time(NULL));
    int ArrLength = 0;

    int Array[100];
    FillArrayWithRandomNumbers(ArrLength, Array);

    cout << "The Array:\n";
    PrintArray(ArrLength, Array);

    cout << "The odd numbers count is " << CountOfOddNumbersInArray(ArrLength, Array) << endl;

}