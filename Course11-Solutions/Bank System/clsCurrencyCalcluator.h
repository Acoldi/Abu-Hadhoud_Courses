#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"

class clsCurrencyCalcluator : protected clsScreen
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

	static clsCurrency _GetCurrency(string Message = "Enter currency code")
	{
		cout << Message;
		string CurrencyCode = clsString::UpperStringLetters(clsInputValidate::ReadString());

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "Currency doesn't exitst, try again: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		return clsCurrency::FindByCode(CurrencyCode);
	}

	static void _ShowResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{
		float Result;

		if (Currency2.CurrencyCode == "USD")
		{
			Result = Currency1.ConverToUSD(Amount);

			cout << Amount << " " 
				<< Currency1.CurrencyCode << " = " 
				<< Result
				<< " " << Currency2.CurrencyCode << endl;
			return;
		}
		
		Result = Currency1.ConverToOtherCurrency(Amount, Currency2);

		cout << Amount << " "
			<< Currency1.CurrencyCode << " = "
			<< Result
			<< " " << Currency2.CurrencyCode << endl;
	}

public:
	static void ShowCurrencyCalculatorScreen()
	{
		_DrawScreenHeader("\tCurrency Calculator Screen");

		// Had Sol

		clsCurrency Currency1 = _GetCurrency("Currency 1: ");
		_Print(Currency1);
		clsCurrency Currency2 = _GetCurrency("\nCurrency 2: ");
		_Print(Currency2);
		
		cout << "\nEnter exchange amount: ";
		float Amount = clsInputValidate::ReadNumber<float>();

		_ShowResults(Amount, Currency1, Currency2);

		// My Sol

	    /*cout << "Enter Currency1 Code: ";
		string Code = clsInputValidate::ReadString();
		Code = clsInputValidate::UpperStringLetters(Code);
		
		while (!clsCurrency::IsCurrencyExist(Code))
		{
			cout << "Currency doesn't exits, Try again: ";
			Code = clsInputValidate::UpperStringLetters(Code);
		}

		clsCurrency Currency1 = clsCurrency::FindByCode(Code);
		_Print(Currency1);

		cout << "Enter Currency2 Code: ";
		Code = clsInputValidate::ReadString();
		Code = clsInputValidate::UpperStringLetters(Code);

		while (!clsCurrency::IsCurrencyExist(Code))
		{
			cout << "Currency doesn't exits, Try again: ";
			Code = clsInputValidate::ReadString();
			Code = clsInputValidate::UpperStringLetters(Code);
		}

		clsCurrency Currency2 = clsCurrency::FindByCode(Code);
		_Print(Currency2);


		cout << "\nEnter Amount To exchange: ";
		float Amount = clsInputValidate::ReadNumber<float>();

		if (Currency2.CurrencyCode == "USD")
		{
			cout << Amount << " " << Currency1.CurrencyCode << " = " << Amount / Currency1.Rate << " " << Currency2.CurrencyCode << endl;
		}
		else
		{
			float Currency1InDollars = Amount / Currency1.Rate; // From any currency to dollar we devide by the (rate)
			// From dollar to any other currency, we multiply by the (rate)
			cout << Amount << " " << Currency1.CurrencyCode << " = " << Currency1InDollars * Currency2.Rate << " " << Currency2.CurrencyCode << endl;
		}

		char answer = 'n';
		cout << "Do you want to perform another calculation? (y/n)\n- ";
		cin >> answer;
		while (tolower(answer) == 'y')
		{
			system("cls");
			ShowCurrencyCalculatorScreen();
		}*/
	}
};

