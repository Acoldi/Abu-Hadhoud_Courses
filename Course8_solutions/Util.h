#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Date
{
	short day, month, year;
};

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

enDayOrder DayOrder(int day, int month, int year);
enDayOrder DayOrder(const Date& date);


enDayOrder DayOrder(int day, int month, int year)
{
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;

    int d = (day + y + y / 4 - y / 100 + y / 400 + 31 * m / 12) % 7;

    return (enDayOrder)d;
}

enDayOrder DayOrder(const Date& date)
{
    return DayOrder(date.day, date.month, date.year);
}

bool IsValidDate(Date Date)
{
    return !(Date.month < 1 || Date.month > 12) ? !(Date.day < 1 || Date.day > NumberOfDaysInMonth(Date.month, Date.year)) : false;
}

vector<string> SplitString(string text, string delimeter) {
    
    vector<string> vParts = vector<string>();
    string part = "";

    for (short i = 0; i < text.length(); i++)
    {
        if (text[i] == delimeter[0])
        {
            for (short j = 0; j < delimeter.length(); j++)
            {
                if (text[j] != delimeter[j]) {
                    break;
                }
            }
            vParts.push_back(part);
            part = "";
            continue;
        }
        part += text[i];
    }

    if (part != " ") {
        vParts.push_back(part);
    }

    return vParts;
}

// dd/mm/yyy
Date StringToDate(string stringDate)
{
    Date Date;
    vector<string> vDate;

    vDate = SplitString(stringDate, "/");

    Date.day = stoi(vDate[0]);
    Date.month = stoi(vDate[1]);
    Date.year = stoi(vDate[2]);

    return Date;
}

string DateToSting(Date Date)
{
    return to_string(Date.day) + "/" + to_string(Date.month) + "/" + to_string(Date.year);
}

string replaceWordInString(string text, string TextToReplace, string ReplaceTo) {
    // prepare a new string nst
    // for each char in text
    //   if char = first char of texttoreplace
    //      position = char position
    //      for each rchar in texttoreplace, char in text
    //         if char != rchar
    //              break
    //              position = 0;
    //         if char = lastrchar
    //              nst = slice of text till position
    //              append replaceto to nst
    //              [i]char = [i]rchar
    //              break
    //      append char to nst

    // My sol
    // --------------------------------------------------
    //string nst = "";

    //for (short i = 0; i < text.length(); i++)
    //{
    //    if (text[i] == TextToReplace[0]) {
    //        int slicePosition = i;
    //        for (short j = 0; j < TextToReplace.length(); j++) {
    //            if (text[i + j] != TextToReplace[j]) {
    //                slicePosition = 0;
    //                break;
    //            }
    //            if (j == TextToReplace.length() - 1) {
    //                //nst = text.substr(0, slicePosition);
    //                nst = text.replace(slicePosition, TextToReplace.length(), ReplaceTo);
    //                return nst;
    //            }
    //        }
    //    }
    //}
    //return "";
    // --------------------------------------------------
    // Had sol
    //cout << "\n" << __cplusplus << "\n";

    int pos = text.find(TextToReplace);
    while (pos != string::npos) {
        text.replace(pos, TextToReplace.length(), ReplaceTo);

        pos = text.find(TextToReplace);
    }

    return text;
}