#pragma once
#include "clsScreen.h"
#include "clsUsersListScreen.h"
#include "clsInputValidate.h"
#include "clsClientsListScreen.h"
#include "clsUtil.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"


class clsManageUSersScreen : protected clsScreen
{
	enum enManageUsersOption {
		eListUsers = 1, eAddNewUser, eDeleteUser, eUpdateUser, eFindUser, eMainMenue
	};

	static void _PrintCurrentScreenHeader(string Title)
	{
		cout << setw(37) << "" << left << "===============================" << endl;
		cout << setw(37) << "" << left << "\t" << Title << endl;
		cout << setw(37) << "" << left << "===============================" << endl;
	}

	static void _GoToManageUsersMenue()
	{
		cout << "\n\n\t\tPress any key to go back to manage users screen\n";
		system("pause>0");
		ShowManageUsersMenue();
	}

	static void _ShowListUsersScreen()
	{
		//cout << "Here List Users Screen\n";

		clsUsersListScreen::ShowUsersList();
	}

	static void _ShowAddNewUserScreen()
	{
		//cout << "Here Add New User Screen";

		clsAddNewUserScrean::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		//cout << "Here Delete User Screen";

		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		//cout << "Here Update User Screen";

		clsUpdateUserScrean::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		//cout << "Here Find User Screen";

		clsFindUserScreen::ShowFindUserScreen();
	}

	static enManageUsersOption _ReadManageUsersOptions()
	{
		short Choice = 0;
		cout << "Choose what do you want to do ( 1 to 6 )\n";
		Choice = clsInputValidate::ReadNumberBetween(1, 6, "Enter number between 1 and 7");  // Read Short type is required
		return (enManageUsersOption)Choice;
	}

	static void _PerformManageUseOption(enManageUsersOption Choice)
	{
		switch (Choice)
		{
		case clsManageUSersScreen::eListUsers:
			system("cls");
			_ShowListUsersScreen();
			_GoToManageUsersMenue();
			break;
		case clsManageUSersScreen::eAddNewUser:
			system("cls");
			_ShowAddNewUserScreen();
			_GoToManageUsersMenue();
			break;
		case clsManageUSersScreen::eDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_GoToManageUsersMenue();
			break;
		case clsManageUSersScreen::eUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_GoToManageUsersMenue();
			break;
		case clsManageUSersScreen::eFindUser:
			system("cls");
			_ShowFindUserScreen();
			_GoToManageUsersMenue();
			break;
		case clsManageUSersScreen::eMainMenue:
			// Do nothing to go back to main menue
			break;
		}
	}

public:
	static void ShowManageUsersMenue()
	{
		if (!_ChecAccessPermission(clsUser::enPermissions::pManageUsers))
		{
			return;
		}

		system("cls");

		_DrawScreenHeader("\t\tMain Screen");

		_PrintCurrentScreenHeader("\tManage Users Menue");

		cout << setw(37) << "" << left << "[1] List Users" << endl;
		cout << setw(37) << "" << left << "[2] Add New User" << endl;
		cout << setw(37) << "" << left << "[3] Delete User" << endl;
		cout << setw(37) << "" << left << "[4] Update User" << endl;
		cout << setw(37) << "" << left << "[5] Find User" << endl;
		cout << setw(37) << "" << left << "[6] Main Menue" << endl;
		cout << setw(37) << "" << left << "===============================" << endl;

		_PerformManageUseOption(_ReadManageUsersOptions());
	}
};

