#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "Global.h"


class clsTransferScreen : protected clsScreen
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

	static string _ReadAccountNumber(string Message = "Enter account number: ")
	{
		string AccNum = "";
		cout << Message;
		AccNum = clsInputValidate::ReadString();

		return AccNum;
	}

public:
	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\tTranfer Screen");

		clsBankClient SourseClient = clsBankClient::Find(_ReadAccountNumber("Transfer From: "));
		_Print(SourseClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("Transfer To: "));
		_Print(DestinationClient);

		cout << "Enter the amount you want to transfer: ";
		float Amount = clsInputValidate::ReadNumber<float>();

		char answer = 'y';
		cout << "Are you sure you want to make this Transfer?\n - ";
		cin >> answer;

		if (tolower(answer) == 'y')
		{
			if (SourseClient.Transfer(Amount, DestinationClient, CurrentUser.UserName))
			{
				cout << "Transfer done!\n";
			}
			else
				cout << "Transfer Failed!\n";
		}
		else
		{
			cout << "Operation is cancelled!\n";
		}
		_Print(SourseClient);
		_Print(DestinationClient);
	}
};

