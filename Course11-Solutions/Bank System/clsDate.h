#pragma once
#pragma warning(disable : 4996)
#include<iostream>
#include <ctime>
#include <string>
#include "clsString.h"

class clsDate
{
	int _Day = 1;
	int _Month = 1;
	int _Year = 1;

	static short GetDayIndexFromDate(short year, short month, short day)
	{
		short a = (14 - month) / 12;

		short y = year - a;

		short m = month + 12 * a - 2;

		short d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

		return d;
	}

	static void printDays(short Year, short Month)
	{
		short Current = GetDayIndexFromDate(Year, Month, 1);

		short NumberOfDays = NumberOfDaysInMonth(Month, Year);

		short Days = 1;
		short Iterator = 0;

		// Print Spaces
		int i;
		for (i = 0; i < Current; i++)
		{
			cout << "     ";
		}

		for (int j = 1; j <= NumberOfDays; j++)
		{
			printf("%5i", j);

			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}

		cout << "\n______________________________________";
	}
	void printDays()
	{
		printDays(_Year, _Month);
	}

	static void PrintHeader(short Month)
	{
		string monthsArr[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov",
								"Dec" };
		cout << "__________________" << monthsArr[Month - 1] << "_______________" << endl;
		cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";
		short DaysOfMonth[5][7];
	}
	void PrintHeader()
	{
		PrintHeader(_Month);
	}

public:
	clsDate() {
		time_t t = time(0);
		tm* Now = localtime(&t);
		_Year = Now->tm_year + 1900;
		_Month = Now->tm_mon + 1;
		_Day = Now->tm_mday;
	}
	clsDate(string sDate)
	{
		vector<string> vDate;
		vDate = clsString::Split(sDate, "/");

		Day = stoi(vDate[0]);
		Month = stoi(vDate[1]);
		Year = stoi(vDate[2]);
	}
	clsDate(int year, int month, int day)
	{
		_Year = year;
		_Month = month;
		_Day = day;
	}
	clsDate(short PassedDays, int Year)
	{
		*this = PassedDaysToDate(PassedDays, Year);
	}


	void setYear(int Year)
	{
		_Year = Year;
	}
	void setMonth(short month)
	{
		_Month = month;
	}
	void setDay(short Day)
	{
		_Day = Day;
	}

	int getYear()
	{
		return _Year;
	}
	int getMonth()
	{
		return _Month;
	}
	int getDay()
	{
		return _Day;
	}
	__declspec(property(get = getYear, put = setYear)) int Year;
	__declspec(property(get = getMonth, put = setMonth)) int  Month;
	__declspec(property(get = getDay, put = setDay)) int Day;

	static short NumberOfDaysInYear(int Year)
	{
		return IsLeapYear(Year) ? 366 : 365;
	}
	short NumberOfDaysInYear()
	{
		return IsLeapYear(_Year) ? 366 : 365;
	}

	static int NumberOfHoursInYear(int Year)
	{
		return NumberOfDaysInYear(Year) * 24;
	}
	int NumberOfHoursInYear()
	{
		return NumberOfDaysInYear(_Year) * 24;
	}

	int NumberOfMinutesInYear(int Year)
	{
		return NumberOfHoursInYear(Year) * 60;
	}
	int NumberOfMinutesInYear()
	{
		return NumberOfHoursInYear(_Year) * 60;
	}

	int NumberOfSecondsInYear(int Year)
	{
		return NumberOfMinutesInYear(Year) * 60;
	}
	int NumberOfSecondsInYear()
	{
		return NumberOfMinutesInYear(_Year) * 60;
	}
	
	static bool IsLeapYear(int year)
	{
		return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
	}
	bool IsLeapYear()
	{
		return (_Year % 4 == 0 && _Year % 100 != 0 || _Year % 400 == 0);
	}

	static int NumberOfDaysInMonth(int Month, int Year)
	{
		clsDate Date;
		Date.Year = Year;
		if (Month < 1 || Month > 12)
			return 0;

		int NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		return Month == 2 ? (Date.IsLeapYear(Year) ? 29 : 28) : Month[NumberOfDays - 1];
	}
	int NumberOfDaysInMonth()
	{
		return NumberOfDaysInMonth(_Month, _Year);
	}

