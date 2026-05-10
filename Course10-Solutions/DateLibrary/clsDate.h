#pragma once
#pragma warning(disable:4996)

#include <iostream>
#include <vector>
#include "c:\\Users\HP\source\repos\Abu-Hadhoud_Courses\Course7-Solutions\Prob37SplitString.h"
#include "C:\Users\HP\source\repos\Abu-Hadhoud_Courses\Course8_solutions\p8_PrintMonthCalendar.h"
#include "C:\Users\HP\source\repos\Abu-Hadhoud_Courses\Course8_solutions\p9_PrintYearCalendar.h"
using namespace std;


class clsDate
{
private:
	short _day;
	short _month;
	short _year;

	static clsDate _GetSystemDate() {
		time_t t = time(0);

		tm* now = localtime(&t);

		clsDate date = clsDate();
		date.year = now->tm_year + 1900;
		date.month = now->tm_mon + 1;
		date.day = now->tm_mday;

		return date;
	}

public:
	static void swapDates(clsDate& date1, clsDate& date2) {
		clsDate temp = clsDate();

		temp.day = date1.day;
		temp.month = date1.month;
		temp.year = date1.year;

		date1.day = date2.day;
		date1.month = date2.month;
		date1.year = date2.year;


		date2.day = temp.day;
		date2.month = temp.month;
		date2.year = temp.year;
	}

	
	void setDay(short day) {
		_day = day;
	}
	short getDay() {
		return _day;
	}
	void setMonth(short month) {
		_month = month;
	}
	short getMonth() {
		return _month;
	}
	void setYear(short year) {
		_year = year;
	}
	short getYear() {
		return _year;
	}

	__declspec(property(get = getDay, put = setDay)) short day;
	__declspec(property(get = getMonth, put = setMonth)) short month;
	__declspec(property(get = getYear, put = setYear)) short year;

	clsDate()
	{
		this->year = 2000;
		this->month = 1;
		this->day = 1;
	}
	clsDate(short day, short month, short year) {
		this->year = year;
		this->month = month;
		this->day = day;
	}
	/// <summary>
	/// day, month, year
	/// </summary>
	/// <param name="date"></param>
	clsDate(string date) {
		clsDate date1 = StringToDate(date);
		this->day = date1.day;
		this->month = date1.month;
		this->year = date1.year;
	}


	static bool IsLeapYear(short year)
	{
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}
	bool IsLeapYear()
	{
		return IsLeapYear(this->year);
	}

	static int NumberOfDaysInYear(int Year)
	{
		if (IsLeapYear(Year))
			return 366;
		else
			return 365;
	}
	int NumberOfDaysInYear()
	{
		return NumberOfDaysInYear(this->year);
	}

	static int NumberOfDaysInMonth(int year, int month)
	{
		int NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		return IsLeapYear(year) && month == 2 ? 29 : NumberOfDays[month - 1];
	}
	int NumberOfDaysInMonth()
	{
		return NumberOfDaysInMonth(this->year, this->month);
	}

	enum enDayOrder
	{
		sun = 0,
		mon,
		tue,
		wed,
		thu,
		fri,
		sat
	};

	static enDayOrder DayOrder(clsDate date)
	{
		int a = (14 - date.month) / 12;
		int y = date.year - a;
		int m = date.month + 12 * a - 2;

		int d = (date.day + y + y / 4 - y / 100 + y / 400 + 31 * m / 12) % 7;

		return (enDayOrder)d;
	}
	enDayOrder DayOrder()
	{
		return DayOrder(*this);
	}

