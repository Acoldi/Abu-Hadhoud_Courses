#pragma once

#pragma once
#include <iostream>
#include <iomanip>
#include "Prob7_ReadDateAndPrintDayName.h"

enum Month {
    JANUARY = 1,
    FEBRUARY,   
    MARCH,      
    APRIL,      
    MAY,        
    JUNE,       
    JULY,       
    AUGUST,     
    SEPTEMBER,  
    OCTOBER,    
    NOVEMBER,   
    DECEMBER    
};

std::string monthToString(int month) {
    switch (month) {
    case Month::JANUARY: return "Jan";
    case Month::FEBRUARY: return "Feb";
    case Month::MARCH: return "Mar";
    case Month::APRIL: return "Apr";
    case Month::MAY: return "May";
    case Month::JUNE: return "Jun";
    case Month::JULY: return "Jul";
    case Month::AUGUST: return "Aug";
    case Month::SEPTEMBER: return "Sep";
    case Month::OCTOBER: return "Oct";
    case Month::NOVEMBER: return "Nov";
    case Month::DECEMBER: return "Dec";
    default: return "Unknown";

    }
}

void PrintHeader(int month, int width)
{
    if (width < 29) width = 29;
    cout << endl;
    cout << setw(width / 2 - 3) << setfill('_') << '_' << monthToString(month) << setw(width / 2) << '_' << endl << endl << setfill(' ');
    cout << setw(width / 7) << "Sun";
    cout << setw(width / 7) << "Mon";
    cout << setw(width / 7) << "Tue";
    cout << setw(width / 7) << "Wed";
    cout << setw(width / 7) << "Thu";
    cout << setw(width / 7) << "Fri";
    cout << setw(width / 7) << "Sat" << endl;
}

void PrintDays(int year, int month, int width)
{
    int days = NumberOfDaysInMonth(year, month);

    int startOfMonth = DayOrder(1, month, year);
    startOfMonth++;

    int dayCounter = 1;
    for (int i = 1; i <= days; i++)
    {
        cout << setw(width / 7);
        if (i < startOfMonth)
        {
            days++;
            cout << " ";
        }
        else
            cout << right << dayCounter++;
        
        if (i % 7 == 0)
            cout << endl;
    }

    cout << endl;
}

void PrintLIne(int length)
{
    for (int  i = 0; i < length; i++)
    {
        cout << "_";
    }

    cout << endl;
}

int ReadMonth()
{
    int month= 0;

    cout << "Enter month: "; cin >> month;
    return month;
}

int ReadYear()
{
    int year = 0;

    cout << "Enter year: "; cin >> year;

    return year;
}

void PrintCalendar(int month, int year, int width)
{
    PrintHeader(month, width);

    PrintDays(year, month, width);

    PrintLIne(width);
}

void Prob8_PrintMonthCalendar()
{
    int month = ReadMonth();
    int year = ReadYear();
    int width = 50;

    PrintCalendar(month, year, width);
}