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

enum enCharType {SmallLetter=1, CapitalLetter, SpecialCharacter, Digit};

char RandomValues(enCharType Value)
{
    switch (Value)
    {
    case enCharType::CapitalLetter:
        return char(RandomNumber(65, 90));
    case enCharType::SmallLetter:
        return char(RandomNumber(97, 122));
    case enCharType::SpecialCharacter:
        return char(RandomNumber(33, 47));
    case enCharType::Digit:
        return char(RandomNumber(48, 57));
    }
}

int main(void)
{
    srand((unsigned) time(NULL));
    cout << RandomValues(enCharType::SmallLetter) << endl;
    cout << RandomValues(enCharType::CapitalLetter) << endl;
    cout << RandomValues(enCharType::SpecialCharacter) << endl;
    cout << RandomValues(enCharType::Digit) << endl;
}