#pragma once
#include "clsScreen.h"
#include "clsUser.h"

class clsFindUserScreen : protected clsScreen
{
	static void _Print(clsUser User)
	{
		cout << "\tUser Card\n";
		cout << "__________________________________\n";
		cout << "Name           : " << User.Name << endl;  // what variable are these?
		cout << "LastName       : " << User.LastName << endl;
		cout << "Email          : " << User.Email << endl;
		cout << "Phone Number   : " << User.PhoneNumber << endl;
		cout << "UserName       : " << User.UserName << endl;
		cout << "Password       : " << User.Password << endl;
		cout << "Permissions    : " << User.Permissions << endl;
		cout << "__________________________________\n";
	}
public:
	static void ShowFindUserScreen()
	{
		_DrawScreenHeader("\tFind User Screen");


		cout << "Enter User Name to find User: ";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(AccountNumber))
		{
			cout << "User Name is not found, try different one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(AccountNumber);

		_Print(User);

		if (User.IsEmpty())
			cout << "User is not found!\n";
		else
			cout << "User is found\n";
	}
};

