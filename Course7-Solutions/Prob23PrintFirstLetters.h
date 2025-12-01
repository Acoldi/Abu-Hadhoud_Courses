#pragma once
#include <iostream>
#include <string>

using namespace std;

string ReadStringp23()
{
    string S1;
    getline(cin, S1);
    return S1;
}

void PrintFirstLettersOfStringp23(string Text)
{
	if (Text[0] != ' ')
	{
		cout << Text[0] << endl;
	}

	for (int i = 0; i < Text.length(); i++)
	{

		if (Text[i] == ' ' && Text[i + 1] != ' ')
		{
			cout << Text[i + 1] << endl;
		}
	}
}

void Prob23_PrintFirstLetters()
{
	cout << "Please Enter your string:\n";
	PrintFirstLettersOfStringp23(ReadStringp23());
	system("Pause>0");
}

