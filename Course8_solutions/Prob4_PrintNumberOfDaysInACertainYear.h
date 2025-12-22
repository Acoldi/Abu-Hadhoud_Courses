#pragma once

#include <iostream>
#include "Prob3_IsLeapYearOptimized.h"

using namespace std;

int NumberOfDaysInYear(int Year)
{
	if (IsLeapYearOptimized(Year))
		return 366;
	else
		return 365;
}

int NumberOfHoursInYear(int Year)
{
	return NumberOfDaysInYear(Year) * 24;
}

int NumberOfMinutesInYear(int Year)
{
	return NumberOfHoursInYear(Year) * 60;
}

int NumberOfSecondsInYear(int Year)
{
	return NumberOfMinutesInYear(Year) * 60;
}

void Prob4_PrintNumberOfDaysMinutesHoursInYear()
{
	cout << "Enter a year: ";  int year = 0; cin >> year;

	cout << "Number of days: " << NumberOfDaysInYear(year) << endl;
	cout << "Number of hours: " << NumberOfHoursInYear(year) << endl;
	cout << "Number of minutes: " << NumberOfMinutesInYear(year) << endl;
	cout << "Number of seconds: " << NumberOfSecondsInYear(year) << endl;
}