	static string DayName(clsDate date) {
		string dayname = "";

		enDayOrder dayorder = DayOrder(date);
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
	string DayName() {
		return DayName(*this);
	}

	static bool IsValidDate(clsDate Date)
	{
		return !(Date.month < 1 || Date.month > 12) ? !(Date.day < 1 || Date.day > NumberOfDaysInMonth(Date.month, Date.year)) : false;
	}
	bool IsValidDate()
	{
		return IsValidDate(*this);
	}

	static clsDate StringToDate(string stringDate)
	{
		clsDate Date;
		vector<string> vDate;

		vDate = Splitp37(stringDate, "/");

		Date.day = stoi(vDate[0]);
		Date.month = stoi(vDate[1]);
		Date.year = stoi(vDate[2]);

		return Date;
	}

	static string DateToSting(clsDate Date)
	{
		return to_string(Date.day) + "/" + to_string(Date.month) + "/" + to_string(Date.year);
	}
	string DateToSting()
	{
		return DateToSting(*this);
	}

	static void PrintMonthCalendar(clsDate date, short width)
	{
		PrintHeader(date.month, width);

		PrintDays(date.year, date.month, width);

		PrintLIne(width);
	}
	void PrintMonthCalendar(short width)
	{
		PrintMonthCalendar(*this, width);
	}

	//------------------Using library codes----------

	static void PrintYearCalendar(short year, short width)
	{
		PrintCalendarYearHeader(year, width);
		clsDate date(1, 1, year);
		for (int month = 1; month <= 12; month++)
		{
			date.month = month;
			PrintMonthCalendar(date, width);
			cout << endl;
		}
	}
	void PrintYearCalendar(short width)
	{
		return PrintYearCalendar(this->year, width);
	}

	static int NumberOfDaysFromBeginingOfYear(clsDate date)
	{
		int days = 0;

		for (int i = 1; i < date.month; i++)
		{
			days += NumberOfDaysInMonth(date.year, i);
		}

		return days + date.day;
	}
	int NumberOfDaysFromBeginingOfYear()
	{
		return NumberOfDaysFromBeginingOfYear(*this);
	}

	static clsDate YearDaysToDate(short year, short days)
	{
		clsDate date = clsDate();
		date.year = year;
		date.month = 1;

		short remainingDays = days;
		short daysInMonth = 0;

		while (true)
		{
			daysInMonth = NumberOfDaysInMonth(date.year, date.month);

			if (remainingDays > daysInMonth) {
				remainingDays -= daysInMonth;
				date.month++;
			}
			else {
				date.day = remainingDays;
				break;
			}
		}

		return date;
	}
	clsDate YearDaysToDate(short days)
	{
		return YearDaysToDate(this->year, days);
	}

	static clsDate AddDaysToDate(clsDate &date, short days)
	{
		// Remaining days are all year's days
		int remainingDays = days + NumberOfDaysFromBeginingOfYear(date);

		// Reset the year months (as they turned to days)
		date.month = 1;

		// I'll need this to make decisions about increasing months and years
		// to the date
		int monthDays = NumberOfDaysInMonth(date.year, date.month);

		while (true)
		{
			if (remainingDays > monthDays) {
				date.month++;
				remainingDays -= monthDays;

				// If month value is 13 
				if (date.month > 12) {
					date.year++;
					date.month = 1;
				}

				// Update month days, as the current month is the next previous one
				monthDays = NumberOfDaysInMonth(date.year, date.month);
			}
			else
			{
				date.day = remainingDays;
				break;
			}
		}

		return date;
	}
	clsDate AddDaysToDate(short days)
	{
		return AddDaysToDate(*this, days);
	};

	static bool DateIsBefore(clsDate sourceDate, clsDate DestDate)
	{
		return sourceDate.year < DestDate.year ? true : (sourceDate.year == DestDate.year ? sourceDate.month < DestDate.month ? true : (sourceDate.month == DestDate.month ? sourceDate.day < DestDate.day : false) : false);
	}
	bool IsBefore(clsDate Dest)
	{
		return DateIsBefore(*this, Dest);
	}

	static bool DateIsEqual(clsDate sourceDate, clsDate DestDate)
	{
		return (sourceDate.year == DestDate.year) ? ((sourceDate.month == DestDate.month) ? (sourceDate.day == DestDate.day ? true : false) : false) : false;
	}
	bool DateIsEqual(clsDate date)
	{
		return DateIsEqual(*this, date);
	}

	static bool IsLastDayInMonth(clsDate date)
	{
		return NumberOfDaysInMonth(date.year, date.month) == date.day;
	}
	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}

	static bool IsLastDayInYear(clsDate date)
	{
		return NumberOfDaysInMonth(date.year, 12) == date.day;
	}
	bool IsLastDayInYear()
	{
		return IsLastDayInYear(*this);
	}

	static bool IsLastMonthInYear(clsDate date)
	{
		return date.month == 12;
	}
	bool IsLastMonthInYear()
	{
		return IsLastDayInYear(*this);
	}

	static void DateAddOneDay(clsDate &date)
	{
		if (IsLastDayInMonth(date)) {
			if (IsLastMonthInYear(date)) {
				date.day = 1;
				date.month = 1;
				date.year++;
			}
			else {
				date.day = 1;
				date.month++;
			}
		}
		else {
			date.day++;
		}
	}
	void DateAddOneDay()
	{
		DateAddOneDay(*this);
	}

