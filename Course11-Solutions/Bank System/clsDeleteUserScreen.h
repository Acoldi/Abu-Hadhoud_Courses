#pragma once
#include "clsScreen.h"
#include "clsUser.h"


class clsDeleteUserScreen: protected clsScreen
{
	static void _Print(clsUser User)
	{
		cout << "\tUser Card\n";
		cout << "__________________________________\n";
		cout << "Name           : " << User.Name << endl;  // what variable are these?
		cout << "LastName       : " << User.LastName << endl;
		cout << "Email          : " << User.Email << endl;
		cout << "Phone Number   : " << User.PhoneNumber << endl;
		cout << "User Name      : " << User.UserName << endl;
		cout << "Password       : " << User.Password << endl;
		cout << "Permisions     : " << User.Permissions << endl;
		cout << "__________________________________\n";
	}
public:
	static void ShowDeleteUserScreen()
	{
		_DrawScreenHeader("\t\tDelete Client Screen");

		cout << "Enter Username: ";
		string Username = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(Username))
		{
			cout << "Invalid Username, try again: ";
			Username = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(Username);
		_Print(User);

		char answer = 'n';
		cout << "Are you sure you want to delete this user?  ";
		cin >> answer;

		if (tolower(answer) == 'y')
		{
			if (User.Delete())
			{
				cout << "User deleted successfully!\n";
				_Print(User);
			}
			else
			{
				cout << "Error, Client couldn't be deleted!\n";
			}
		}
	}


};

