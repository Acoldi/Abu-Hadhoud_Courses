#pragma once

#include "p58_PeriodsOverlap.h"

int periodLength(stPeriod period, bool includeEndDay = false) {
	return DateDifferenceTwoWays(period.startDate, period.endDate, includeEndDay);
}

bool DateisInPeriod(Date date, stPeriod period) {
	return DateIsBetween(date, period.startDate, period.endDate);
}

int OverlappedDays(stPeriod period1, stPeriod period2) {
	int period1Length = periodLength(period1);
	int period2Length = periodLength(period2);

	int days = 0;

	if (period1Length < period2Length) {
		while (DateIsBefore(period1.startDate, period1.endDate)) {

			if (DateisInPeriod(period1.startDate, period2))
				days++;
			
			period1.startDate = DateAddOneDay(period1.startDate);
		}
	}
	else
	{
		while (DateIsBefore(period2.startDate, period2.endDate)) {

			if (DateisInPeriod(period2.startDate, period1))
				days++;

			period2.startDate = DateAddOneDay(period2.startDate);
		}
	}

	return days;
}

void p61() {
	cout << "Period 1" << endl;
	stPeriod period1 = readPeriod();

	cout << "Period 2" << endl;
	stPeriod period2 = readPeriod();

	cout << "Overlapped Days: " << OverlappedDays(period1, period2);
}