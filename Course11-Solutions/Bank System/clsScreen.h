#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsUser.h"
#include "Global.h"
#include "clsDate.h"

using namespace std;

class clsScreen
{
protected:

	static bool _ChecAccessPermission(clsUser::enPermissions Permission)
	{
		if (!CurrentUser.CheckAccessPermission((short)Permission))
		{
			cout << "\t\t\t\t\t_______________________________________\n";
			cout << "\t\t\t\t\t\tPermission is denied, contact your admin\n";
			cout << "\t\t\t\t\t_______________________________________\n";
			return false;
		}
		else
			return true;
	}

	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		cout << "\t\t\t\t\t____________________________________________\n";
		cout << "\n\t\t\t\t\t" << Title << endl;
		if (SubTitle != "")
		{
			cout << "\t\t\t\t\t" << SubTitle << endl;
		}
		cout << "\t\t\t\t\t____________________________________________\n\n";

		cout << "\t\t\t\t\tUser: " << CurrentUser.Name << endl;
		cout << "\t\t\t\t\tDate: " << clsDate::DateToSting(clsDate()); cout << endl;
	}
};

