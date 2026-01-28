#pragma once


#include "p11_NumberOfDaysToDate.h";


Date ReadDate()
{
	Date date = Date();
	date.day = ReadDay();
	date.month = ReadMonth();
	date.year = ReadYear();

	return date;
}
void PrintDate(Date date) {
	cout << date.year << "/" << date.month << "/" << date.day;
}

//// My sol
//Date AddDaysToDate(Date date, int days)
//{
//	int remainingDays = days;
//	short yearDays = NumberOfDaysInYear(date.year);
//
//	while (true) {
//		if (remainingDays + NumberOfDaysTillCertainDay(date.year, date.day, date.month) > yearDays)
//		{
//			if (remainingDays > yearDays) {
//				date.year++;
//				remainingDays -= yearDays;
//			}
//			else {
//				date.year++;
//				remainingDays -= yearDays - NumberOfDaysTillCertainDay(date.year, date.day, date.month);
//				date = YearDaysToDate(date.year, remainingDays);
//				break;
//			}
//			yearDays = NumberOfDaysInYear(date.year);
//		}
//		else
//		{
//			date = YearDaysToDate(date.year, remainingDays);
//			break;
//		}
//	}
//	return date;
//}

// Teacher's sol  (a much more elegant solution)
Date AddDaysToDate(Date date, int days)
{
	// Remaining days are all year's days
	int remainingDays = days + NumberOfDaysFromBeginingOfYear(date.day, date.month, date.year);

	// Reset the year months (as they turned to days)
	date.month = 1;
	
	// I'll need this to make decisions about increasing months and years
	// to the date
	int monthDays = NumberOfDaysInMonth(date.year, date.month);
	
	while (true)
	{
		if (remainingDays > monthDays) {
			date.month++;
			remainingDays -= monthDays;

			// If month value is 13 
			if (date.month > 12) {
				date.year++;
				date.month = 1;
			}

			// Update month days, as the current month is the next previous one
			monthDays = NumberOfDaysInMonth(date.year, date.month);
		}
		else
		{
			date.day = remainingDays;
			break;
		}
	}

	return date;
}

void p12_AddingDaysToDate()
{
	Date date = ReadDate();
	int AddedDays;  cout << "Enter days to add: "; cin >> AddedDays;
	date = AddDaysToDate(date, AddedDays);

	cout << "New Date: "; PrintDate(date);
}