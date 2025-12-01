#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void PrintVectorp37(vector <string>& Vstring)
{
	cout << "The vector elements are:\n";
	for (string& S : Vstring)
	{
		cout << S << endl;
	}
}

vector <string> Splitp37(string text, string Delimeter)
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

void Prob37_SplitString()
{
	//cout << "Please enter your string:\n ";
    string text = "Ali,Ahmed,Hassan,Hussein";
    cout << "String to split: " << text << endl;
	vector <string> ListOfWord =  Splitp37(text, ",");

	PrintVectorp37(ListOfWord);

	system("Pause>0");
}
