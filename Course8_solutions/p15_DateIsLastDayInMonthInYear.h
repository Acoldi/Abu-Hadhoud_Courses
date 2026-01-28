#pragma once


#include "p14_DateIsEqual.h";

bool IsLastDayInMonth(Date date)
{
	return NumberOfDaysInMonth(date.year, date.month) == date.day;
}

bool IsLastDayInYear(Date date)
{
	return NumberOfDaysInMonth(date.year, 12) == date.day;
}

bool IsLastMonthInYear(Date date)
{
	return date.month == 12;
}


void p15_IsLastDayInMonthInYear()
{
	Date date = ReadDate();

	if (IsLastDayInMonth(date))
		cout << "Yes last day in month!" << endl;

	if (IsLastDayInYear(date))
		cout << "Yes last day in year!" << endl;
}