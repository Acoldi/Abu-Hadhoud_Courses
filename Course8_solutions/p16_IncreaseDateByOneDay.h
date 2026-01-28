#pragma once

#include "p14_DateIsEqual.h"


// My sol
//Date DateAddOneDay(Date date)
//{
//	return AddDaysToDate(date, 1);
//}

// Teacher's
Date DateAddOneDay(Date date)
{
	if (IsLastDayInMonth(date)) {
		if (IsLastMonthInYear(date)) {
			date.day = 1;
			date.month = 1;
			date.year++;
		}
		else {
			date.day = 1;
			date.month++;
		}
	}
	else {
		date.day++;
	}
	return date;
}

void p16_IncreaseDateByOneDay() {
	Date date = ReadDate();

	PrintDate(date);

	date = DateAddOneDay(date);

	cout << "  Increased by one day: ";
	
	PrintDate(date);
}