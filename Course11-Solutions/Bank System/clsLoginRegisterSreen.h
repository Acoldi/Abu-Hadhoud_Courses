#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsString.h"

class clsLoginRegisterScreen : protected clsScreen
{

public:
	static void ShowLoginRegisterscreen()
	{
		if (!_ChecAccessPermission(clsUser::enPermissions::pShowLoginsLis))
		{
			return;
		}

		system("cls");

		vector<clsUser::stLoginRegisterRecord> vLoginsList = clsUser::GetLoginResgistersList();

		_DrawScreenHeader("\tLogin Register Screen");

		cout << endl;

		cout << setw(8) << "" << "___________________________________________________________________________________________________________\n";
		cout << setw(8) << "" << "|" << left << setw(25) << "Date/Time";
		cout << "|" << left << setw(18) << " Username";
		cout << "|" << left << setw(25) << " Password";
		cout << "|" << left << setw(18) << " Permissions" << endl;
		cout << setw(8) << "" << "___________________________________________________________________________________________________________\n\n";

				
		for (clsUser::stLoginRegisterRecord L : vLoginsList)
		{
			cout << setw(8) << "" << "| " << left << setw(25) << L.DateAndTime;
			cout << "| " << left << setw(18) << L.UserName;
			cout << "| " << left << setw(25) << L.Password;
			cout << "| " << left << setw(18) << L.Permissions << endl;
		}
		cout << setw(8) << "" << "___________________________________________________________________________________________________________\n\n";

		
	}
};

