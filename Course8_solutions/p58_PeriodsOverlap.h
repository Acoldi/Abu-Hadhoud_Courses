#pragma once

#include "p57_CompareDates.h"

struct stPeriod
{
	Date startDate;
	Date endDate;
};

bool DateIsBetween(Date date, Date startDate, Date endDate) {
	return DateIsBefore(date, endDate) && DateIsAfter(date, startDate);
}

bool PeriodsOverlap(stPeriod period1, stPeriod period2) {
	return !(DateIsAfter(period1.startDate, period2.endDate) || DateIsBefore(period1.endDate, period2.startDate));
}

stPeriod readPeriod() {
	stPeriod period;

	cout << "Start date" << endl;
	period.startDate = ReadDate();
	cout << endl;

	cout << "End date" << endl;
	period.endDate = ReadDate();
	cout << endl;

	return period;
}

void p58() {
	cout << "Enter period 1" << endl;
	stPeriod period1 = readPeriod();

	cout << "Enter period 2" << endl;
	stPeriod period2 = readPeriod();

	cout << endl << PeriodsOverlap(period1, period2) ? "Overlapped!" : "Not Overlapped";
}