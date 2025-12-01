#pragma once
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

char InvertLetterCasep27(char C)
{
	return isupper(C) ? tolower(C) : toupper(C);
}

void Prob27_InvertLetterCase()
{
	cout << "Please Enter your letter:\n";
	char CH;
	cin >> CH;

	cout << "\nLetter after inverting case:\n";
	cout << InvertLetterCasep27(CH) << endl;

	system("Pause>0");
}

