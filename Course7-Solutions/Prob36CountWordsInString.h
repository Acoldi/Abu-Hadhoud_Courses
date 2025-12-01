#pragma once
#include <iostream>
#include <string>

using namespace std;

int CountWordsInString(string text)
{
	int pos = 0, counter = 0;
	string delim = " ";
	string word = "";

	while ((pos = text.find(delim)) != std::string::npos)
	{
		word = text.substr(0, pos);

		if (word != "")
			counter++;

		text.erase(0, pos + delim.length());
	}

	if (text != "")
		counter++;

	return counter;
}

void Prob36_CountWordsInString()
{
	//cout << "Please Enter your string:\n ";
    string text = "How many words are in this string?";
    cout << "The string is: '" << text << "'" << endl;
	cout << "The number of words: " << CountWordsInString(text);

	system("Pause>0");
}

