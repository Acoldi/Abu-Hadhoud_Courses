#pragma once

#include "p8_PrintMonthCalendar.h"

int ReadDay()
{
	int day;
	cout << "Enter a day: ";
	cin >> day;

	return day;
}

int NumberOfDaysFromBeginingOfYear(int day, int month, int year)
{
	int days = 0;

	for (int  i = 1; i < month; i++)
	{
		days += NumberOfDaysInMonth(year, i);
	}

	return days + day;
}


void NumberOfDaysTillCertainDay()
{
	int Day = ReadDay();
	int Month = ReadMonth();
	int Year = ReadYear();

	cout << "Number of days till " << Year << " " << Month << " " << Day << " is: ";

	cout << NumberOfDaysFromBeginingOfYear(Day, Month, Year);
}

int NumberOfDaysTillCertainDay(int Year, int Day, int Month)
{
	 int result =  NumberOfDaysFromBeginingOfYear(Day, Month, Year);

	 return result;
}

