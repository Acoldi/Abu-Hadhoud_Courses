#pragma once
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int ReadNumber(string message)
{
	int num;
	cout << message;
	cin >> num;
	return num;
}

enum enNumber {
	One = 1,
	Two = 2,
	Three = 3,
	Four = 4,
	Five = 5,
	Six = 6,
	Seven = 7,
	Eight = 8,
	Nine = 9,
};

enum enTens {
	Ten = 1,
	Twenty = 2,
	Tirty = 3,
	Fourty = 4,
	Fifty = 5,
	Sixty = 6,
	Seventy = 7,
	Eighty = 8,
	Ninety = 9,
};

enum enDecimalPosition {
	Thousands = 4,
	Millions = 7,
	Billions = 10,
	Trillions = 13,
};

enum enTen {
	Eleven = 1,
	Twelve,
	Thirteen,
	Fourteen,
	Fifteen,
	Sixteen,
	Seventeen,
	Eighteen,
	Nineteen,
};

string GetFrom11To19(short numFrom1to19) {
	switch ((enTen)numFrom1to19)
	{
	case Eleven:
		return "Eleven";
	case Twelve:
		return "Twelve";
	case Thirteen:
		return "Thirteen";
	case Fourteen:
		return "Fourteen";
	case Fifteen:
		return "Fifteen";
	case Sixteen:
		return "Sixteen";
	case Seventeen:
		return "Seventeen";
	case Eighteen:
		return "Eighteen";
	case Nineteen:
		return "Nineteen";
	default:
		return "";
	}
}

string GetOnes(int number)
{
	switch ((enNumber)number)
	{
	case One:
		return " One";
		break;
	case Two:
		return " Two";
		break;
	case Three:
		return " Three";
		break;
	case Four:
		return " Four";
		break;
	case Five:
		return " Five";
		break;
	case Six:
		return " Six";
		break;
	case Seven:
		return " Seven";
		break;
	case Eight:
		return " Eight";
		break;
	case Nine:
		return " Nine";
		break;
	default:
		break;
	}
}

string GetTens(int number)
{
	switch ((enTens)number)
	{
	case Ten:
		return " Ten";
		break;
	case Twenty:
		return " Twenty";
		break;
	case Tirty:
		return " Thirty";
		break;
	case Fourty:
		return " Fourty";
		break;
	case Fifty:
		return " Fifty";
		break;
	case Sixty:
		return " Sixty";
		break;
	case Seventy:
		return " Senenty";
		break;
	case Eighty:
		return " Eighty";
		break;
	case Ninety:
		return " Ninety";
		break;
	default:
		break;
	}
}

string GetDecimalPositions(int posittion)
{
	switch ((enDecimalPosition)posittion)
	{
	case Thousands:
		return " Thousands";
		break;
	case Millions:
		return " Millions";
		break;
	case Billions:
		return " Billions";
		break;
	case Trillions:
		return " Trillions";
		break;
	default:
		return "";
		break;
	}
}

string NumberToText(int num)
{
	vector<int> v;
	int d = 0;
	string text = "";

	while (num > 0) {
		v.push_back(num % 10);
		num /= 10;
	}
	while (!v.empty()) {
		d = v.back();
		if (d == 0) {
			v.pop_back();
			continue;
		}
		if (v.size() % 3 == 0) {
			text += GetOnes(d) + " Hundrads";
		}
		else if (v.size() % 3 == 2) {
			if (d == 1) {
				v.pop_back();
				d = v.back();
				text += " " + GetFrom11To19(d);
			}
			else {
				text += " " + GetTens(d);
			}
		}
		else {
			text += " " + GetOnes(d) + " " + GetDecimalPositions(v.size());
		}
		v.pop_back();
	}
	return text;
}

void ReadNumberToText()
{
	int num = ReadNumber("Enter a Number: ");

	cout << NumberToText(num);
}