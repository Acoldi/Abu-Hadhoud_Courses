#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string JoinStingp39(vector <string> text, string Deli)
{
	string Result = "";
	for (string &word : text)
	{
		if (Result != "")
			Result += Deli;
		Result += word;
	}
	return Result;
}

void Prob39_JoinString()
{
	vector <string> vS = { "Ali", "Mohammed", "Fadhi" };

	cout << "Vector elements: Ali, Mohammed, Fadhi" << endl;
	cout << "Joined string: " << JoinStingp39(vS, "       ") << endl;

	system("Pause>0");
}
