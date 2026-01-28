#pragma once

#include "P19_DiffInDatesWithMinus.h"


Date DateAddOneWeek(Date date) {
	for (short i = 0; i < 7; i++)
	{
		date = DateAddOneDay(date);
	}

	return date;
}

Date DateAddWeekS(Date date, int weeks) {
	for (short i = 0; i < weeks; i++)
	{
		date = DateAddOneDay(date);
	}

	return date;
}


Date AddMonthsToDate(Date date, int months) {
	for (int i = 0; i < months; i++)
	{
		date.month++;
		if (date.month > 12) {
			date.year++;
			date.month = 1;
		}
		int monthdays = NumberOfDaysInMonth(date.year, date.month);
		if (date.day > monthdays) {
			date.day = monthdays;
		}
	}
	return date;
}

Date DateAddOneYear(Date date)
{
	return AddMonthsToDate(date, 12);
}

Date DateAddYears(Date date, int years) {
	for (int i = 0; i < years; i++)
	{
		date = DateAddOneYear(date);
	}

	return date;
}

Date DateAddYearsFaster(Date date, int years) {
	date.year += years;

	return date;
}

Date DateAddOneDecade(Date date) {
	return DateAddYearsFaster(date, 10);
}

Date DateAddDecades(Date date, int Decades) {
	for (int i = 0; i < Decades; i++)
	{
		date = DateAddOneDecade(date);
	}

	return date;
}

Date DateAddOneCentury(Date date) {
	for (short i = 0; i < 10; i++)
	{
		date = DateAddOneDecade(date);
	}

	return date;
}

Date DateAddOneMellenium(Date date) {
	date = DateAddYearsFaster(date, 1000);

	return date;
}

void p20to32()
{
	Date date/*ReadDate()*/;
	date.day = 18;
	date.month = 1;
	date.year = 2026;

	cout << endl << "Date after: " << endl;

	cout << "01-Adding one day is: "; PrintDate(DateAddOneDay(date)); cout << endl;
	cout << "02-Adding 10 day is: "; PrintDate(AddDaysToDate(date, 10)); cout << endl;
	cout << "03-Adding one week is: "; PrintDate(DateAddOneWeek(date)); cout << endl;
	cout << "04-Adding 10 week is: "; PrintDate(DateAddWeekS(date, 10)); cout << endl;
	cout << "05-Adding one month is: "; PrintDate(AddDaysToDate(date, NumberOfDaysInMonth
		(date.year, date.month))); cout << endl;
	cout << "06-Adding 10 months is: "; PrintDate(AddMonthsToDate(date, 10)); cout << endl;
	cout << "07-Adding 1 year is: "; PrintDate(DateAddOneYear(date)); cout << endl;
	cout << "08-Adding 10 year is: "; PrintDate(DateAddYears(date, 10)); cout << endl;
	cout << "09-Adding 10 year (faster) is: "; PrintDate(DateAddYearsFaster(date, 10)); cout << endl;
	cout << "10-Adding 1 decade is: "; PrintDate(DateAddOneDecade(date)); cout << endl;
	cout << "11-Adding 10 decades is: "; PrintDate(DateAddDecades(date, 10)); cout << endl;
	cout << "12-Adding 10 decades (faster) is: "; PrintDate(DateAddDecades(date, 10)); cout << endl;
	cout << "13-Adding 1 century is: "; PrintDate(DateAddOneCentury(date)); cout << endl;
	cout << "14-Adding 1 Millenium: "; PrintDate(DateAddOneMellenium(date)); cout << endl;
}