	static string  GetDayFromDate(short year, short month, short day, bool Short = false)
	{
		short a = (14 - month) / 12;

		short y = year - a;

		short m = month + 12 * a - 2;

		short d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

		if (!Short)
		{
			string Arr[7] = { "Sunday", "Monday", "Tuesday", "Wednsday", "Thursday", "Friday", "Saturday" };
			return Arr[d];
		}
		else
		{
			string Arr[7] = { "Sund", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
			return Arr[d];
		}
	}
	string  GetDayFromDate(bool Short = false)
	{
		return GetDayFromDate(_Year, _Month, _Day, Short);
	}

	static void PrintMonthCalendar(short Year, short Month)
	{
		PrintHeader(Month);
		printDays(Year, Month);
	}
	void PrintMonthCalendar()
	{
		PrintMonthCalendar(_Year, _Month);
	}

	static void printYearCalendar(short Year)
	{
		printf("\n_________________________________________\n");
		printf("	Calendar - %i \n", Year);
		printf("_________________________________________\n\n");

		for (int i = 0; i < 12; i++)
		{
			PrintMonthCalendar(Year, i + 1);
			cout << endl;
		}
	}
	void printYearCalendar()
	{
		printYearCalendar(_Year);
	}

	static short countDaysFromBeginninhOfYear(short Year, short Month, short Day)
	{
		short TotalDays = 0;

		for (int i = 0; i < Month - 1; i++)
		{
			TotalDays += NumberOfDaysInMonth(i + 1, Year);
		}

		return TotalDays += Day;
	}
	short countDaysFromBeginninhOfYear()
	{
		return countDaysFromBeginninhOfYear(_Year, _Month, _Day);
	}

	static clsDate AddDays(short AddedDays, clsDate Date)
	{
		short DaysPassed = countDaysFromBeginninhOfYear(Date.Year, Date.Month, Date.Day);

		short RemaindingDays = AddedDays + DaysPassed;

		Date.Year = Date.Year;

		Date.Month = 1;

		while (true)
		{
			short MonthDays = NumberOfDaysInMonth(Date.Month, Date.Year);

			if (RemaindingDays > MonthDays)
			{
				RemaindingDays -= MonthDays;
				Date.Month++;

				if (Date.Month == 13)
				{
					Date.Year++;
					Date.Month = 1;
				}
			}
			else
			{
				Date.Day = RemaindingDays;
				break;
			}

		}

		return Date;
	}
	clsDate AddDays(short AddedDays)
	{
		AddDays(AddedDays, *this);
	}

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
	}
	bool IsDate1BeforeDate2(clsDate Date2)
	{
		return IsDate1BeforeDate2(*this, Date2);
	}

	static bool IsDate1EqualtoDate2(clsDate Date1, clsDate Date2)
	{
		return  (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? Date1.Day == Date2.Day : false) : false;
	}
	bool IsDate1EqualtoDate2(clsDate Date2)
	{
		IsDate1EqualtoDate2(*this, Date2);
	}

