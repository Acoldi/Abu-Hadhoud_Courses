#pragma once

#include <iostream>;
#include "Util.h";
using namespace std;


string DayName(Date date) {
	string dayname = "";

	enDayOrder dayorder = DayOrder(date.day, date.month, date.year);
	switch (dayorder)
	{
	case sun:
		dayname = "Sunday";
		break;
	case mon:
		dayname = "Monday";
		break;
	case tue:
		dayname = "Tuesday";
		break;
	case wed:
		dayname = "Wednesday";
		break;
	case thu:
		dayname = "Thursday";
		break;
	case fri:
		dayname = "Friday";
		break;
	case sat:
		dayname = "Satuday";
		break;
	default:
		break;
	}

	return dayname;
}

void Prob7_ReadDateAndPrintDayName()
{
	int day, month, year = 0;
	cout << "Year: "; cin >> year;
	cout << "Month: "; cin >> month;
	cout << "Day: "; cin >> day;

	switch (DayOrder(day, month, year))
	{
	case sun:
		cout << "Sunday";
		break;
	case mon:
		cout << "Monday";
		break;
	case tue:
		cout << "Tuesday";
		break;
	case wed:
		cout << "Wednesday";
		break;
	case thu:
		cout << "Thursday";
		break;
	case fri:
		cout << "Friday";
		break;
	case sat:
		cout << "Satuday";
		break;
	default:
		break;
	}
}