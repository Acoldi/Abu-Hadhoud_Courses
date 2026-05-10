#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int ReadPositiveNum(string Message)
{
    int num;
    do
    {
        cout << Message << ": ";
        cin >> num;
    } while (num <= 0);
    return num;
}

void PrintInvertedLetterPattern(int Number)
{
    for (int i = 64 + Number; i >= 65; i--) // i represents the letter.
    {
        for (int j = 0; j < Number - (Number + 64 - i); j++) // This tell us how many time we shouls print the current letter, we want to print those times decreasingly from the Number to 0
                                                             // so we want to decrement the number by 1
                                                             // so it is Number - (something gets incremented by 1) which is
                                                             // Number + 64 - i 
                                                             // Where i is getting decremented by 1
                                                             // every iteration. The first iteration it is gonna be 64
                                                             // so we are going to print the letter the same number of Number
                                                             // the next one i is (64 + Number - 1) which leads to the 
                                                             // Equation (Number + 64 - i) to get decremented by 1
                                                             // SO the iterations are gonne be less than the previous ones by 1
        {
            cout << char(i);
        }
        cout << endl;
    }
}

int main(void)
{
    PrintInvertedLetterPattern(ReadPositiveNum("Enter a number"));
}