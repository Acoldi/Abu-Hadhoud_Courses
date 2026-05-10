#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"


class clsDepositeScreen : protected clsScreen
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

	static string _ReadAccountNumber()
	{
		string AccNum = "";
		cout << "Enter account number: ";
		AccNum = clsInputValidate::ReadString();

		return AccNum;
	}

public:
	static void ShowDepositeScreen()
	{
		_DrawScreenHeader("\tDeposite Screen");

		string AccNum = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccNum))
		{
			cout << "No such account number, enter another one: ";
			clsInputValidate::ReadString();
		}

		// Load client
		clsBankClient Client = clsBankClient::Find(AccNum);

		_Print(Client);
			
		cout << "Balance to deposite: ";
		float Amount = clsInputValidate::ReadNumber<float>();
		char answer = 'y';
		cout << "Are you sure you want to make this deposite?\n - ";
		cin >> answer;

		if (tolower(answer) == 'y')
		{
			// Save Client
			Client.Deposite(Amount);
			cout << "Balance Added Seccussfully\n";

			cout << "New Balance is: " << Client.AccountBalance << endl;
		}
		else
		{
			cout << "Operation is cancelled!\n";
		}
	}
};

