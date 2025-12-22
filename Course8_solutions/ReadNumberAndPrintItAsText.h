#pragma once
#include <iostream>
#include <string>

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

string integerText(int number, int position)
{
	string result = "";

	if (position == 2)
		result = GetTens(number);
	else if (position % 1 == 0)
		result = GetOnes(number).append(GetDecimalPositions(position));
	if (position % 3 == 0)
		result = GetOnes(number) + " Hundrads";

	return result;
}

string NumberToText(int& num, int& Position)
{
	if (num == 0) return PlaceValue();
	else return NumberToText(num, Position);

	int CurrentNumber = 0;
	int NextToNumber = 0;

	CurrentNumber = num % 10;
	num /= 10;
	Position++;

	if (CurrentNumber % 3 != 0)
	{
		NextToNumber = num % 10;

		if (NextToNumber == 1)
		{
			num /= 10;
			Position++;
			return ToTextInTens(CurrentNumber) + PlaceValue(Position);
		}

		return GetOnes(CurrentNumber) + PlaceValue(Position);
	}
	else
	{
		if (Position == 2)
			return GetTens(CurrentNumber);

		// In hundrads
		return GetOnes(CurrentNumber) + " Hundrad";
	}
}

string NumberToText(int &num)
{
	if ( == 0)
		return "";
	else
	{
		return 
	}

	

	return 
}

void ReadNumberToText()
{
	int num = ReadNumber("Enter a Number: ");

	cout << NumberToText(num);
}