#pragma once

#include "Util.h"
#include "p63_StringtoDate.h"

string FormatDate(Date date, string Format) {
	string formattedDate = Format;

	formattedDate = replaceWordInString(Format, "dd", to_string(date.day));
	formattedDate = replaceWordInString(formattedDate, "mm", to_string(date.month));
	formattedDate = replaceWordInString(formattedDate, "yyyy", to_string(date.year));

	return formattedDate;
}

void p65() {
	string format = "";
	cout << "Date (dd/mm/yyyy): "; 
	getline(cin >> ws, format);

	Date date = StringToDate(format);

	cout << FormatDate(date, "yyyy/mm/Hello dd");
}