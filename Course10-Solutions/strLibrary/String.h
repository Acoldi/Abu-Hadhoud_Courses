#pragma once
#include <iostream>
#include <vector>
using namespace std;


class clsString
{
private:
	string _val;
public:
	clsString(string string) {
		this->_val = string;
	}
	clsString() {
		_val = "";
	}

	void PrintFirstLettersOfString()
	{
		bool IsFirstLetter = true;

		for (int i = 0; i < _val.length(); i++)
		{
			// If the current letter is not dash and the previous letter is dash
			if (_val[i] != ' ' && IsFirstLetter)
			{
				cout << _val[i] << endl;
			}

			IsFirstLetter = (_val[i] == ' ' ? true : false);
		}
	}

	static void PrintFirstLettersOfString(string text)
	{
		bool IsFirstLetter = true;

		for (int i = 0; i < text.length(); i++)
		{
			// If the current letter is not dash and the previous letter is dash
			if (text[i] != ' ' && IsFirstLetter)
			{
				cout << text[i] << endl;
			}

			IsFirstLetter = (text[i] == ' ' ? true : false);
		}
	}

	static string UpperFirstLetters(string Text)
	{
		bool IsFirstLetter = true;

		for (int i = 0; i < Text.length(); i++)
		{
			// If the current letter is not dash and the previous letter is dash
			if (Text[i] != ' ' && IsFirstLetter)
			{
				Text[i] = Text[i] - 32;
			}

			IsFirstLetter = (Text[i] == ' ' ? true : false);
		}
		return  Text;
	}

	void UpperFirstLetters()
	{
		bool IsFirstLetter = true;

		for (int i = 0; i < _val.length(); i++)
		{
			// If the current letter is not dash and the previous letter is dash
			if (_val[i] != ' ' && IsFirstLetter)
			{
				_val[i] = _val[i] - 32;
			}

			IsFirstLetter = (_val[i] == ' ' ? true : false);
		}
	}

	static string LowerFirstLetters(string Text)
	{
		bool IsFirstLetter = true;

		for (int i = 0; i < Text.length(); i++)
		{
			// If the current letter is not dash and the previous letter is dash
			if (Text[i] != ' ' && IsFirstLetter)
			{
				Text[i] = tolower(Text[i]);
			}

			IsFirstLetter = (Text[i] == ' ' ? true : false);
		}

		return Text;
	}

	void LowerFirstLetters()
	{
		bool IsFirstLetter = true;

		for (int i = 0; i < _val.length(); i++)
		{
			// If the current letter is not dash and the previous letter is dash
			if (_val[i] != ' ' && IsFirstLetter)
			{
				_val[i] = tolower(_val[i]);
			}

			IsFirstLetter = (_val[i] == ' ' ? true : false);
		}
	}

	static vector <string> Split(string text, string Delimeter)
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

	vector <string> Split(string Delimeter)
	{
		vector <string> vString;
		int pos = 0;
		string word = "";

		while ((pos = _val.find(Delimeter)) != std::string::npos)
		{
			word = _val.substr(0, pos);

			if (word != "")
				vString.push_back(word);

			_val.erase(0, pos + Delimeter.length());
		}

		if (_val != "")
			vString.push_back(_val);

		return vString;
	}


	static string DeletePunctsFromString(string text)
	{
		string S2 = "";

		for (int i = 0; i < text.length(); i++)
		{
			if (!ispunct(text[i]))
			{
				S2 += text[i];
			}
		}
		return S2;
	}


	string DeletePunctsFromString()
	{
		string S2 = "";

		for (int i = 0; i < _val.length(); i++)
		{
			if (!ispunct(_val[i]))
			{
				S2 += _val[i];
			}
		}
		return S2;
	}


};