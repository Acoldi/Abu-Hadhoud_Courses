#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"


class clsWithdrawScreen : protected clsScreen
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
	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("\tWithdraw Screen");

		string AccNum = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccNum))
		{
			cout << "No such account number, enter another one: ";
			clsInputValidate::ReadString();
		}

		// Load client
		clsBankClient Client = clsBankClient::Find(AccNum);

		_Print(Client);
			
		cout << "Balance to Withdraw: ";
		float Amount = clsInputValidate::ReadNumber<float>();
		char answer = 'y';
		cout << "Are you sure you want to Withdraw?\n - ";
		cin >> answer;

		if (tolower(answer) == 'y')
		{
			if (!Client.Withdraw(Amount))
			{
				cout << "The withdraw amount greater than account balance";
				return;
			}
			
			cout << "Balance Withdrawed Seccussfully\n";

			cout << "New Balance is: " << Client.AccountBalance << endl;
		}
		else
		{
			cout << "Operation is cancelled!\n";
		}
	}
};

