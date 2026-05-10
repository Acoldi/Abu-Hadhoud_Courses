#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"

class clsFindClientScreen : protected clsScreen
{
	static void _Print(clsBankClient Client)
	{
		cout << "\tClietn Card\n";
		cout << "__________________________________\n";
		cout << "Name           : " << Client.Name << endl;
		cout << "LastName       : " << Client.LastName << endl;
		cout << "Email          : " << Client.Email << endl;
		cout << "Phone Number   : " << Client.PhoneNumber << endl;
		cout << "Account Number : " << Client.AccountNumber() << endl;
		cout << "Pin Code       : " << Client.PinCode << endl;
		cout << "Account Balance: " << Client.AccountBalance << endl;
		cout << "__________________________________\n";
	}
public:
	static void ShowFindClientScreen()
	{
		if (!_ChecAccessPermission(clsUser::enPermissions::pFindClient))
		{
			return;
		}

		_DrawScreenHeader("\tFind Client Screen");


		cout << "Enter Account Number to find client: ";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account Number is not found, try different one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_Print(Client);

		if (Client.IsEmpty())
			cout << "Client is not found!\n";
		else
			cout << "Client is found\n";
	}
};

