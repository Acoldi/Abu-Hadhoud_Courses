#pragma once
#include "clsScreen.h"
#include "clsUser.h"


class clsUpdateUserScrean : protected clsScreen
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

		cout << "Permission to update client?\n - ";
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			Permissions += clsUser::enPermissions::pUpdateClientInfo;
		}

		cout << "Permission to delete clients client?\n - ";
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			Permissions += clsUser::enPermissions::pDeleteClient;
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

	static void _Print(clsUser User)
	{
		cout << "\tClietn Card\n";
		cout << "__________________________________\n";
		cout << "Name           : " << User.Name << endl;  // what variable are these?
		cout << "LastName       : " << User.LastName << endl;
		cout << "Email          : " << User.Email << endl;
		cout << "Phone Number   : " << User.PhoneNumber << endl;
		cout << "Username       : " << User.UserName << endl;
		cout << "Password       : " << User.Password << endl;
		cout << "Permissions    : " << User.Permissions << endl;
		cout << "__________________________________\n";
	}
public:
	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("\t\tUpdate User Screen");

		cout << "Enter Username: ";
		string UserName = clsInputValidate::ReadString();


		while (!clsUser::IsUserExist(UserName))
		{
			cout << "User Name doesn't exist, try again\n";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);
		_Print(User);

		// Are you sure check
		cout << "\n\t\tUpdating User info\n";
		_ReadUserInfo(User);

		clsUser::enSaveResults SaveResult;

		SaveResult = User.Save();  // This will save, or if the object is empty it won't. Returning the status of the saving process

		switch (SaveResult)
		{
		case clsUser::svFailedEmptyObject:
			cout << "Error, User is not saved because it is Empty\n";
			break;
		case clsUser::svSucceeded:
			cout << "\nUser Updated Successfully\n";
			_Print(User);
			break;
		}

	}

};
