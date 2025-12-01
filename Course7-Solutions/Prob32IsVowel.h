#pragma once
#include <iostream>
#include <cctype>

using namespace std;

bool IsVowelp32(char Letter)
{
	char lowerLetter = tolower(Letter);
	return (lowerLetter == 'a' || lowerLetter == 'o' || lowerLetter == 'i' || lowerLetter == 'e' || lowerLetter == 'u');
}

void Prob32_IsVowel()
{
	char Letter;
	
	cout << "\nEnter the letter you want to check: "; 
    cin >> Letter;

	if (IsVowelp32(Letter))
	{
		cout << "\nIt is a vowel!\n";
	}
	else
		cout << "\nIt is not a vowel!\n";
	
    system("Pause>0");
}

