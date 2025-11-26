#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "RandomNumber.h"

using namespace std;

enum enCharType {SmallLetter=1, CapitalLetter, SpecialCharacter, Digit};

char GetRandomCharacters(enCharType Type)
{
    switch (Type)
    {
    case enCharType::CapitalLetter:
        return char(randomNumber(65, 90));
    case enCharType::SmallLetter:
        return char(randomNumber(97, 122));
    case enCharType::SpecialCharacter:
        return char(randomNumber(33, 47));
    case enCharType::Digit:
        return char(randomNumber(48, 57));
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