	static int DateDifference(clsDate date1, clsDate date2, bool includeEndDay = false) {
		int days = 0;
		while (DateIsBefore(date1, date2)) {
			days++;
			DateAddOneDay(date1);
		}
		return includeEndDay ? ++days : days;
	}
	int DateDifference(clsDate date, bool includeEndDay = false) {
		return DateDifference(*this, date, includeEndDay);
	}

	static int AgeIndays(clsDate bdate) {
		int ageinDays = DateDifference(bdate, _GetSystemDate(), true);
		return ageinDays;
	}

	static int DateDifferenceTwoWays(clsDate date1, clsDate date2, bool includeEndDay = false) {
		int days = 0;
		int swapFlag = 1;

		if (DateIsBefore(date2, date1)) {
			swapDates(date1, date2);
			swapFlag *= -1;
		}

		while (DateIsBefore(date1, date2)) {
			days++;
			DateAddOneDay(date1);
		}

		return includeEndDay ? ++days * swapFlag : days * swapFlag;
	}
	int DateDifferenceTwoWays(clsDate date, bool includeEndDay = false) {
		return DateDifferenceTwoWays(*this, date, includeEndDay);
	}

	static bool isEndOfWeek(clsDate date) {
		enDayOrder enDayOrder = DayOrder(date);

		if (enDayOrder == sat) {
			return true;
		}
		else return false;
	}
	bool isEndOfWeek() {
		return isEndOfWeek(*this);
	}

	static bool dateIsWeekEnd(clsDate date) {
		enDayOrder enDayOrder = DayOrder(date);

		if (enDayOrder == sat || enDayOrder == fri) {
			return true;
		}
		else return false;
	}
	bool dateIsWeekEnd() {
		return dateIsWeekEnd(*this);
	}

	static bool isBusinessDay(clsDate date) {
		return !dateIsWeekEnd(date);
	}
	bool isBusinessDay() {
		return isBusinessDay(*this);
	}

	static bool DateIsAfter(clsDate date1, clsDate date2) {
		return !DateIsBefore(date1, date2) && !DateIsEqual(date1, date2);
	}
	bool DateIsAfter(clsDate date) {
		return !DateIsBefore(*this, date) && !DateIsEqual(*this, date);
	}

	static struct stPeriod
	{
		clsDate *startDate = new clsDate();
		clsDate *endDate = new clsDate();
	};

	static bool DateIsBetween(clsDate date, clsDate startDate, clsDate endDate) {
		return DateIsBefore(date, endDate) && DateIsAfter(date, startDate);
	}
	bool DateIsBetween(clsDate startDate, clsDate endDate) {
		return DateIsBefore(*this, endDate) && DateIsAfter(*this, startDate);
	}

	static bool PeriodsOverlap(stPeriod period1, stPeriod period2) {
		return !(DateIsAfter(*period1.startDate, *period2.endDate) || DateIsBefore(*period1.endDate, *period2.startDate));
	}


	static bool DateisInPeriod(clsDate date, stPeriod period) {
		return DateIsBetween(date, *period.startDate, *period.endDate);
	}
	bool DateisInPeriod(stPeriod period) {
		return DateisInPeriod(*this, period);
	}

	static int periodLength(stPeriod period, bool includeEndDay = false) {
		return DateDifferenceTwoWays(*period.startDate, *period.endDate, includeEndDay);
	}

	static int OverlappedDays(stPeriod period1, stPeriod period2) {
		int period1Length = periodLength(period1);
		int period2Length = periodLength(period2);

		int days = 0;

		if (period1Length < period2Length) {
			while (DateIsBefore(*period1.startDate, *period1.endDate)) {

				if (DateisInPeriod(*period1.startDate, period2))
					days++;

				DateAddOneDay(*period1.startDate);
			}
		}
		else
		{
			while (DateIsBefore(*period2.startDate, *period2.endDate)) {

				if (DateisInPeriod(*period2.startDate, period1))
					days++;

				DateAddOneDay(*period2.startDate);
			}
		}

		return days;
	}
	
	static string FormatDate(clsDate date, string Format) {
		string formattedDate = Format;

		formattedDate = replaceWordInString(Format, "dd", to_string(date.day));
		formattedDate = replaceWordInString(formattedDate, "mm", to_string(date.month));
		formattedDate = replaceWordInString(formattedDate, "yyyy", to_string(date.year));

		return formattedDate;
	}
	string FormatDate(string Format) {
		return FormatDate(*this, Format);
	}

	void PrintDate() {
		cout << this->year << "/" << this->month << "/" << this->day;
	}

};