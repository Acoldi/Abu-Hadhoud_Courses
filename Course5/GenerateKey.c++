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

enum enCharType {SmallLetter=1, CapitalLetter, SpecialCharacter, Digit};

int RandomNumber(int From, int To)
{
    int N;
    N = rand() % (To - From + 1) + From;
    return N;
}

char GetRandomCharacters(enCharType Type)
{
    switch (Type)
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

string GenerateWord(enCharType CharType, int Length)
{
    string Word;
    for (int i = 0; i < Length; i++)
    {
        Word += GetRandomCharacters(CharType);
    }
    return Word;
}

string GenerateKey(enCharType CharType, int LengthOfWord)
{
    string Key = "";
    Key += GenerateWord(CharType, LengthOfWord) + "_";
    Key += GenerateWord(CharType, LengthOfWord) + "_";
    Key += GenerateWord(CharType, LengthOfWord) + "_";
    Key += GenerateWord(CharType, LengthOfWord);
    return Key;
}

void GenerateKeys(int NumberOfKeys)
{
    for (int i = 0; i < NumberOfKeys; i++)
    {
        cout << "key [" << i << "] : " << GenerateKey(enCharType::CapitalLetter, 4) << endl;
    }
}

int main(void)
{
    cout << endl;
    srand((unsigned) time(NULL));
    GenerateKeys(ReadPositiveNum("Enter number of keys to generate"));    
}