#pragma once

#include "Util.h"
#include "p33-46.h"


bool isEndOfWeek(Date date) {
	enDayOrder enDayOrder = DayOrder(date);

	if (enDayOrder == sat) {
		return true;
	}
	else return false;
}

bool dateIsWeekEnd(Date date) {
	enDayOrder enDayOrder = DayOrder(date);

	if (enDayOrder == sat || enDayOrder == fri) {
		return true;
	}
	else return false;
}

bool isBusinessDay(Date date) {
	return !dateIsWeekEnd(date);
}

int daysTillEndOfWeek(Date date) {
	if (isEndOfWeek(date)) return 0;
	else
	{
		/*int counter = 0;
		for (short i = 0; !isEndOfWeek(date); i++)
		{
			counter++;
			date = DateAddOneDay(date);
		}
		return counter;*/

		return 6 - DayOrder(date);
	}
}

int daysTillEndOfMonth(Date date) {
	if (IsLastDayInMonth(date)) return 0;
	
	return NumberOfDaysInMonth(date.year, date.month) - date.day;
}

int daysTillEndOfYear(Date date) {
	if (IsLastDayInYear(date)) return 0;
	
	return NumberOfDaysInYear(date.year) - NumberOfDaysFromBeginingOfYear(date.day, date.month, date.year);
}

void p47to53()
{
	Date date = GetSystemDate();

	cout << "Today is " << DayName(date) << " , "
		<< date.day << "/" << date.month << "/" << date.year << endl << endl;

	cout << "Is it End of Week?\n";
	if (isEndOfWeek(date))
		cout << "Yes it is end of week.\n\n";
	else
		cout << "No Not end of week.\n\n";

	cout << "Is it Weekend?\n";
	if (dateIsWeekEnd(date))
		cout << "Yes it is a week end.\n\n";
	else
		cout << "No it is NOT a week end.\n\n";

	cout << "Is it Business Day?\n";
	if (isBusinessDay(date))
		cout << "Yes it is a business day.\n\n";
	else
		cout << "No it is NOT a business day.\n\n";

	cout << "Days until end of week : " << daysTillEndOfWeek(date) << " Day(s).\n";
	cout << "Days until end of month : " << daysTillEndOfMonth(date) << " Day(s).\n";
	cout << "Days until end of year  : " << daysTillEndOfYear(date) << " Day(s).\n";
}