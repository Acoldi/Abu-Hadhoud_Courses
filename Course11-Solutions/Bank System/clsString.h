#pragma once
#include <iostream>
#include <vector>
using namespace std;

class clsString
{
	string _Value;

public:
	clsString()
	{
		_Value = "";
	}

	clsString(string value)
	{
		_Value = value;
	}

	void SetValue(string Value)
	{
		_Value = Value;
	}
	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;


	static int CountWordsInString(string text)
	{
		int pos = 0, counter = 0;
		string delim = " ";
		string word = "";

		while ((pos = text.find(delim)) != std::string::npos)
		{
			word = text.substr(0, pos);

			if (word != "")
				counter++;

			text.erase(0, pos + delim.length());  // We added 1 here because the position starts from 0 (array positions)
			// So maybe its position is 3 after "ALi" word,  #q maybe the erase() excludes the second parameter!!.
		}

		if (text != "")
			counter++;

		return counter;
	}
	int CountWordsInString()
	{
		return CountWordsInString(_Value);
	}

	static vector<string> Split(string text, string Delimeter)
	{
		vector <string> vString;
		int pos = 0;
		string word = "";

		while ((pos = text.find(Delimeter)) != std::string::npos)
		{
			word = text.substr(0, pos);


			vString.push_back(word);

			text.erase(0, pos + Delimeter.length());
		}


		vString.push_back(text);

		return vString;
	}
	vector<string> Split(string Delimeter)
	{
		return Split(_Value, Delimeter);
	}

	static string TrimLeft(string text)
	{
		for (int i = 0; i < text.length(); i++)
		{
			if (text[i] != ' ')
			{
				return text.substr(i, text.length() - i);
			}
		}
		return "";
	}
	string TrimLeft()
	{
		TrimLeft(_Value);
	}

	static string TrimRight(string text)
	{
		for (int i = text.length(); i > 0; i--)
		{
			if (text[i] != ' ')
			{
				return text.substr(0, i);
			}
		}
		return "";
	}
	string TrimRight()
	{
		TrimRight(_Value);
	}

	static string TrimAll(string text)
	{
		return TrimLeft(TrimRight(text));
	}
	string TrimAll()
	{
		return TrimAll(_Value);
	}
	 
	static string JoinSting(vector <string> text, string Deli)
	{
		string Result = "";
		for (string& word : text)
		{
			Result += word;
			Result += Deli;
		}
		return Result.substr(0, Result.length() - Deli.length());
	}

	static string ReverseWordsInString(string text)
	{
		vector<string> vString;
		string S2 = "";

		vString = Split(text, " ");

		vector<string>::iterator vIterator = vString.end();

		while (vIterator != vString.begin())
		{
			vIterator--;
			S2 += *vIterator + " ";
		}

		return S2.substr(0, S2.length() - 1);

	}
	void ReverseWordsInString()
	{
		 _Value = ReverseWordsInString(_Value);
	}

	static string ReplaceWordInString(string text, string StringToReplace, string ReplaceTo)
	{
		int Pos = text.find(StringToReplace);

		while (Pos != std::string::npos)
		{
			text.replace(Pos, StringToReplace.length(), ReplaceTo);
			Pos = text.find(StringToReplace);  // Find next
		}

		return text;
	}
	void ReplaceWordInString(string StringToReplace, string ReplaceTo)
	{
		_Value = ReplaceWordInString(_Value, StringToReplace, ReplaceTo);
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
	void DeletePunctsFromString()
	{
		_Value = DeletePunctsFromString(_Value);
	}

	static string UpperFirstLetters(string Text)
	{
		bool IsFirstLetter = true;

		for (int i = 0; i < Text.length(); i++)
		{
			// If the current letter is not dash and the previous letter is dash
			if (Text[i] != ' ' && IsFirstLetter)
			{
				Text[i] = toupper(Text[i]);
			}

			IsFirstLetter = (Text[i] == ' ' ? true : false);
		}
		return Text;
	}
	void UpperFirstLetters()
	{
		_Value = UpperFirstLetters(_Value);
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
		_Value = LowerFirstLetters(_Value);
	}

	static string LowerStringLetters(string Text)
	{
		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = tolower(Text[i]);
		}
		return Text;
	}
	void LowerStringLetters()
	{
		_Value = LowerStringLetters(_Value);
	}

	static string UpperStringLetters(string Text)
	{

		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = toupper(Text[i]);
		}
		return Text;
	}
	void UpperStringLetters()
	{
		_Value = UpperStringLetters(_Value);
	}



};