	static bool IsLastDayInMonth(clsDate Date)
	{
		return Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year);
	}
	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}

	static bool IsLastMonthInYear(clsDate Date)
	{
		return Date.Month == 12;
	}
	bool IsLastMonthInYear()
	{
		return IsLastMonthInYear(*this);
	}

	static clsDate AddOneDay(clsDate Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date))
			{
				Date.Day = 1;
				Date.Month = 1;
				Date.Year++;
			}
			else
			{
				Date.Day = 1;
				Date.Month++;
			}
		}
		else
			Date.Day++;

		return Date;
	}
	clsDate AddOneDay()
	{
		return AddOneDay(*this);
	}

	static int DaysFromDateToDate1(clsDate Date, clsDate Date1, bool include = false)
	{
		int TotalDays = 0;

		if (include)
			TotalDays = 1;

		while (IsDate1BeforeDate2(Date, Date1))
		{
			Date = AddOneDay(Date);
			TotalDays++;
		}
		return TotalDays;
	}
	int DaysFromDateToDate1(clsDate Date1, bool include = false)
	{
		return DaysFromDateToDate1(*this, Date1);
	}

	static clsDate PassedDaysToDate(short DaysPassed, short Year)
	{
		clsDate Date;

		short RemaindingDays = DaysPassed;

		Date.Year = Year;

		Date.Month = 1;

		while (true)
		{
			short MonthDays = NumberOfDaysInMonth(Date.Month, Year);

			if (RemaindingDays > MonthDays)
			{
				RemaindingDays -= MonthDays;
				Date.Month++;
			}
			else
			{
				Date.Day = RemaindingDays;
				break;
			}
		}

		return Date;
	}
	
	static string DateToSting(clsDate Date)
	{
		return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
	}
	string DateToSting()
	{
		return DateToSting(*this);
	}

	static clsDate GetSystemDate()
	{
		int day, month, year;

		time_t t = time(0);
		tm* Now = localtime(&t);

		year = Now->tm_year + 1900;
		month = Now->tm_mon + 1;
		day = Now->tm_mday;

		return clsDate(year, month, day);
	}
	
	static string GetSystemDatetimeString()
	{
		int day, month, year, Hour, Minute, Second;

		time_t t = time(0);
		tm* Now = localtime(&t);

		year = Now->tm_year + 1900;
		month = Now->tm_mon + 1;
		day = Now->tm_mday;
		Hour = Now->tm_hour;
		Minute = Now->tm_min;
		Second = Now->tm_sec;

		return (to_string(day) + "/" +
			to_string(month) + "/" +
			to_string(year) + " - " +
			to_string(Hour) + ":" +
			to_string(Minute) + ":" +
			to_string(Second));
	}

	static bool IsValidDate(clsDate Date)
	{
		return !(Date.Month < 1 || Date.Month > 12) ? !(Date.Day < 1 || Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year)) : false;
	}
	bool IsValidDate()
	{
		return IsValidDate(*this);
	}

	static void SwapDates(clsDate& Date, clsDate& Date1)
	{
		clsDate temp;

		temp.Day = Date.Day;
		temp.Month = Date.Month;
		temp.Year = Date.Year;

		Date.Day = Date1.Day;
		Date.Month = Date1.Month;
		Date.Year = Date1.Year;

		Date1.Day = temp.Day;
		Date1.Month = temp.Month;
		Date1.Year = temp.Year;
	}

	static int YourAgeInDays(clsDate Birthdate)
	{
		clsDate Date1;
		Date1.Day = 5;
		Date1.Month = 8;
		Date1.Year = 2024;

		return DaysFromDateToDate1(Birthdate, Date1, true);
	}

	static clsDate IncreaseDateByOneWeek(clsDate &Date)
	{
		for (int i = 0; i < 7; i++)
		{
			Date = AddOneDay(Date);
		}
		return Date;
	}
	clsDate IncreaseDateByOneWeek()
	{
		IncreaseDateByOneWeek(*this);
	}

	enum enDatesOrder { Before = -1, Equal = 0, After = 1 };

	static enDatesOrder CompareDates(clsDate Date1, clsDate Date2)
	{
		return IsDate1EqualtoDate2(Date1, Date2) ? enDatesOrder::Equal : IsDate1BeforeDate2(Date1, Date2) ?
			enDatesOrder::Before : enDatesOrder::After;
	}
	enDatesOrder CompareDates(clsDate Date2)
	{
		CompareDates(*this, Date2);
	}

	static void Print(clsDate date)
	{
		cout << date.Day << "/"
			<< date.Month << "/"
			<< date.Year;
	}
	void Print()
	{
		cout << _Day << "/"
			<< _Month << "/"
			<< _Year;
	}

	static bool IsDate1AfterDate2(clsDate Date, clsDate Date1)
	{
		return !IsDate1BeforeDate2(Date, Date1) && !IsDate1EqualtoDate2(Date, Date1);
	}
	bool IsDate1AfterDate2(clsDate Date1)
	{
		IsDate1AfterDate2(*this, Date1);
	}

};

