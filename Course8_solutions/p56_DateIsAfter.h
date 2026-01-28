#pragma once

#include "p55_VacationReturnDate.h"

bool DateIsAfter(Date date1, Date date2) {
	return !DateIsBefore(date1, date2) && !DateIsEqual(date1, date2);
}

void p56(){
	
	cout << "Date1" << endl;
	Date date1 = ReadDate();

	cout << "Date2" << endl;
	Date date2 = ReadDate();

	if (DateIsAfter(date1, date2)) {
		cout << "Date1 is after than Date2!" << endl;
	}
	else
		cout << "Date1 is NOT after Date2!" << endl;
}