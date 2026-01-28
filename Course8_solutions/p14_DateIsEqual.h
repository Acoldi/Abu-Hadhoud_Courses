#pragma once


#include "p13_DateIsLess.h";


 //Mine
//bool DateIsEqual(Date sourceDate, Date DestDate)
//{
//	return sourceDate.year == DestDate.year ? sourceDate.month == DestDate.month ? sourceDate.day == DestDate.day : true : false;
//}

// Teacher's
bool DateIsEqual(Date sourceDate, Date DestDate)
{
 return (sourceDate.year == DestDate.year) ? ((sourceDate.month == DestDate.month) ? (sourceDate.day == DestDate.day ? true : false) : false) : false;
}
/// <summary>
///	<Notes>
/// <1>
/// I guess using parentheses does make a difference!
/// </1>
/// </summary>

void p14_DateIsEqual()
{
	Date date1 = Date();
	date1.day = 12;
	date1.month = 12;
	date1.year = 2022;

	Date date2 = Date();
	date2.day = 12;
	date2.month = 12;
	date2.year = 2022;


	if (DateIsEqual(date1, date2)) {
		cout << "Date1 is equal to Date2!" << endl;
	}
	else
		cout << "Date1 is NOT equal to Date2!" << endl;
}