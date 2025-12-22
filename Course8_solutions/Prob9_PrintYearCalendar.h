#pragma once

#include "Prob8_PrintMonthCalendar.h"



void PrintCalendarYearHeader(int year, int width)
{
	PrintLIne(width);
	string calendarYear = "Calendar - " + to_string(year);
	cout << endl << setw((width - calendarYear.length()) / 2) << "" << setw(calendarYear.length()) << calendarYear << endl << endl;
	PrintLIne(width);
	cout << endl;
}


void prob9_PrintYearCalendar()
{
	int year = ReadYear();
	int width = 30;

	PrintCalendarYearHeader(year, width);

	for (int month = 1; month <= 12; month++)
	{
		PrintCalendar(month, year, width);
		cout << endl;
	}

}