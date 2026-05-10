#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"


class clsDeleteClientsScrean : protected clsScreen
{
	static void _Print(clsBankClient Client)
	{
		cout << "\tClietn Card\n";
		cout << "__________________________________\n";
		cout << "Name           : " << Client.Name << endl;  // what variable are these?
		cout << "LastName       : " << Client.LastName << endl;
		cout << "Email          : " << Client.Email << endl;
		cout << "Phone Number   : " << Client.PhoneNumber << endl;
		cout << "Account Number : " << Client.AccountNumber() << endl;
		cout << "Pin Code       : " << Client.PinCode << endl;
		cout << "Account Balance: " << Client.AccountBalance << endl;
		cout << "__________________________________\n";
	}
public:
	static void ShowDeleteClientScreen()
	{
		if (!_ChecAccessPermission(clsUser::enPermissions::pDeleteClient))
		{
			return;
		}

		_DrawScreenHeader("Delete Client Screen");

		cout << "Enter account number: ";
		string AccountNumber = clsInputValidate::ReadString();


		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account Number doesn't exist, try again: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_Print(Client);

		char answer = 'n';
		cout << "Are you sure you want to delete this client?  ";
		cin >> answer;

		if (tolower(answer) == 'y')
		{
			if (Client.Delete())
			{
				cout << "Client deleted successfully!\n";
				_Print(Client);
			}
			else
			{
				cout << "Error, Client couldn't be deleted!\n";
			}
		}
		else
		{
			cout << "Client deletion is cancelled!\n";
		}
	}


};

