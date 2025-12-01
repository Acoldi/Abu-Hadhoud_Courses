#pragma once
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadStringp25()
{
    string S1;
    getline(cin, S1);
    return S1;
}

void LowerFirstLettersp25(string &Text)
{
	bool IsFirstLetter = true;

	for (int i = 0; i < Text.length(); i++)
	{
		if (Text[i] != ' ' && IsFirstLetter)
		{
			Text[i] = Text[i] + 32;
		}
		
		IsFirstLetter = (Text[i] == ' ' ? true : false);
	}
}

void Prob25_LowerFirstLetters()
{
	cout << "Please Enter your string:\n";
	string Text = ReadStringp25();

	LowerFirstLettersp25(Text);

	cout << Text << endl;
	system("Pause>0");
}

