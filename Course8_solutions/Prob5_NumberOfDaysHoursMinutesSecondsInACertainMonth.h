#pragma once
#include <iostream>
#include "Prob4_PrintNumberOfDaysInACertainYear.h"

using namespace std;

int NumberOfDaysInMonth(int year, int month)
{/*
	if (IsLeapYearOptimized(year) && month == 2) return 29;
	if (month == 2) return 28;
	if (month <= 0 || month > 12 || year <= 0) return 0;

	return (month <= 7) ? (month % 2 == 0 ? 30 : 31) : (month % 2 == 0 ? 31 : 30);*/

	int NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	
	return IsLeapYearOptimized(year) && month == 2 ? 29 : NumberOfDays[month - 1];
}

int NumberOfHoursInMonth(int year, int month)
{
	return NumberOfDaysInMonth(year, month) * 24;
}

int NumberOfMinutesInMonth(int year, int month)
{
	return NumberOfHoursInMonth(year, month) * 60;
}

int NumberOfSecondsInMonth(int year, int month)
{
	return NumberOfMinutesInMonth(year, month) * 24;
}

void prob5_PrintNumberOfDaysHoursMinutesInMonth()
{
	cout << "Year: "; int year = 0; cin >> year;
	cout << "Month: "; int month = 0; cin >> month;

	cout << "Number of days: " << NumberOfDaysInMonth(year, month) << endl;
	cout << "Number of hours: " << NumberOfHoursInMonth(year, month) << endl;
	cout << "Number of minutes: " << NumberOfMinutesInMonth(year, month) << endl;
	cout << "Number of seconds: " << NumberOfSecondsInMonth(year, month) << endl;

}
