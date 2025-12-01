#pragma once
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string DeletePunctsFromString(string text)
{
	string S2  = "";
	
	for (int i = 0; i < text.length(); i++)
	{
		if (!ispunct(text[i]))
		{	
			S2 += text[i];
		}
	}
	return S2;
}

void Prob44_RemovePunct()
{
	//cout << "Enter your text please:  \n";
    string text = "Hello, world! This is a test.";
    cout << "Original string: " << text << endl;
	cout << " The string without punctuation: \n    " << DeletePunctsFromString(text);

	system("Pause>0");
}

