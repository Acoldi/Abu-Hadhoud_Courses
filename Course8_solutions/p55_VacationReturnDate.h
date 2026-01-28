#pragma once


#include "p54_VacationDays.h"


//Date DateVacationEnd(Date vacationStart, short vacationDays)
//{
//	short days = 0;
//
//	while (days < vacationDays) {
//
//		if (isBusinessDay(vacationStart)) {
//			days++;
//		}
//		
//		vacationStart = DateAddOneDay(vacationStart);
//	}
// 
//	return vacationStart;
//}

// Teacher's soul
Date DateVacationEnd(Date vacationStart, short vacationDays)
{
	while (dateIsWeekEnd(vacationStart)) {
		vacationStart = DateAddOneDay(vacationStart);
	}

	short weekendsCounter = 0;
	for (short i = 0; i < vacationDays + weekendsCounter; i++)
	{
		if (dateIsWeekEnd(vacationStart)) {
			weekendsCounter++;
		}

		vacationStart = DateAddOneDay(vacationStart);
	}

	while (dateIsWeekEnd(vacationStart)) {
		vacationStart = DateAddOneDay(vacationStart);
	}

	return vacationStart;
}


void p55() {
	cout << "Vacation start date" << endl;
	Date date1 = ReadDate();
	cout << endl << "Vacation Days: ";
	
	short vdays = 0;

	cin >> vdays;

	cout << "Vacation starts: " << DayName(date1) << ", "; PrintDate(date1);  cout << endl;

	cout << "Vacation ends: "; PrintDate(DateVacationEnd(date1, vdays));
}