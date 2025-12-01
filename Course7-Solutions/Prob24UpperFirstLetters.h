#pragma once
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadStringp24()
{
    string S1;
    getline(cin, S1);
    return S1;
}

void UpperFirstLettersp24(string &Text)
{
	bool IsFirstLetter = true;

	for (int i = 0; i < Text.length(); i++)
	{
		if (Text[i] != ' ' && IsFirstLetter)
		{
			Text[i] = Text[i] - 32;
		}
		
		IsFirstLetter = (Text[i] == ' ' ? true : false);
	}
}

void Prob24_UpperFirstLetters()
{
	cout << "Please Enter your string:\n";
	string Text = ReadStringp24();

	UpperFirstLettersp24(Text);

	cout << Text << endl;
	system("Pause>0");
}

