#pragma once
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadStringp29()
{
    string S1;
    getline(cin, S1);
    return S1;
}

enum enCaseLetterp29 { Upper = 1, Lower = 2, All = 3 };

int CountLetterCasep29(string Text, enCaseLetterp29 Case = enCaseLetterp29::All)
{
	if (Case == enCaseLetterp29::All)
		return Text.length();

	int counter = 0;
	for (int i = 0; i < Text.length(); i++)
	{
		if (isupper(Text[i]) && Case == enCaseLetterp29::Upper)
			counter++;

		if (islower(Text[i]) && Case == enCaseLetterp29::Lower)
			counter++;
	}
	return counter;
}

void Prob29_CountCaseLetters()
{
	cout << "Please Enter your text:\n ";

	string text = ReadStringp29();
	cout << "\nOriginal Text:\n" << text;

	cout << "\n\nText Length = " << CountLetterCasep29(text);
	cout << "\nNumber of upper case letters: " << CountLetterCasep29(text, enCaseLetterp29::Upper) << endl;
	cout << "Number of lower case letters: " << CountLetterCasep29(text, enCaseLetterp29::Lower) << endl;

	system("Pause>0");
}
