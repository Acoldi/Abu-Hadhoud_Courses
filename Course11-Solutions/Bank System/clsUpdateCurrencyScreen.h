#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"

class clsUpdateCurrencyScreen : protected clsScreen
{
	static void _Print(clsCurrency Currency)
	{
		cout << "\nCurrency Info\n";
		cout << "__________________________________\n";
		cout << "Country      : " << Currency.Country << endl;
		cout << "Currency code: " << Currency.CurrencyCode << endl;
		cout << "Currency Name: " << Currency.Name << endl;
		cout << "Rate         : " << Currency.Rate << endl;
		cout << "__________________________________\n";
	}

public:
	static void ShowUpdateCurrencyScreen()
	{
		_DrawScreenHeader("\tUpdate Currency Screen\n");

		cout << "Enter Currency Code: ";
		string Code = clsInputValidate::ReadString();
		Code = clsInputValidate::UpperStringLetters(Code);

		clsCurrency Currency = clsCurrency::FindByCode(Code);

		_Print(Currency);

		char ans = 'n';
		cout << "Are you sure you want to update this currency rate?\n";
		cin >> ans;
		
		if (tolower(ans) == 'y')
		{
			cout << "\nEnter new rate: ";
			float NewRate = clsInputValidate::ReadNumber<float>();
			Currency.UpdateRate(NewRate);

			cout << "Currency Updated successfully (:\n";

			_Print(Currency);
		}
		else
		{
			cout << "Operation is canceled\n";
		}
	}
};

