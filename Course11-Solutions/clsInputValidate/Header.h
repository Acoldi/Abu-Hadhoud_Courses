#pragma once
#include <iostream>
#include "C://Users/HP/source/repos/Abu-Hadhoud_Courses/Course10-Solutions/DateLibrary/clsDate.h"
using namespace std;

class clsInputValidate
{
public:
	static bool IsNumberBetween(int n, int from, int to)
	{
		return (n < to) && (n > from);
	}

	static bool IsNumberBetween(bool n, bool from, bool to)
	{
		return (n < to) && (n > from);
	}

	static bool IsDateBetween(clsDate date, clsDate from, clsDate to)
	{
		if (IsValidDate(data) && IsValidDate(from) && IsValidDate(to))
		{
			return IsDateBetween(date, from, to);
		}
	}

	
};