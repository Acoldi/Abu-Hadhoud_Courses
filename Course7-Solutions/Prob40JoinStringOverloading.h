#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string JoinStingp40(vector <string> text, string Deli)
{
	string Result = "";
	for (string &word : text)
	{
		Result += word;
		Result += Deli;
	}
	return Result.substr(0, Result.length() - Deli.length());
}

string JoinStingp40(string S[3], int Size, string Deli)
{
	string Result = "";
	for (int i = 0; i < Size; i++)
	{
		Result += S[i];
		Result += Deli;
	}
	return Result.substr(0, Result.length() - Deli.length());
}

void Prob40_JoinStringOverloading()
{
	vector <string> vS = { "Ali", "Mohammed", "Fadhi" };
	string S[3] = { "Foo", "Bar", "Zoo" };

	cout << "Joined vector string: " << JoinStingp40(vS, ",,,") << endl;
	cout << "Joined array string: " << JoinStingp40(S, 3, "   u   ") << endl;

	system("Pause>0");
}
