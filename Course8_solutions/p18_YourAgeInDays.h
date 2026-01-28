#pragma once
#pragma warning(disable : 4996)
#include "p17_DifferenceBetween2Dates.h";

Date GetSystemDate(){
	time_t t = time(0);

	tm* now = localtime(&t);

	Date date = Date();
	date.year = now->tm_year + 1900;
	date.month = now->tm_mon + 1;
	date.day = now->tm_mday;

	return date;
}

int AgeIndays(Date bdate) {
	int ageinDays = DateDifference(bdate, GetSystemDate(), true);
	return ageinDays;
}

void p18_YourAgeInDays()
{
	Date bdate = Date();
	cout << "Your birth date: ";
	bdate = ReadDate();

	cout << endl << "Your age in days: " << AgeIndays(bdate);
}