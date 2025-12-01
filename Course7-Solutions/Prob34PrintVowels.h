#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

bool IsVowelp34(char Letter)
{
	if (tolower(Letter) == 'a' || tolower(Letter) == 'o' || tolower(Letter) == 'i' || tolower(Letter) == 'e'
		|| tolower(Letter) == 'u')
	{
		return true;
	}
	return false;
}


void PrintVowels(string text)
{
	cout << "\nVowels in the string are: ";
	for (int i = 0; i < text.length(); i++)
	{
		if (IsVowelp34(text[i]))
		{
			cout << text[i] << "    ";
		}
	}
	cout << endl;
}

void Prob34_PrintVowels()
{
	//cout << "Enter your string: ";
	//string text = ReadSting();
    string text = "This is a test string for printing vowels.";
	
    cout << "String is: " << text << endl;
	PrintVowels(text);

}
