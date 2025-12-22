#pragma once
#include <iostream>
#include "Prob4_PrintNumberOfDaysInACertainYear.h"

using namespace std;

enum enDayOrder {
	sun = 0,
	mon = 1,
	tue = 2,
	wed = 3,
	thu = 4,
	fri = 5,
	sat = 6,
};

enDayOrder DayOrder(int day, int month, int year)
{
	int a = (14 - month) / 12;
	int y = year - a;
	int m = month + 12 * a - 2;

	int d = (day + y + y / 4 - y / 100 + y / 400 + 31 * m / 12) % 7;

	return (enDayOrder) d;
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