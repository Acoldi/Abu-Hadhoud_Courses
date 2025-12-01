#pragma once
#include <iostream>
#include <string>

using namespace std;

void PrintEachWordInstring(string text)
{
	string delim = " ";
	int pos = 0;
	string word = "";

	cout << "Words in string are:" << endl;
	while ((pos = text.find(delim)) != std::string::npos)
	{
		word = text.substr(0, pos);

		if (word != "")
			cout << word << endl;

		text.erase(0, pos + delim.length());
	}

	if (text != "")
		cout << text << endl;
}

void Prob35_PrintEachWordInString()
{
	//cout << "Please Enter your string:\n ";
    string text = "This is a sample string";
    cout << "The string is: " << text << endl;
	PrintEachWordInstring(text);

	system("Pause>0");
}

