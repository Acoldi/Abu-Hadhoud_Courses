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
        cout << Message; cin >> num;
    } while (num < 0);
    return num;
}

void PrintArray(int Length, int array[])
{
    for (int i = 0; i < Length; i++)
    {
        cout << array[i] << " " ;
    }
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

int main(void)
{
    int Arr[100];
    int Length = 0;

    AddArrayElements(Length, Arr);
   
    cout << "Array length: " << Length << endl;
    cout << "Array's elements: ";
    PrintArray(Length, Arr);

}