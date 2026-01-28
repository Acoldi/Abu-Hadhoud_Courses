#pragma once

#include "p8_PrintMonthCalendar.h"

void PrintHeader(int month, int width);
void PrintCalendar(int month, int year, int width);
void PrintLIne(int length);
int ReadMonth();
int ReadYear();


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