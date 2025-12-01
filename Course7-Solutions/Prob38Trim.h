#pragma once
#include <iostream>
#include <string>

using namespace std;

string TrimLeftp38(string text)
{
	int i = 0;
	while (text[i] == ' ')
	{
		i++;
	}
	return text.erase(0, i);
}

string TrimRightp38(string text)
{
	int i = text.length();
	while (i > 0 && text[i - 1] == ' ')
	{
		i--;
	}
	return text.erase(i);
}

string TrimAllp38(string text)
{
	text = TrimLeftp38(text);
	text = TrimRightp38(text);

	return text;
}

void Prob38_Trim()
{
	//cout << "Please enter your string:\n";
	//string text = ReadSting();
    string text = "    Hello World    ";

    cout << "Original text: \"" << text << "\"" << endl;
	cout << "Trim Left: \"" << TrimLeftp38(text) << "\"" << endl;
	cout << "Trim Right: \"" << TrimRightp38(text) << "\"" << endl;
	cout << "Trim All: \"" << TrimAllp38(text) << "\"" << endl;

	system("Pause>0");
}
