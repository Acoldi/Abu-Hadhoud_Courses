#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsMainScreen.h"
#include "clsDepositeScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "cslTransferLogsScreen.h"


class clsTransactionScreen : protected clsScreen
{
	static void _PrintCurrentScreenHeader(string Title)
	{
		cout << setw(37) << "" << left << "===============================" << endl;
		cout << setw(37) << "" << left << "\t" << Title << endl;
		cout << setw(37) << "" << left << "===============================" << endl;
	}

	enum enTransactionMenueOption {eDeposite=1, eWithdraw, eTotalBalances, eTransfer, eShowTransferLogsScreen, eShowMainMenue};

	static enTransactionMenueOption _ReadMainMenueOption()
	{
		return (enTransactionMenueOption)clsInputValidate::ReadNumberBetween(1, 3, "Enter number between 1 and 8\n- ");
	}

	static void _GoBackToTransationMenueScreen()
	{
		cout << "\t\tPress any key to go back to transaction menue";
		system("pause>0");
		ShowTransactionMenue();
	}

	static void _ShowDepositeScreen()
	{
		//cout << "Here will implement deposite screen\n";
		clsDepositeScreen::ShowDepositeScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		//cout << "Here will implement total balances screen\n";
		clsTotalBalancesScreen::ShowTotalBalancesScreen();
	}

	static void _ShowWithdrawScreen()
	{
		//cout << "Here will implement Withdraw screen\n";
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogsScreen()
	{
		cslTransferLogsScreen::ShowTransferLogsScreen();
	}

	static void _PerformTransactionMenueScreen(enTransactionMenueOption Choice)
	{
		switch (Choice)
		{
		case clsTransactionScreen::eDeposite:
			system("cls");
			_ShowDepositeScreen();
			_GoBackToTransationMenueScreen();
			break;
		case clsTransactionScreen::eWithdraw:
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransationMenueScreen();
			break;
		case clsTransactionScreen::eTotalBalances:
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransationMenueScreen();
			break;
		case clsTransactionScreen::eTransfer:
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransationMenueScreen();
			break;
		case clsTransactionScreen::eShowTransferLogsScreen:
			system("cls");
			_ShowTransferLogsScreen();
			_GoBackToTransationMenueScreen();
			break;
		case clsTransactionScreen::eShowMainMenue:
			// Do nothing here, because when the perform option function ends then the main menue is back.
			break;
		
		}
	}

public:


	static void ShowTransactionMenue()
	{
		if (!_ChecAccessPermission(clsUser::enPermissions::pTransactions))
		{
			return;
		}

		system("cls");

		_DrawScreenHeader("\t\tMain Screen");

		_PrintCurrentScreenHeader("\tTransaction Menue");

		cout << setw(37) << "" << left << "[1] Deposite" << endl;
		cout << setw(37) << "" << left << "[2] WithDraw" << endl;
		cout << setw(37) << "" << left << "[3] Total Balances" << endl;
		cout << setw(37) << "" << left << "[4] Transfer" << endl;
		cout << setw(37) << "" << left << "[5] Transfer Log Menue" << endl;
		cout << setw(37) << "" << left << "[6] Main Menue" << endl;
		cout << setw(37) << "" << left << "===============================" << endl;

		cout << "Choose what you want to do (1 to 6): ";
		short Choice = clsInputValidate::ReadNumberBetween(1,6, "Enter number between 1 and 6");

		_PerformTransactionMenueScreen((enTransactionMenueOption)Choice);
	}
};

