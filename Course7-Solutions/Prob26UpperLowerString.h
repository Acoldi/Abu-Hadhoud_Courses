#pragma once
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadStringp26()
{
    string S1;
    getline(cin, S1);
    return S1;
}

void LowerStringLettersp26(string &Text)
{
	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = tolower(Text[i]);
	}
}

void UpperStringLettersp26(string &Text)
{
	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = toupper(Text[i]);
	}
}

void Prob26_UpperLowerString()
{
	cout << "Please Enter your string:\n";
	string Text = ReadStringp26();

    cout << "\nString after converting to lowercase:\n";
	LowerStringLettersp26(Text);
	cout << Text << endl;

    cout << "\nString after converting to uppercase:\n";
	UpperStringLettersp26(Text);
	cout << Text << endl;

	system("Pause>0");
}
