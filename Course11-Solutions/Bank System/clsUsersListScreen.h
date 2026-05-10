#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"

class clsUsersListScreen : protected clsScreen
{
	

public:
	static void ShowUsersList()
	{
		system("cls");

		vector <clsUser> vUsers = clsUser::GetUsersList();
		string Title = "\t Users List";
		string SubTitle = "\t   ( " + to_string(vUsers.size()) + " ) Users";

		_DrawScreenHeader(Title, SubTitle);

		cout << endl;

		cout << setw(8) << "" << "___________________________________________________________________________________________________________\n";
		cout << setw(8) << "" << "|" << left << setw(15) << "Name";
		cout << "|" << left << setw(12) << "LastName";
		cout << "|" << left << setw(18) << "Email";
		cout << "|" << left << setw(15) << "Phone Number";
		cout << "|" << left << setw(15) << "User Name";
		cout << "|" << left << setw(15) << "Password";
		cout << "|" << left << setw(10) << "Permissions" << endl;
		cout << setw(8) << "" << "___________________________________________________________________________________________________________\n\n";


		for (clsUser U : vUsers)
		{
			cout << setw(8) << "" << "|" << left << setw(15) << U.Name;
			cout << "|" << left << setw(12) << U.LastName;
			cout << "|" << left << setw(18) << U.Email;
			cout << "|" << left << setw(15) << U.PhoneNumber;
			cout << "|" << left << setw(15) << U.UserName;
			cout << "|" << left << setw(15) << U.Password;
			cout << "|" << left << setw(10) << U.Permissions << endl;
		}
		if (vUsers.size() == 0)
		{
			cout << "\t\t\t\t\t\t\tNo Users!\n";
		}
		cout << setw(8) << "" << "___________________________________________________________________________________________________________\n\n";
	}
};

