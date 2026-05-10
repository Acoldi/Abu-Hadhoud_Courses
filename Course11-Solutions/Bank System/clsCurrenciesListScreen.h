#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"


class clsCurrenciesListScreen : protected clsScreen
{

public:
	static void ShowCurrenciesList()
	{
		system("cls");

		vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
		string Title = "\t Currencies List";
		string SubTitle = "\t   ( " + to_string(vCurrencies.size()) + " ) Currencies";

		_DrawScreenHeader(Title, SubTitle);

		cout << endl;

		cout << setw(8) << "" << "___________________________________________________________________________________________________________\n";
		cout << setw(8) << "" << "|" << left << setw(30) << "Country";
		cout << "|" << left << setw(12) << "Code";
		cout << "|" << left << setw(35) << "Name";
		cout << "|" << left << setw(12) << "Rate/(1$)" << endl;
		cout << setw(8) << "" << "___________________________________________________________________________________________________________\n\n";


		for (clsCurrency C : vCurrencies)
		{
			cout << setw(8) << "" << "|" << left << setw(30) << C.Country;
			cout << "|" << left << setw(12) << C.CurrencyCode;
			cout << "|" << left << setw(35) << C.Name;
			cout << "|" << left << setw(12) << C.Rate << endl;
		}
		if (vCurrencies.size() == 0)
		{
			cout << "\t\t\t\t\t\t\tNo Currencies!\n";
		}
		cout << setw(8) << "" << "___________________________________________________________________________________________________________\n\n";
	}
};

