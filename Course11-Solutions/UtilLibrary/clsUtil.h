#pragma once
#include<iostream>
#include<vector>
#include "C://Users/HP/source/repos/Abu-Hadhoud_Courses/Course10-Solutions/DateLibrary/clsDate.h"
using namespace std;

class clsUtil
{
public:
	
	static void Srand()
	{
		srand((unsigned)time(NULL));
	}
	static int RandomNumber(int From, int To)
	{
		int N;

		N = rand() % (To - From + 1) + From;

		return N;
	}

	static string Tabs(int NumberOfTabs)
	{
		string t = "";
		for (int i = 0; i < NumberOfTabs; i++)
		{
			t = t + "\t";
		}
		return t;
	}

	enum enCharType {CapitalLetters, SmallLetters, Digit, Mix, Punctuation};
	
	static char GetRandomPunctuation() {
		short ch = (char)RandomNumber(33, 47);
		short ch1 = (char)RandomNumber(58, 64);
		return RandomNumber(1, 2) == 1 ? ch : ch1;
	}
	
	static char GetRandomCapitalLetter() {
		return (char)RandomNumber(65, 90);
	}
	
	static char GetRandomSmallLetter() {
		return (char)RandomNumber(97, 122);
	}
	
	static char GetRandomDigit() {
		return (char)RandomNumber(48, 57);
	}


	static char GetRandomCharacter(enCharType charType)
	{
		if (charType == enCharType::Mix)
			charType = (enCharType)RandomNumber(0, 2);

		switch (charType)
		{
		case clsUtil::CapitalLetters:
			return GetRandomCapitalLetter();
			break;
		case clsUtil::SmallLetters:
			return GetRandomSmallLetter();
			break;
		case clsUtil::Digit:
			return GetRandomDigit();
			break;
		case clsUtil::Punctuation:
			return GetRandomPunctuation();
			break;

		}
	}

	static string GenerateWord(enCharType charsTypes, short wordLength)
	{
		string result = "";
		for (short i = 0; i < wordLength; i++)
		{
			result += GetRandomCharacter(charsTypes);
		}
		return result;
	}

	static string GenerateKey(enCharType charType)
	{
		string result = "";
		for (short i = 0; i < 4; i++)
		{
			result += GenerateWord(charType, 4);
			result += "-";
		}
		result.pop_back();
		return result;
	}

	static vector<string> GenerateKeys(short NumberOfKeys, enCharType charsTyps)
	{
		vector<string> res = vector<string>();
		for (short i = 0; i < NumberOfKeys; i++)
		{
			res.push_back(GenerateKey(charsTyps));
		}
		return res;
	}

	static void SwapDates(clsDate& Date, clsDate& Date1)
	{
		clsDate::swapDates(Date, Date1);
	}
	static void Swap(int& First, int& Second)
	{
		int temp = First;
		First = Second;
		Second = temp;
	}
	
	static void ShuffleArray(int Length, int Array[])
	{
		for (int i = 0; i < Length; i++)
		{
			Swap(Array[RandomNumber(0, Length)], Array[RandomNumber(0, Length)]);
		}
	}

	static void FIllArrayWithRandomNumbers(int Arr[], short Rows, short Cols)
	{
		for (int i = 0; i < Cols; i++)
		{
			Arr[i] = RandomNumber(1, 100);
		}
	}

	static void FillArrayWithRandomWords(string array[], short size, enCharType charsTyps, short wordLength)
	{
		for (short i = 0; i < size; i++)
		{
			array[i] = GenerateWord(charsTyps, wordLength);
		}
	}

	static void FillArrayWithRandomKeys(string array[], short size, enCharType charsTyps)
	{
		for (short i = 0; i < size; i++)
		{
			array[i] = GenerateKey(charsTyps);
		}
	}

	static string EncryptText(string Text, short key)
	{
		for (short i = 0; i < Text.length(); i++)
		{
			Text[i] = char(Text[i] + key);
		}
	}

	static string DecryptText(string Text, short key)
	{
		for (short i = 0; i < Text.length(); i++)
		{
			Text[i] = char(Text[i] - key);
		}
	}
};