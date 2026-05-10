#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsClientsListScreen.h"
#include "clsUtil.h"


class clsTotalBalancesScreen : protected clsScreen
{
public:
	
	static void ShowTotalBalancesScreen()
	{
		vector<clsBankClient> vClients = clsBankClient::GetClientsList();

		_DrawScreenHeader("\t\tTotal Balances Screen", "\t\t   Balances list of " + to_string(vClients.size()) + "client");

		cout << "\t\t\t\tTotal Balances\n";
		cout << "_________________________________________________________________\n";
		cout << "|" << left << setw(22) << "Account Number";
		cout << "|" << left << setw(22) << "Client Name";
		cout << "|" << left << setw(22) << "Balance" << endl;
		cout << "_________________________________________________________________\n\n";

		for (clsBankClient C : vClients)
		{
			cout << "|" << left << setw(22) << C.AccountNumber();
			cout << "|" << left << setw(22) << C.Name;
			cout << "|" << left << setw(22) << C.AccountBalance << endl;
		}
		if (vClients.size() == 0)
		{
			cout << "\t\t\t\tNo Clients!\n";
		}
		cout << "_________________________________________________________________\n";

		if (vClients.size() > 0)
		{
			double totalBalance = clsBankClient::GetTotalBalances();

			cout << "\t\t\tTotal Balances = " << totalBalance << endl;
			cout << "\t\t\t" << clsUtil::NumberToText(totalBalance) << endl;
			//cout << "\t\t\t( " << clsUtil::NumberToText(totalBalance) << " )\n";   // Why doesn't this line of code work??
		}
		else
		{
			cout << "No Clients Exist!\n";
		}
	}
};

