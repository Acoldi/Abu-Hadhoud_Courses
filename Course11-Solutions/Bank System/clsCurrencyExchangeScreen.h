#pragma once
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include "clsCurrencyCalcluator.h"

class clsCurrencyExchangeScreen : protected clsScreen
{
	static void _PrintCurrentScreenHeader(string Title)
	{
		cout << setw(37) << "" << left << "===============================" << endl;
		cout << setw(37) << "" << left << "\t" << Title << endl;
		cout << setw(37) << "" << left << "===============================" << endl;
	}

	enum enCurrencyEchangeOption {
		eListCurrencies = 1, eFindCurrency, eUpdateRate, eCurrencyCalculator, eMainMenue
	};

	static enCurrencyEchangeOption _ReadCurrencyExchangeMenueOptions()
	{
		cout << "Choose what do you want to do (1 to 6): ";
		short Choice = clsInputValidate::ReadNumberBetween(1, 6, "You have from 1 and 6 choices");
		
		return (enCurrencyEchangeOption)Choice;
	}

	static void _GoToCurrencyExchangeMenue()
	{
		cout << "\n\n\t\tPress any key to go back to Currency Exchange Menue\n";
		system("pause>0");
		ShowCurrencyExchangeScreen();
	}

	static void _ShowListCurrenciesScreen()
	{
		//cout << "List Currencies will be here\n";
		clsCurrenciesListScreen::ShowCurrenciesList();

	}

	static void _ShowFindCurrencyScreen()
	{
		/*cout << "Find Currency will be here\n";*/

		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateCurrencyScreen()
	{
		//cout << "Update Currency will be here\n";

		clsUpdateCurrencyScreen::ShowUpdateCurrencyScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "Currency Calculator will be here\n";

		clsCurrencyCalcluator::ShowCurrencyCalculatorScreen();
	}


	static void _PerformCurrencyExchangeMenueOption(enCurrencyEchangeOption Choice)
	{
		switch (Choice)
		{
		case clsCurrencyExchangeScreen::eListCurrencies:
			system("cls");
			_ShowListCurrenciesScreen();
			_GoToCurrencyExchangeMenue();
			break;
		case clsCurrencyExchangeScreen::eFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoToCurrencyExchangeMenue();
			break;
		case clsCurrencyExchangeScreen::eUpdateRate:
			system("cls");
			_ShowUpdateCurrencyScreen();
			_GoToCurrencyExchangeMenue();
			break;
		case clsCurrencyExchangeScreen::eCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoToCurrencyExchangeMenue();
			break;
		case clsCurrencyExchangeScreen::eMainMenue:
			// Do nothing...
			break;
		}
	}

public:
	static void ShowCurrencyExchangeScreen()
	{
		system("cls");

		_DrawScreenHeader("\t\tMain Screen");

		_PrintCurrentScreenHeader("\tCurrency Exchange Menue");

		cout << setw(37) << "" << left << "[1] List Currencies" << endl;
		cout << setw(37) << "" << left << "[2] Find Currency" << endl;
		cout << setw(37) << "" << left << "[3] Update Rate" << endl;
		cout << setw(37) << "" << left << "[4] Currency Calculator" << endl;
		cout << setw(37) << "" << left << "[5] Main Menue" << endl;
		cout << setw(37) << "" << left << "===============================" << endl;

		_PerformCurrencyExchangeMenueOption(_ReadCurrencyExchangeMenueOptions());

	}
};

