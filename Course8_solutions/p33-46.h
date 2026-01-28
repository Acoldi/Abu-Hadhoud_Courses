#pragma once

#include "p20.h"
#include "p15_DateIsLastDayInMonthInYear.h"

Date DateSubtractOneDay(Date date)
{
	if (date.day == 1) {
		if (date.month == 1) {
			date.day = 31;
			date.month = 12;
			date.year--;
		}
		else {
			date.month--;
			date.day = NumberOfDaysInMonth(date.year, date.month);
		}
	}
	else {
		date.day--;
	}
	return date;
}

Date dateSubtractXDays(Date date, int days) {
	for (int i = 0; i < days; i++)
	{
		date = DateSubtractOneDay(date);
	}

	return date;
}

Date DatedecreaseOneWeek(Date date) {
	for (short i = 0; i < 7; i++)
	{
		date = DateSubtractOneDay(date);
	}

	return date;
}

Date DateDecreaseWeekS(Date date, int weeks) {
	for (short i = 0; i < weeks; i++)
	{
		date = DatedecreaseOneWeek(date);
	}

	return date;
}

Date DateDecreaseOneMonth(Date date) {
	date.month--;
	if (date.month < 1) {
		date.year--;
		date.month = 12;
	}
	int monthdays = NumberOfDaysInMonth(date.year, date.month);
	if (date.day > monthdays) {
		date.day = monthdays;
	}

	return date;
}

Date DecreaseMonthsToDate(Date date, int months) {
	for (int i = 0; i < months; i++)
	{
		date = DateDecreaseOneMonth(date);
	}
	return date;
}

Date DateDecreaseOneYear(Date date)
{
	return DecreaseMonthsToDate(date, 12);
}

Date DateDecreaseYears(Date date, int years) {
	for (int i = 0; i < years; i++)
	{
		date = DateDecreaseOneYear(date);
	}

	return date;
}

Date DateDecreaseYearsFaster(Date date, int years) {
	date.year -= years;

	return date;
}

Date DateDecreaseOneDecade(Date date) {
	return DateDecreaseYearsFaster(date, 10);
}

Date DateDecreaseDecades(Date date, int Decades) {
	for (int i = 0; i < Decades; i++)
	{
		date = DateDecreaseOneDecade(date);
	}

	return date;
}

Date DateDecreaseOneCentury(Date date) {
	for (short i = 0; i < 10; i++)
	{
		date = DateDecreaseOneDecade(date);
	}

	return date;
}

Date DateDecreaseOneMellenium(Date date) {
	date = DateDecreaseYearsFaster(date, 1000);

	return date;
}

void p33to46()
{
	Date date/*ReDecreaseate()*/;
	date.day = 18;
	date.month = 1;
	date.year = 2026;

	cout << endl << "Date after: " << endl;

	cout << "01-Decreaseing one day is: "; PrintDate(DateSubtractOneDay(date)); cout << endl;

	cout << "02-Decreaseing 10 day is: "; PrintDate(dateSubtractXDays(date, 10)); cout << endl;

	cout << "03-Decreaseing one week is: "; PrintDate(DatedecreaseOneWeek(date)); cout << endl;

	cout << "04-Decreaseing 10 week is: "; PrintDate(DateDecreaseWeekS(date, 10)); cout << endl;

	cout << "05-Decreaseing one month is: "; PrintDate(DateDecreaseOneMonth(date)); cout << endl;

	cout << "06-Decreaseing 10 months is: "; PrintDate(DecreaseMonthsToDate(date, 10)); cout << endl;

	cout << "07-Decreaseing 1 year is: "; PrintDate(DateDecreaseOneYear(date)); cout << endl;

	cout << "08-Decreaseing 10 year is: "; PrintDate(DateDecreaseYears(date, 10)); cout << endl;

	cout << "09-Decreaseing 10 year (faster) is: "; PrintDate(DateDecreaseYearsFaster(date, 10)); cout << endl;

	cout << "10-Decreaseing 1 decade is: "; PrintDate(DateDecreaseOneDecade(date)); cout << endl;

	cout << "11-Decreaseing 10 decades is: "; PrintDate(DateDecreaseDecades(date, 10)); cout << endl;

	cout << "12-Decreaseing 10 decades (faster) is: "; PrintDate(DateDecreaseDecades(date, 10)); cout << endl;

	cout << "13-Decreaseing 1 century is: "; PrintDate(DateDecreaseOneCentury(date)); cout << endl;

	cout << "14-Decreaseing 1 Millenium: "; PrintDate(DateDecreaseOneMellenium(date)); cout << endl;

}