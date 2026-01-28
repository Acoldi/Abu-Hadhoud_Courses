#pragma once
#include "p16_IncreaseDateByOneDay.h";

// My sol
//int DateDifference(Date date1, Date date2) {
//	if (DateIsLess(date1, date2)) {
//		int diff = 0;
//		while (!DateIsEqual(date1, date2)) {
//			date1 = DateAddOneDay(date1);
//			diff++;
//		}
//		return diff;
//	}
//	else {
//		int diff = 0;
//		while (!DateIsEqual(date2, date1)) {
//			date2 = DateAddOneDay(date2);
//			diff++;
//		}
//		return diff;
//	}
//	return 0;
//}

// Teacher's
int DateDifference(Date date1, Date date2, bool includeEndDay = false) {
	int days = 0;
	while (DateIsBefore(date1, date2)) {
		days++;
		date1 = DateAddOneDay(date1);
	}
	return includeEndDay ? ++days : days;
}


void p17_DifferenceBetween2Dates() {
	cout << "Date 1:" << endl;
	Date date1 = ReadDate();
	cout << endl << "Date 2:" << endl;
	Date date2 = ReadDate();
	
	cout << endl << "Date difference in days: " << DateDifference(date1, date2);
}