#pragma once

#include "Util.h"
#include "p58_PeriodsOverlap.h"


Date ReadDate(string date) {
	string dateText;
	cout << "Enter date (dd/mm/yyyy): "; getline(cin >> ws, dateText);
	
	return StringToDate(dateText);;
}

void p63() {
	PrintDate(ReadDate());
}