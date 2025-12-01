#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

bool IsVowelp33(char Letter)
{
	if (tolower(Letter) == 'a' || tolower(Letter) == 'o' || tolower(Letter) == 'i' || tolower(Letter) == 'e'
		|| tolower(Letter) == 'u')
	{
		return true;
	}
	return false;
}


int CountVowel(string text)
{
	int counter = 0;
	for (int i = 0; i < text.length(); i++)
	{
		if (IsVowelp33(text[i]))
		{
			counter++;
		}
	}
	return counter;
}

void Prob33_IsVowel()
{
    //cout << "Enter your string: ";
	//string text = ReadSting();
    string text = "Hello World, this is a test.";
	
	cout << "\nNumber of vowels in '" << text << "' is: " << CountVowel(text);
	
}
