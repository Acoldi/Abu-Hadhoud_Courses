#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void PrintVectorp41(vector <string>& Vstring)
{
	cout << "The  vector elements are:\n";
	for (string& S : Vstring)
	{
		cout << S << endl;
	}
}

vector <string> Splitp41(string text, string Delimeter)
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

string ReverseWordsInString(string text)
{
	vector<string> vString;
	string S2 = "";

	vString = Splitp41(text, " ");
	
	vector<string>::iterator vIterator = vString.end();

	while (vIterator != vString.begin())
	{
		vIterator--;
		S2 += *vIterator + " ";
	}

	return S2.substr(0, S2.length() - 1);
	
}

void Prob41_ReverseWordsInString()
{
	//cout << "Enter your text please:  \n";
    string text = "Welcome to the jungle";
    cout << "Original string: " << text << endl;
	cout << "The result of reversing your text: \n    " << ReverseWordsInString(text);

	system("Pause>0");
}
