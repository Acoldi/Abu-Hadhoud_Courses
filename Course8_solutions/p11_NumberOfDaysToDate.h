#pragma once

#include "p10_YearDaysToCertainDay.h"
#include "Util.h"


//Date YearDaysToDate(short year, short days)
//{
//	Date date = Date();
//	date.year = year;
//	
//	short day = days;
//	short i = 1;
//	for (i; day > 31; i++)
//	{
//		day -= NumberOfDaysInMonth(year, i);
//	}
//	date.month = i;
//	date.day = day;
//
//	return date;
//}

Date YearDaysToDate(short year, short days)
{
	Date date = Date();
	date.year = year;
	date.month = 1;

	short remainingDays = days;
	short daysInMonth = 0;

	while (true)
	{
		daysInMonth = NumberOfDaysInMonth(date.year, date.month);

		if (remainingDays > daysInMonth) {
			remainingDays -= daysInMonth;
			date.month++;
		}
		else {
			date.day = remainingDays;
			break;
		}
	}

	return date;
}

void p11_NumberOfdaysToDate()
{	
	short year = ReadYear();

	short days = NumberOfDaysTillCertainDay(year, ReadDay(), ReadMonth());

	Date date = YearDaysToDate(year, days);
	cout << "Number of Days are: " << days << endl;
	cout << "Date is: " << " " << date.year << "/" << date.day << "/" << date.month;

}