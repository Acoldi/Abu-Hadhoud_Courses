#pragma once
#include <iostream>
#include <string>

using namespace std;


bool IsLeapYear(int Year)
{
	if (Year % 400 == 0)
		return true;

	if (Year % 100 == 0)
		return false;

	return Year % 4 == 0;
}

void Prob2_IsleapYear()
{
	int year; 
	cout << "Enter a year: "; cin >> year;
	if (IsLeapYear(year))
		cout << year << " IS a leap year";
	else
		cout << year << " is NOT a leap year";
}