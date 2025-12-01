#pragma once
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

char InvertLetterCasep28(char C)
{
	return isupper(C) ? tolower(C) : toupper(C);
}

void InvertALLCharactersCasep28(string& Text)
{
	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = InvertLetterCasep28(Text[i]);
	}
}

void Prob28_InvertAllLetters()
{
	cout << "Please Enter your text:\n";
	string text;
	getline(cin, text);

	InvertALLCharactersCasep28(text);
	
	cout << "\nText after inverting case:\n";
	cout << text << endl;

	system("Pause>0");
}

