#pragma once
#include "clsBankClient.h"
#include "clsScreen.h";
#include "Global.h";

class clsClientsListScreen : protected clsScreen
{

public:
	static void ShowClientsList()
	{
		if (!_ChecAccessPermission(clsUser::enPermissions::pShowClientList))
		{
			return;
		}

		vector <clsBankClient> vClients = clsBankClient::GetClientsList();
		string Title = "\t Clients List";
		string SubTitle = "\t   ( " + to_string(vClients.size()) + " ) Clients";
		
		_DrawScreenHeader(Title, SubTitle);
		
		cout << endl;
		
		cout << setw(8) << "" << "___________________________________________________________________________________________________________\n";
		cout << setw(8) << "" << "|" << left << setw(15) << "Name";
		cout << "|" << left << setw(15) << "LastName";
		cout << "|" << left << setw(15) << "Email";
		cout << "|" << left << setw(15) << "Phone Number";
		cout << "|" << left << setw(15) << "Account Number";
		cout << "|" << left << setw(15) << "Pin Code";
		cout << "|" << left << setw(15) << "Balance" << endl;
		cout << setw(8) << "" << "___________________________________________________________________________________________________________\n\n";


		for (clsBankClient &C : vClients)
		{
			cout << setw(8) << "" << "|" << left << setw(15) << C.Name;
			cout << "|" << left << setw(15) << C.LastName;
			cout << "|" << left << setw(15) << C.Email;
			cout << "|" << left << setw(15) << C.PhoneNumber;
			cout << "|" << left << setw(15) << C.AccountNumber();
			cout << "|" << left << setw(15) << C.PinCode;
			cout << "|" << left << setw(15) << C.AccountBalance << endl;
		}
		if (vClients.size() == 0)
		{
			cout << "\t\t\t\tNo Clients!\n";
		}
		cout << setw(8) << "" << "___________________________________________________________________________________________________________\n\n";

		/*cout << "Enter any key to exit";
		int d;
		cin >> d;*/
	}

};

