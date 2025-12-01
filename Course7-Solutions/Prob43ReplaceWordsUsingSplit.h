#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
	
using namespace std;

// Forward declaration for LowerStringLetters
void LowerStringLetters(string& text);

string JoinStingp43(vector <string> text, string Deli)
{
	string Result = "";
	for (string& word : text)
	{
		if (Result != "")
			Result += Deli;
		Result += word;
	}
	return Result;
}

vector <string> Splitp43(string text, string Delimeter)
{
	vector <string> vString;
	int pos = 0;
	string word = "";

	while ((pos = text.find(Delimeter)) != std::string::npos)
	{
		word = text.substr(0, pos);

		if (word != "")
			vString.push_back(word);

		text.erase(0, pos + Delimeter.length());
	}

	if (text != "")
		vString.push_back(text);

	return vString;
}


string ReplaceWordInStringUsingSplit(string text, string StringToReplace, string ReplaceTo, bool MatcCase = true)
{
	vector<string> vString;

	vString = Splitp43(text, " ");

	for (string& word : vString)
	{
		if (MatcCase)
		{
			if (word == StringToReplace)
			{
				word = ReplaceTo;
			}
		}
		else {
            string tempWord = word;
            string tempStringToReplace = StringToReplace;
			LowerStringLetters(tempWord);
			LowerStringLetters(tempStringToReplace);
			if (tempWord == tempStringToReplace)
			{
				word = ReplaceTo;
			}
		}
	}
	return JoinStingp43(vString, " ");
}

void Prob43_ReplaceWordsUsingSplit()
{
	//cout << "Enter your text please:  \n";
    string text = "Welcome ali, this is Ali's house";
    cout << "Original text: " << text << endl;
	cout << " The replaced string (case sensitive) \n    " << ReplaceWordInStringUsingSplit(text, "Ali", "Dudy", true) << endl;
    cout << " The replaced string (case insensitive) \n    " << ReplaceWordInStringUsingSplit(text, "ali", "Dudy", false) << endl;

	system("Pause>0");
}

// Definition for LowerStringLetters, assuming it modifies the string in place.
void LowerStringLetters(string& text)
{
    for (char& c : text)
    {
        c = tolower(c);
    }
}
