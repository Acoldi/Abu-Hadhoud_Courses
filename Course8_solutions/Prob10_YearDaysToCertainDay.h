#pragma once

#include "Prob9_PrintYearCalendar.h"
#include "Prob5_NumberOfDaysHoursMinutesSecondsInACertainMonth.h"

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


void prob10_PrintNumberOfDaysTillCertainDay()
{
	int Day = ReadDay();
	int Month = ReadMonth();
	int Year = ReadYear();

	cout << "Number of days till " << Year << " " << Month << " " << Day << " is: ";

	cout << NumberOfDaysFromBeginingOfYear(Day, Month, Year);
}

