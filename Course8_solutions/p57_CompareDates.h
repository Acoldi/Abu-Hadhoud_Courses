#pragma once

#include "p56_DateIsAfter.h"

short DateCompare(Date date1, Date date2) {
	return DateIsAfter(date1, date2) ? 1 : DateIsEqual(date1, date2) ? 0 : -1;
}

void p57() {

	cout << "Date1" << endl;
	Date date1 = ReadDate();

	cout << "Date2" << endl;
	Date date2 = ReadDate();


	cout << "Compare results: " << DateCompare(date1, date2);
}
