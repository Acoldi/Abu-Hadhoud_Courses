#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"


class clsAddNewClientsScrean : protected clsScreen
{
	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "Name: ";
		Client.Name = clsInputValidate::ReadString();
		cout << "Last Name: ";
		Client.LastName = clsInputValidate::ReadString();
		cout << "Email: ";
		Client.Email = clsInputValidate::ReadString();
		cout << "Phone number: ";
		Client.PhoneNumber = clsInputValidate::ReadString();
		cout << "Pin Code: ";
		Client.PinCode = clsInputValidate::ReadString();
		cout << "Account Balance: ";
		Client.AccountBalance = clsInputValidate::ReadNumber<float>();

	}

	static void _AddNewClient()
	{
		cout << "Enter Account Number: ";
		string AccountNumber = clsInputValidate::ReadString();


		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account Number exists, choose another account number: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::GetAddNewClientObject(AccountNumber);

		_ReadClientInfo(Client);

		clsBankClient::enSaveResults SaveResult = Client.Save();

		switch (SaveResult)
		{
		case clsBankClient::svFailedEmptyObject:
			cout << "Error, Account is not saved because it is Empty\n";
			break;
		case clsBankClient::svSucceeded:
			cout << "\nClient Added Successfully\n";
			_Print(Client);
			break;
		case clsBankClient::svFailedAccountNumberExists:
			cout << "Account Number is already used, Enter another one: ";
			break;
		}

	}

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
	static void ShowAddNewClientsScreen()
	{
		if (!_ChecAccessPermission(clsUser::enPermissions::pAddNewClient))
		{
			return;
		}

		string title = "\t\tAdd New Client";

		_DrawScreenHeader(title);

		char Answer = 'y';
		do
		{
			_AddNewClient();
			cout << "Do you want to add another client? (y/n)\n - ";
			cin >> Answer;
		} while (tolower(Answer) == 'y');

	}
};

