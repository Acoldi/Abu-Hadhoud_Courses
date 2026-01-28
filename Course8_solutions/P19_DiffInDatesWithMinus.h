#pragma once
#include "p18_YourAgeInDays.h"


//int DateDifferenceTwoWays(Date date1, Date date2, bool includeEndDay = false) {
//	int days = 0;
//	if (DateIsLess(date1, date2)) {
//		while (DateIsLess(date1, date2)) {
//			days++;
//			date1 = DateAddOneDay(date1);
//		}
//		return includeEndDay ? ++days : days;
//	}
//	else {
//
//		while (DateIsLess(date2, date1)) {
//			days++;
//			date2 = DateAddOneDay(date2);
//		}
//		int result = includeEndDay ? ++days : days;
//
//		return result* -1;
//	}
//}

void swapDates(Date &date1, Date &date2) {
	Date temp = Date();

	temp.day = date1.day;
	temp.month = date1.month;
	temp.year = date1.year;

	date1.day = date2.day;
	date1.month = date2.month;
	date1.year = date2.year;

	
	date2.day = temp.day;
	date2.month = temp.month;
	date2.year = temp.year;
	
}

// His sol -He cares about _backward compatability_ that is, he 
// doesn't break method interfaces and tries not to change in the
// implementaion as much as required
int DateDifferenceTwoWays(Date date1, Date date2, bool includeEndDay = false) {
	int days = 0;
	int swapFlag = 1;

	if (DateIsBefore(date2, date1)) {
		swapDates(date1, date2);
		swapFlag *= -1;
	}

	while (DateIsBefore(date1, date2)) {
		days++;
		date1 = DateAddOneDay(date1);
	}

	return includeEndDay ? ++days * swapFlag: days * swapFlag;
}


void P19_DiffInDatesWithMinus()
{
	cout << "Date 1:" << endl;
	Date date1 = ReadDate();
	cout << endl << "Date 2:" << endl;
	Date date2 = ReadDate();

	cout << endl << "Date difference in days: " << DateDifferenceTwoWays(date1, date2);
}