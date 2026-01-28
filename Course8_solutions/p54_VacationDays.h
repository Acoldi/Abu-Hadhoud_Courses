#pragma once

#include "p47to53.h"
#include "p7_ReadDateAndPrintDayName.h"


short VacationDaysCount(Date vacationStart, Date vacationEnd) {
	short days = 0;

	while (DateIsBefore(vacationStart, vacationEnd)) {
		
		if (isBusinessDay(vacationStart)) {
			days++;
		}
		vacationStart = DateAddOneDay(vacationStart);
	}

	return days;
}

void p54()
{
	cout << "Vacation start date: ";
	Date date1 = ReadDate();
	cout << endl;
	cout << "Vacation end date: ";
	Date date2 = ReadDate();

	cout << "Vacation starts: " <<  DayName(date1) << ", "; PrintDate(date1);  cout << endl;
	cout << "Vacation ends: " << DayName(date2) << ", ";  PrintDate(date2); cout << endl;

	cout << "Actual vacatoin days: " << VacationDaysCount(date1, date2);
}