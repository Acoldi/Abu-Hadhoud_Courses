#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"

class clsFindCurrencyScreen : protected clsScreen
{
	static void _Print(clsCurrency Currency)
	{
		cout << "\nCurrency Info\n";
		cout << "__________________________________\n";
		cout << "Name           : " << Currency.Country << endl;  // what variable are these?
		cout << "LastName       : " << Currency.CurrencyCode << endl;
		cout << "Email          : " << Currency.Name << endl;
		cout << "Phone Number   : " << Currency.Rate << endl;
		cout << "__________________________________\n";
	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (Currency.IsEmpty())
		{
			cout << "Currency is not found\n";
		}
		else
		{
			cout << "Currency is found\n";

			_Print(Currency);
		}

	}

public:
	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\tFind Currency Screen");
		
		enum eSearchMethod {eCode=1, eCountry=2};

		cout << "Enter (1)To search by Code, (2)To search by country\n";
		short SearchChoice = clsInputValidate::ReadNumberBetween(1, 2, "You have 1 or 2 only\n");

		if (SearchChoice == eSearchMethod::eCode)
		{
			cout << "Enter Currency Code: ";
			string Code = clsInputValidate::ReadString(); 
			Code = clsInputValidate::UpperStringLetters(Code);

			clsCurrency Currency = clsCurrency::FindByCode(Code);

			_ShowResults(Currency);
		}

		if (SearchChoice == eSearchMethod::eCountry)
		{
			cout << "Enter Country Name: ";
			string Country = clsInputValidate::ReadString();

			Country = clsInputValidate::UpperFirstLetters(Country);


			clsCurrency Currency = clsCurrency::FindByCountry(Country);

			_ShowResults(Currency);
		}
	}
};

