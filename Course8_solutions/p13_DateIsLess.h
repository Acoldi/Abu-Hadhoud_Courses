#pragma once


#include "p12_AddingDaysToDate.h";


// Mine
//bool DateIsLess(Date sourceDate, Date DestDate)
//{
//	return sourceDate.year < DestDate.year ? true : sourceDate.month < DestDate.month ? true : sourceDate.day < DestDate.day;
//}

// Teacher's
bool DateIsBefore(Date sourceDate, Date DestDate)
{
	return sourceDate.year < DestDate.year ? true : (sourceDate.year == DestDate.year ? sourceDate.month < DestDate.month ? true : (sourceDate.month == DestDate.month ? sourceDate.day < DestDate.day : false) : false);
}



void p13_DateIsLess()
{
	Date date1 = Date();
	date1.day = 12;
	date1.month = 12;
	date1.year = 2022;

	Date date2 = Date();
	date2.day = 13;
	date2.month = 1;
	date2.year = 2022;


	if (DateIsBefore(date1, date2)) {
		cout << "Date1 is less than Date2!" << endl;
	}
	else
		cout << "Date1 is NOT less than Date2!" << endl;
}