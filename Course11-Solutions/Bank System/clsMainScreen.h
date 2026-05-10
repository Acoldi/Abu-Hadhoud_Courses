#pragma once
#include "clsUtil.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsClientsListScreen.h"
#include "clsAddNewClientsScrean.h"
#include "clsDeleteClientsScreen.h"
#include "clsUpdateClientScrean.h"
#include "clsFindClientScreen.h"
#include "clsTransactionMenueScreen.h"
#include "clsManageUSersScreen.h"
#include "clsFindUserScreen.h"
#include "Global.h"
#include "clsLoginRegisterSreen.h"
#include "clsCurrencyExchangeScreen.h"
//#include "clsLoginScreen.h"



class clsMainScreen : protected clsScreen
{
private:
	
	enum enMainMenueOption {eShowClientList=1, eAddNewClient, eDeleteClient, eUpdateClientInfo, eFindClient, eTransactions, 
		eManageUsers , eLoginRegister, eCurrencyExhange
	, eExit};

	static enMainMenueOption _ReadMainMenueOption()
	{
		return (enMainMenueOption)clsInputValidate::ReadNumberBetween(1, 10, "Enter number between 1 and 9\n- ");
	}

	static void _GoBackToMainMenue()
	{
		cout << "Press Any Key To Go Back To Main Menue\n";
		system("pause>0");
		ShowMainMenue();
	}

	

	static void _ShowAllClientListScreen()
	{
		clsClientsListScreen::ShowClientsList();
	}

	static void _ShowAddNewClientsScreen()
	{
		clsAddNewClientsScrean::ShowAddNewClientsScreen();
	}

	static void _ShowDeleteClientScreen()
	{
		clsDeleteClientsScrean::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen()
	{
		clsUpdateClientScrean::ShowUpdateClientScreen();
	}

	static void _FindClientScreen()
	{
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionMenue()
	{
		clsTransactionScreen::ShowTransactionMenue();
	}

	static void _ShowManageUsersMenueScreen()
	{
		//cout << "Manage Users Menue Screen Will Be Here\n";
		clsManageUSersScreen::ShowManageUsersMenue();
	}

	static void _ShowLoginRegisterScreen()
	{
		clsLoginRegisterScreen::ShowLoginRegisterscreen();
	}

	static void _ShowCurrencyExchangeMenueScreen()
	{
		clsCurrencyExchangeScreen::ShowCurrencyExchangeScreen();
	}

	/*static void _ShowLoginScreen()
	{
		cout << "Login Screen Will Be Here\n";
	}*/

	static void _LogOut()
	{
		CurrentUser = clsUser::Find("", "");
	}

	static void _PerformMainMenueOption(enMainMenueOption Choice)
	{
		switch (Choice)
		{
		case clsMainScreen::eShowClientList:
			system("cls");
			_ShowAllClientListScreen();
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eAddNewClient:
			system("cls");
			_ShowAddNewClientsScreen();
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eDeleteClient:
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eUpdateClientInfo:
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eFindClient:
			system("cls");
			_FindClientScreen();
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eTransactions:
			system("cls");
			_ShowTransactionMenue();
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eManageUsers:
			system("cls");
			_ShowManageUsersMenueScreen();
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eLoginRegister:
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eCurrencyExhange:
			system("cls");
			_ShowCurrencyExchangeMenueScreen();
			_GoBackToMainMenue();
			break;
		case clsMainScreen::eExit:
			system("cls");
			_LogOut(); // The login function will return after this line is exectued!
			/*clsLoginScreen::ShowLoginScreen();*/  // Circular reference confuses the compiler, therfore it is denied.
			break;
		}
	}

	static void _PrintCurrentScreenHeader(string Title)
	{
		cout << setw(37) << "" << left << "===============================" << endl;
		cout << setw(37) << "" << left << "\t" << Title << endl;
		cout << setw(37) << "" << left << "===============================" << endl;
	}

public:
	static void ShowMainMenue()
	{
		system("cls");
		
		_DrawScreenHeader("\t\tMain Screen");

		_PrintCurrentScreenHeader("\tMain Menue");

		cout << setw(37) << "" << left << "[1] Show Client List" << endl;
		cout << setw(37) << "" << left << "[2] Add New Client" << endl;
		cout << setw(37) << "" << left << "[3] Delete Client" << endl;
		cout << setw(37) << "" << left << "[4] Update Client Info" << endl;
		cout << setw(37) << "" << left << "[5] Find Client" << endl;
		cout << setw(37) << "" << left << "[6] Transactions" << endl;
		cout << setw(37) << "" << left << "[7] Manage Users" << endl;
		cout << setw(37) << "" << left << "[8] Log Registers List" << endl;
		cout << setw(37) << "" << left << "[9] Currency Exchange" << endl;
		cout << setw(37) << "" << left << "[10] Logout" << endl;
		cout << setw(37) << "" << left << "===============================" << endl;

		cout << setw(37) << "" << left << "Choose what do you want to do [1 to 10]\n" << endl;

		_PerformMainMenueOption(_ReadMainMenueOption());
		
	}

};

