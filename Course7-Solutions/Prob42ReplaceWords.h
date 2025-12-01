#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void PrintVectorp42(vector <string>& Vstring)
{
	cout << "The  vector elements are:\n";
	for (string& S : Vstring)
	{
		cout << S << endl;
	}
}

vector <string> Splitp42(string text, string Delimeter)
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

string ReplaceWordInString(string text, string OrWord, string DesWord)
{
	vector<string> vString;
	string S2 = "";

	vString = Splitp42(text, " ");

	for (string &word : vString)
	{
		if (word == OrWord)
		{
			word = DesWord;
		}
	}

	vector<string>::iterator vIterator = vString.begin();


	while (vIterator != vString.end())
	{
		S2 += *vIterator + " ";
		vIterator++;
	}

	return S2.substr(0, S2.length() - 1);
	
}

void Prob42_ReplaceWords()
{
	//cout << "Enter your text please:  \n";
    string text = "Welcome Ali, this is Ali's house";
    cout << "Original text: " << text << endl;
	cout << " The replaced string \n    " << ReplaceWordInString(text, "Ali", "Dudy");

	system("Pause>0");
}
