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
        cout << Message;
        cin >> num;
    } while (num < 0);
    return num;
}

void AddArrayElement(int number, int &Length, int Arr[])
{
    Arr[Length] = number;
    Length++;
}

void AddArrayElements(int &Length, int Arr[])
{
    int AddMore = true;
    do    // We don't have to add element here because, maybe we need to add just 1 element later on, it would be better if it is a function by itself.
    {
        AddArrayElement(ReadPositiveNum("Enter a number: "), Length, Arr);
        AddMore = ReadPositiveNum("Do you want to add another element? (1/0)\n- ");
    }
    while (AddMore);
}

void PrintArray(int ArrLength, int array[])
{
    for (int i = 0; i < ArrLength; i++)
    {
        cout << array[i] << " " ;
    }
}

bool IsArrayPalindrome(int Length, int Array[])
{
    for (int i = 0; i < Length; i++)
    {
        if (Array[0 + i] != Array[Length - 1 - i])
            return false;
    }
    return true;
}

int main(void)
{
    int ArrLength = 0;

    int Array[100];
    AddArrayElements(ArrLength, Array);

    cout << "Array\n" << endl;
    PrintArray(ArrLength, Array);

    if (IsArrayPalindrome(ArrLength, Array))
        cout << "\nArray contains a palindrome number\n";
    else
        cout << "Array doesn't contain a palindrome number\n";

}