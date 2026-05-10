#pragma once
#include "clsScreen.h"
#include "clsUser.h"

class clsAddNewUserScrean : protected clsScreen
{
	static short _ReadPermissionstoSet()
	{
		short Permissions = 0;

		char Answer = 'n';
		cout << "Do you want to give full access to this user?\n - ";
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			return clsUser::enPermissions::All;
		}

		cout << "Permission to show clients list?\n - ";
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			Permissions += clsUser::enPermissions::pShowClientList;
		}

		cout << "Permission to add new client?\n - ";
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			Permissions += clsUser::enPermissions::pAddNewClient;
		}

		cout << "Permission to delete clients client?\n - ";
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			Permissions += clsUser::enPermissions::pDeleteClient;
		}

		cout << "Permission to Update clients?\n - ";
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			Permissions += clsUser::enPermissions::pUpdateClientInfo;
		}

		cout << "Permission to find clients clients?\n - ";
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			Permissions += clsUser::enPermissions::pFindClient;
		}

		cout << "Permission to access transactioions menue?\n - ";
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			Permissions += clsUser::enPermissions::pTransactions;
		}

		cout << "Permission to access show Log Registers menue?\n - ";
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			Permissions += clsUser::enPermissions::pShowLoginsLis;
		}

		cout << "Permission to access manage users menue?\n - ";
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			Permissions += clsUser::enPermissions::pManageUsers;
		}

		return Permissions;
	}

	static void _ReadUserInfo(clsUser& User)
	{
		cout << "Name: ";
		User.Name = clsInputValidate::ReadString();
		cout << "Last Name: ";
		User.LastName = clsInputValidate::ReadString();
		cout << "Email: ";
		User.Email = clsInputValidate::ReadString();
		cout << "Phone number: ";
		User.PhoneNumber = clsInputValidate::ReadString();
		cout << "Password: ";
		User.Password = clsInputValidate::ReadString();
		User.Permissions = _ReadPermissionstoSet();

	}

	static void _AddNewUser()
	{
		cout << "Enter UserName: ";
		string UserName = clsInputValidate::ReadString();


		while (clsUser::IsUserExist(UserName))
		{
			cout << "User Name exists, enter another one: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::GetAddNewUserObject(UserName);

		_ReadUserInfo(User);

		clsUser::enSaveResults SaveResult = User.Save();

		switch (SaveResult)
		{
		case clsUser::svFailedEmptyObject:
			cout << "Error: User is not saved because it is Empty\n";
			break;
		case clsUser::svSucceeded:
			cout << "\nUser Added Successfully\n";
			_Print(User);
			break;
		case clsUser::svFailedUserNameExists:
			cout << "Error: User Name is already used";
			break;
		}

	}

	static void _Print(clsUser User)
	{
		cout << "\tClietn Card\n";
		cout << "__________________________________\n";
		cout << "Name           : " << User.Name << endl;
		cout << "LastName       : " << User.LastName << endl;
		cout << "Email          : " << User.Email << endl;
		cout << "Phone Number   : " << User.PhoneNumber << endl;
		cout << "Account Number : " << User.UserName << endl;
		cout << "Pin Code       : " << User.Password << endl;
		cout << "Account Balance: " << User.Permissions << endl;
		cout << "__________________________________\n";
	}


public:
	static void ShowAddNewUserScreen()
	{
		string title = "\t\tAdd New Client";

		_DrawScreenHeader(title);

		char Answer = 'y';
		do
		{
			_AddNewUser();
			cout << "Do you want to add another User? (y/n)\n - ";
			cin >> Answer;
		} while (tolower(Answer) == 'y');
	}
};

