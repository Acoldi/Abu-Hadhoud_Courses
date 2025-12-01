#pragma once
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadStringp31()
{
    string S1;
    getline(cin, S1);
    return S1;
}

int CountLetterp31(string Text, char Letter, bool MatchCase = true)
{
	int counter = 0;

	if (MatchCase)
	{
		for (int i = 0; i < Text.length(); i++)
		{
			if ((Text[i]) == Letter)
				counter++;
		}
		return counter;
	}
	
	for (int i = 0; i < Text.length(); i++)
	{
		if (tolower(Letter) == tolower(Text[i]))
			counter++;
	}
	return counter;
}

void Prob31_CountLetterMatchCase()
{
	cout << "Please Enter your text:\n";
	string text = ReadStringp31();
	char Letter;

	cout << "\nEnter the letter you want to count: "; 
    cin >> Letter;
	
	cout << "\nOriginal text:\n" << text;

	cout << "\n\nThe Count Of '" << Letter << "' (Case Sensitive) = " << CountLetterp31(text, Letter) << endl;
	cout << "The Count Of '" << Letter << "' (Case Insensitive) = " << CountLetterp31(text, Letter, false) << endl;

	system("Pause>0");
}

