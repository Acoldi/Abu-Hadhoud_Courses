#pragma once
#include <iostream>
using namespace std;


bool IsLeapYearOptimized(int Year)
{
	//return (Year % 400 == 0) ? true : (Year % 100 == 0) ? false : Year % 4 == 0;
	// Or

	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

void Prob3_IsleapYear()
{
	int year;
	cout << "Enter a year: "; cin >> year;
	if (IsLeapYearOptimized(year))
		cout << year << " IS a leap year";
	else
		cout << year << " is NOT a leap year";
}