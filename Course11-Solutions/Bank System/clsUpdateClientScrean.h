#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"


class clsUpdateClientScrean : protected clsScreen
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

	static void ShowUpdateClientScreen()
	{
		if (!_ChecAccessPermission(clsUser::enPermissions::pUpdateClientInfo))
		{
			return;
		}

		_DrawScreenHeader("\t\tUpdate Client Screen");

		cout << "Enter Account Number of the client you watn to update: ";
		string AccountNumber = clsInputValidate::ReadString();


		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account Number is not found, Choose another one\n";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_Print(Client);

		cout << "\n\t\tUpdating Client info\n";
		_ReadClientInfo(Client);			

		clsBankClient::enSaveResults SaveResult;

		SaveResult = Client.Save();

		switch (SaveResult)
		{
		case clsBankClient::svFailedEmptyObject:
			cout << "Error, Account is not saved because it is Empty\n";
			break;
		case clsBankClient::svSucceeded:
			cout << "\nClient Updated Successfully\n";
			_Print(Client);
			break;
		}

	}

};
