#pragma once
#include <iostream>
#include <string>

using namespace std;

string ReadStringp30()
{
    string S1;
    getline(cin, S1);
    return S1;
}

int CountLetterp30(string Text, char Letter)
{
	int counter = 0;
	for (int i = 0; i < Text.length(); i++)
	{
		if ((Text[i]) == Letter)
			counter++;
	}
	return counter;
}

void Prob30_CountLetter()
{
	cout << "Please Enter your text:\n";
	string text = ReadStringp30();
	char Letter;

	cout << "\nEnter the letter you want to count: "; 
    cin >> Letter;
	
	cout << "\nOriginal text:\n" << text;

	cout << "\n\nThe Count Of '" << Letter << "' = " << CountLetterp30(text, Letter) << endl; 

	system("Pause>0");
}

