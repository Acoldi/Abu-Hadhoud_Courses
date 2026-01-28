#include "Util.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>

enum eMainMenueList {
	showclientlist = 1, addnewclient = 2, deleteclient = 3,
	updateclient = 4, findclient = 5, transactionmenue = 6, manageusers = 7, logout = 8
};

enum eTransactionMenueList {
	deposite = 1, withdraw = 2, totalbalances = 3,
	mainmenue = 4
};

enum eManageMenueList { listusers = 1, addnewuser, deleteuser, updateuser, finduser, Mainmenue };

using namespace std;


void ShowMainMenueScreen();
void ShowTransactionMenueScreen();
void ShowManageUsersScreen();
void GoToManageUsersScreen();
void ShowMainATMScreen(bool WelcomeUser = false);
void GoToATMmainScreen();
void ATMLogin();

eMainMenueList ReadMainMenueUserChoice()
{
	eMainMenueList Choice;
	int Num = 0;
	cout << "Choose what do you want to do [1 to 7]\n";
	cin >> Num;
	Choice = eMainMenueList(Num);

	return Choice;

}

void PrintClients(vector<stClientData> Clients)
{
	for (stClientData& Client : Clients)
	{
		cout << endl << "| " << left << setw(20) << Client.accountNumber
			<< "| " << left << setw(20) << Client.pinCode
			<< "| " << left << setw(25) << Client.name
			<< "| " << left << setw(20) << Client.phoneNumber
			<< "| " << left << setw(20) << Client.accountBalance;
		cout << endl;  PrintHorizentalLine(120);
	}
}

void PrintClientsTable()
{
	vector<stClientData> vClients = LoadClientsFromFile(ClientsFile);

	cout << "Client List (" << vClients.size() << ") Clients" << endl << endl;

	PrintHorizentalLine(120); cout << endl;
	cout << "| " << left << setw(20) << "AccountNumber"
		<< "| " << left << setw(20) << "Pin Code"
		<< "| " << left << setw(25) << "Name"
		<< "| " << left << setw(20) << "Phone Number"
		<< "| " << left << setw(20) << "Account Balance";
	cout << endl;  PrintHorizentalLine(120);

	PrintClients(vClients);
}

void ExitScreenToaMainMenue()
{
	cout << "Press any key to go back to main menue\n";
	system("pause");
	system("cls");
	ShowMainMenueScreen();
}

void PrintMainMenueScreen()
{
	PrintEqualSigns(40);
	cout << "\tMain Menue Screen\n";
	PrintEqualSigns(40);

	cout << "\t\[1] Show Client List.\n";
	cout << "\t\[2] Add New Client.\n";
	cout << "\t\[3] Delete Client.\n";
	cout << "\t\[4] Update Client Info.\n";
	cout << "\t\[5] Find Client.\n";
	cout << "\t\[6] Show Transacion Main Menue.\n";
	cout << "\t\[7] Manage users\n";
	cout << "\t\[8] Logout.\n";
	PrintEqualSigns(40); cout << '\n';
}

bool ClientExistsByAccountNumber(string AccNumber, string FileName)
{
	fstream MyFile;
	string Line;
	stClientData Client;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		while (getline(MyFile, Line))
		{
			Client = ConvertLineToRecord(Line, "#//#");
			if (Client.accountNumber == AccNumber)
			{
				MyFile.close();
				return true;
			}
		}
		MyFile.close();
		return false;
	}

}

bool UserExistsByUserNameAndPassword(string UserName, string FileName, string Password, sUser& User)
{
	fstream MyFile;
	string Line;
	sUser cUser;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		while (getline(MyFile, Line))
		{
			cUser = ConvertUserLineToRecord(Line, "#//#");
			if (cUser.UserName == UserName && cUser.Password == Password)
			{
				User = cUser;
				MyFile.close();
				return true;
			}
		}
		MyFile.close();
		return false;
	}
	if (MyFile.fail())
	{
		MyFile.open(FileName, ios::out);
		MyFile.close();
	}
	return false;
}


stClientData ReadNewClient()
{
	stClientData Data;
	cout << "       Client Data\n\n";
	cout << "Account Number: ";
	getline(cin >> ws, Data.accountNumber);

	while (ClientExistsByAccountNumber(Data.accountNumber, ClientsFile))
	{
		cout << "Client with [" << Data.accountNumber << "] Is Taken!.Please Enter Another one\n";
		getline(cin >> ws, Data.accountNumber);
	}

	cout << "Pin Code: ";
	Data.pinCode = ReadString();
	cout << "Name: ";
	Data.name = ReadString();
	cout << "Phone Number: ";
	Data.phoneNumber = ReadString();
	cout << "Account Balance: ";
	Data.accountBalance = stod(ReadString());

	return Data;
}

void ShowScreenTemplate(string Title) {
	system("cls");
	PrintEqualSigns(30);
	cout << '\t' << Title << '\n';
	PrintEqualSigns(30);
}

void ShowAccessDeniedScreen()
{
	ShowScreenTemplate("Access Denied!");
}

void ShowClientListScreen()
{
	if (!CheckAccessPermission(enMainMenuePermissions::showClientList))
	{
		ShowAccessDeniedScreen();
		ExitScreenToaMainMenue();
	}

	PrintClientsTable();
	ExitScreenToaMainMenue();
}

int ReadPermisionsToSet()
{
	int Permissions = 0;
	char Answer = 'n';

	cout << "Do you want to give access the entire system?\n";
	cin >> Answer;
	if (Answer == 'Y' || Answer == 'y')
		Permissions = enMainMenuePermissions::all;

	cout << "Do you want to give access to Show Client List Screen?\n";
	cin >> Answer;
	if (Answer == 'Y' || Answer == 'y')
		Permissions += enMainMenuePermissions::showClientList;

	cout << "Do you want to give access to Add New Client Screen?\n";
	cin >> Answer;
	if (Answer == 'Y' || Answer == 'y')
		Permissions += enMainMenuePermissions::addNewClient;

	cout << "Do you want to give access to Delete Client Screen?\n";
	cin >> Answer;
	if (Answer == 'Y' || Answer == 'y')
		Permissions += enMainMenuePermissions::deleteClientScreen;

	cout << "Do you want to give access to Update Client Screen?\n";
	cin >> Answer;
	if (Answer == 'Y' || Answer == 'y')
		Permissions += enMainMenuePermissions::updateClientScreen;

	cout << "Do you want to give access to Find Client Screen?\n";
	cin >> Answer;
	if (Answer == 'Y' || Answer == 'y')
		Permissions += enMainMenuePermissions::findClientScreen;

	cout << "Do you want to give access to Transactions Screen?\n";
	cin >> Answer;
	if (Answer == 'Y' || Answer == 'y')
		Permissions += enMainMenuePermissions::transactionsScreen;

	cout << "Do you want to give access to Manage Users Screen?\n";
	cin >> Answer;
	if (Answer == 'Y' || Answer == 'y')
		Permissions += enMainMenuePermissions::manageUsersScreen;

	return Permissions;

}

sUser ReadNewUser()
{
	sUser User;
	cout << "       User Data\n\n";
	cout << "UserName: ";
	getline(cin >> ws, User.UserName);

	while (UserExistsByUserName(User.UserName, UsersFile, User))
	{
		cout << "User with [" << User.UserName << "] Is Taken!.Please Enter Another Username\n";
		getline(cin >> ws, User.UserName);
	}


	cout << "Password: ";
	User.Password = ReadString();

	User.AL = ReadPermisionsToSet();

	return User;
}


void AddDataLineToFile(string FileName, string Line)
{
	fstream Myfile;
	Myfile.open(FileName, ios::out | ios::app);

	if (Myfile.is_open())
	{
		Myfile << Line << endl;

		Myfile.close();
	}
}

void AddNewClient(string FileName)
{
	stClientData Client;
	Client = ReadNewClient();

	AddDataLineToFile(ClientsFile, ConvertRecordToLine(Client, "#//#"));
}

void AddNewUser(string FileName)
{
	sUser User;
	User = ReadNewUser();

	AddDataLineToFile(UsersFile, ConvertUserRecordToLine(User, "#//#"));
}


void AddClients(void)
{
	char AddMore = 'y';
	do
	{
		system("cls");
		cout << "Adding new client\n\n";

		AddNewClient("ClientsFile");
		cout << "Client Added successfully!\n";

		cout << "\nDo you want to add another client? y/n \n - "; cin >> AddMore;
	} while (tolower(AddMore) == 'y');
}

void AddUsers(void)
{
	char AddMore = 'y';
	do
	{
		system("cls");
		cout << "Adding new User\n\n";

		AddNewUser(UsersFile);
		cout << "User Added successfully!\n";

		cout << "\nDo you want to add another User? y/n \n - "; cin >> AddMore;
	} while (tolower(AddMore) == 'y');
}


void ShowAddNewClietnScreen()
{
	if (!CheckAccessPermission(enMainMenuePermissions::addNewClient))
	{
		ShowAccessDeniedScreen();
		ExitScreenToaMainMenue();
	}

	PrintEqualSigns(40);
	cout << "\t Add New Client Screen\n";
	PrintEqualSigns(40);

	AddClients();

	ExitScreenToaMainMenue();
}

void MarkClientAsDeleted(vector<stClientData>& vClients, string AccNumber)
{
	for (stClientData& C : vClients)
	{
		if (C.accountNumber == AccNumber)
		{
			C.MarkedForDelete = true;
		}
	}
}

void MarkUserAsDeleted(vector<sUser>& vUser, string UserName)
{
	for (sUser& U : vUser)
	{
		if (U.UserName == UserName)
		{
			U.MarkedForDelete = true;
		}
	}
}


void DeleteClientFromFile(string AccountNumber, vector<stClientData>& vClients)
{
	stClientData Client;
	if (FindClientByAccountNumber(AccountNumber, Client, vClients))
	{
		PrintClientCard(Client);

		char Confirm = 'n';
		cout << "Are you sure you want to delete this account number? (Y/N)\nAccount Detalis: \n";

		cin >> Confirm;

		if (Confirm == tolower(Confirm));
		{
			MarkClientAsDeleted(vClients, AccountNumber);

			SaveClientsDataToFile(vClients);

			cout << "Client Deleted Successfully!\n\n";
		}
	}
	else
		cout << "Account With " << AccountNumber << " Is not found";
}

void DeleteUserFromFile(string UserName, vector<sUser>& vUsers)
{
	sUser User;
	if (UserExistsByUserName(UserName, UsersFile, User))
	{
		PrintUserCard(User);

		char Confirm = 'n';
		cout << "Are you sure you want to delete this User? (Y/N)\n";

		cin >> Confirm;

		if (Confirm == 'y' || Confirm == 'Y')
		{
			MarkUserAsDeleted(vUsers, UserName);

			SaveUsersDataToFile(vUsers);

			cout << "User Deleted Successfully!\n\n";
		}
	}
	else
		cout << "Account With " << UserName << " Is not found";
}



void ShowDeleteClientScreen()
{
	if (!CheckAccessPermission(enMainMenuePermissions::deleteClientScreen))
	{
		ShowAccessDeniedScreen();
		ExitScreenToaMainMenue();
	}

	PrintEqualSigns(40);
	cout << "\tDelete Client Screen\n";
	PrintEqualSigns(40);

	cout << "Enter Client Account Number You Want to Delete: ";
	string AccountNumber;
	getline(cin >> ws, AccountNumber);

	vector<stClientData> vClients = LoadClientsFromFile(ClientsFile);

	DeleteClientFromFile(AccountNumber, vClients);

	// Refresh vector
	vClients = LoadClientsFromFile(ClientsFile);

	ExitScreenToaMainMenue();

}

void ShowUpdateClientScreen()
{
	if (!CheckAccessPermission(enMainMenuePermissions::updateClientScreen))
	{
		ShowAccessDeniedScreen();
		ExitScreenToaMainMenue();
	}

	ShowScreenTemplate("Update Client Screen");

	cout << "Enter Client Number You Want to Update: ";
	string AccountNumber;
	getline(cin >> ws, AccountNumber);

	vector<stClientData> vClients = LoadClientsFromFile(ClientsFile);

	UpdateClientByAccountNumber(AccountNumber, vClients);

	ExitScreenToaMainMenue();
}

void ShowUpdateUserScreen()
{
	ShowScreenTemplate("Update User Info Screen");

	cout << "Enter Username: ";
	string UserName;
	getline(cin >> ws, UserName);

	vector<sUser> vUsers = LoadUsersFromFile(UsersFile);

	UpdateUserByUserName(UserName, vUsers);

	GoToManageUsersScreen();
}



void FindClientScreen()
{
	if (!CheckAccessPermission(enMainMenuePermissions::findClientScreen))
	{
		ShowAccessDeniedScreen();
		ExitScreenToaMainMenue();
	}

	PrintEqualSigns(30);
	cout << "\tFind Client Screen\n";
	PrintEqualSigns(30);

	stClientData Client;
	cout << "Enter Client Number: ";
	string AccountNumber;
	getline(cin >> ws, AccountNumber);

	vector<stClientData> vClients = LoadClientsFromFile(ClientsFile);

	if (FindClientByAccountNumber(AccountNumber, Client, vClients))
	{
		PrintClientCard(Client);
	}
	else
		cout << "Client wit " << AccountNumber << " Is Not Found\n";

	ExitScreenToaMainMenue();
}

void FindUserScreen()
{
	ShowScreenTemplate("Find User Screen");

	sUser User;
	cout << "Enter Username: ";
	string UserName;
	getline(cin >> ws, UserName);

	vector<sUser> vUsers = LoadUsersFromFile(UsersFile);

	if (UserExistsByUserName(UserName, UsersFile, User))
	{
		PrintUserCard(User);
	}
	else
		cout << "User with \"" << UserName << "\" Is Not Found\n";

	GoToManageUsersScreen();
}

void ShowEndScreen()
{
	PrintEqualSigns(30);
	cout << "\tProgram ends (:\n";
	PrintEqualSigns(30);
}

eTransactionMenueList ReadTransactionMenueChoice()
{
	short choice;
	cout << "Choose what do you want to do? [1 to 4]\n";
	cin >> choice;
	return eTransactionMenueList(choice);
}

void GoBackToTransactionMenue()
{
	cout << "Press any key to go back to transaction menue...\n";
	system("pause>0");
	ShowTransactionMenueScreen();
}

void DepositeClientBalance(stClientData Client, vector<stClientData>& vClients)
{
	double Amount = 0;
	char sure = 'y';
	cout << "Enter your deposite: ";
	cin >> Amount;
	for (stClientData& C : vClients)
	{
		if (Client.accountNumber == C.accountNumber)
		{
			cout << "Are you sure you want to deposite?\n";
			cin >> sure;

			if (sure == 'y' || sure == 'Y')
			{
				C.accountBalance += Amount;
				cout << "Deposite done successfully!\n";
			}
			break;
		}
	}
}

void ShowDepositeScreen()
{
	ShowScreenTemplate("Deposite Screen");

	cout << "Enter account Number: ";
	string AccNumber; getline(cin >> ws, AccNumber);
	stClientData Client;
	vector<stClientData> vClients = LoadClientsFromFile(ClientsFile);
	if (FindClientByAccountNumber(AccNumber, Client, vClients))
	{
		PrintClientCard(Client);

		DepositeClientBalance(Client, vClients);

		SaveClientsDataToFile(vClients);
	}
	else
	{
		cout << "Account with account number " << AccNumber << " is not found\n";
	}

	GoBackToTransactionMenue();
}

void WithdrawClientBalance(stClientData Client, vector<stClientData>& vClients)
{
	double Amount = 0;
	cout << "Amount: ";
	cin >> Amount;
	char sure = 'y';
	for (stClientData& C : vClients)
	{
		if (Client.accountNumber == C.accountNumber)
		{
			cout << "Are you sure you want to withdraw?\n";
			cin >> sure;
			if (sure == 'y' || sure == 'Y')
			{
				if (Client.accountBalance >= Amount)
				{
					C.accountBalance -= Amount;
					cout << "Withdraw done successfully!\n";
					break;
				}
				else
				{
					cout << "Your withdraw ammount exceeds you total balance! You can withdraw up to "
						<< Client.accountBalance;
					break;
				}
			}
			else
				break;
		}
	}
}

void ShowWithdrawScreen()
{
	ShowScreenTemplate("Withdraw Screen");

	cout << "Enter account Number: ";
	string AccNumber; getline(cin >> ws, AccNumber);
	stClientData Client;
	vector<stClientData> vClients = LoadClientsFromFile(ClientsFile);
	if (FindClientByAccountNumber(AccNumber, Client, vClients))
	{
		PrintClientCard(Client);

		WithdrawClientBalance(Client, vClients);

		SaveClientsDataToFile(vClients);
	}
	else
	{
		cout << "Account with account number " << AccNumber << " is not found\n";
	}

	GoBackToTransactionMenue();
}

void ValidateWithdraw(double Balance, int& Withdraw)
{
	while (Withdraw > Balance)
	{
		if (Balance == 0)
		{
			cout << "Your Balance is 0\n";
			GoToATMmainScreen();
		}

		cout << "The amount you entered exeeds the total balance\n";
		cout << "Please Enter different amount\n- ";
		cin >> Withdraw;
	}

	while (Withdraw % 5 != 0)
	{
		cout << "Please Enter Multiples of 5 : ";
		cin >> Withdraw;
	}
}

void ShowWithdrawScreenForATMsystem()
{
	ShowScreenTemplate("Withdraw Screen");
	int W = 0;
	cout << "Enter the amount of money you want to withdraw: "; cin >> W;

	ValidateWithdraw(CurrentClient.accountBalance, W);

	CurrentClient.accountBalance -= W;

	UpdateCurrentClientInfoInFile(CurrentClient);

	cout << "Balance Withdrawed successfully\nCurrent Balance: " << CurrentClient.accountBalance << endl;
}



int GetTotalBalances(vector<stClientData> vClients)
{
	int Total = 0;
	for (stClientData& Client : vClients)
	{
		Total += Client.accountBalance;
	}
	return Total;
}

void PrintTotalBalances(vector<stClientData> Clients)
{
	for (stClientData& Client : Clients)
	{
		cout << endl << "| " << left << setw(20) << Client.accountNumber
			<< "| " << left << setw(25) << Client.name
			<< "| " << left << setw(20) << Client.accountBalance;
		cout << endl;  PrintHorizentalLine(120);
	}

	int Total = GetTotalBalances(Clients);

	cout << "\n\t\t\t\t\t\t\tTotal Balances is " << Total << endl;

	GoBackToTransactionMenue();
}

void ShowTotalBalancesScreen()
{
	vector<stClientData> vClients = LoadClientsFromFile(ClientsFile);

	cout << "Client List (" << vClients.size() << ") Clients" << endl << endl;

	PrintHorizentalLine(120); cout << endl;
	cout << "| " << left << setw(20) << "AccountNumber"
		<< "| " << left << setw(25) << "Name"
		<< "| " << left << setw(20) << "Account Balance";
	cout << endl;  PrintHorizentalLine(120);

	PrintTotalBalances(vClients);

}

void ShowTransactionMenueScreen()
{
	if (!CheckAccessPermission(enMainMenuePermissions::transactionsScreen))
	{
		ShowAccessDeniedScreen();
		ExitScreenToaMainMenue();
	}

	system("cls");
	PrintEqualSigns(30);
	cout << "\t[1] Deposite\n";
	cout << "\t[2] Withdraw\n";
	cout << "\t[3] Total Balances\n";
	cout << "\t[4] Main Menue\n";
	PrintEqualSigns(30);

	switch (ReadTransactionMenueChoice())
	{
	case deposite:
		ShowDepositeScreen();
		break;
	case withdraw:
		ShowWithdrawScreen();
		break;
	case totalbalances:
		ShowTotalBalancesScreen();
		break;
	case mainmenue:
		ShowMainMenueScreen();
	default:
		break;
	}
}

string ReadPassword()
{
	cout << "Enter Passwrod: ";
	string P;
	getline(cin >> ws, P);
	return P;
}

void ShowLoginScreen()
{
	ShowScreenTemplate("Login Screen");

	string UserName = "";
	string Password = "";

	cout << "Enter Username: "; getline(cin >> ws, UserName);
	Password = ReadPassword();

	while (!UserExistsByUserNameAndPassword(UserName, UsersFile, Password, CurrentUser))
	{
		cout << "Invalid UserName/Passowrd\n";
		cout << "Enter Username: "; getline(cin >> ws, UserName);
		Password = ReadPassword();
	}

	ShowMainMenueScreen();

}

eManageMenueList ReadManageUsersMenueChoices()
{
	short choice = 0;

	cout << "Choose what do you want to do [1 to 6]\n";
	cin >> choice;
	while (choice < 1 || choice > 6)
	{
		cout << "Invalid Choice!\n";
		cin >> choice;
	}

	return (eManageMenueList)choice;
}

void PrintUsersTable()
{
	vector<sUser> vUsers = LoadUsersFromFile(UsersFile);

	cout << "Users List (" << vUsers.size() << ") Users" << endl << endl;

	PrintHorizentalLine(120); cout << endl;
	cout << "| " << left << setw(20) << "User Name"
		<< "| " << left << setw(20) << "Password"
		<< "| " << left << setw(25) << "Administration Level";

	cout << endl;  PrintHorizentalLine(120);

	for (sUser& User : vUsers)
	{
		cout << endl << "| " << left << setw(20) << User.UserName
			<< "| " << left << setw(20) << User.Password
			<< "| " << left << setw(25) << to_string(User.AL);

		cout << endl;  PrintHorizentalLine(120);
	}
}

void ShowListUsersScreen()
{
	ShowScreenTemplate("Users List Screen");

	PrintUsersTable();
}

void ShowAddNewUserScreen()
{
	ShowScreenTemplate("Add New User Screen");

	AddUsers();
}

void GoToManageUsersScreen()
{
	cout << "Press to go to manage screen screen\n";
	system("pause");
	ShowManageUsersScreen();
}

void ShowDeleteUserScreen()
{
	ShowScreenTemplate("Delete User");

	string UserName = "";
	cout << "Enter Username\n";

	getline(cin >> ws, UserName);

	while (UserName == "Admin")
	{
		cout << "You can not delete Admin!\n";
		cout << "Enter Username\n";
		getline(cin >> ws, UserName);
	}

	vector<sUser> vUsers = LoadUsersFromFile(UsersFile);

	DeleteUserFromFile(UserName, vUsers);

	// Refresh vector
	vUsers = LoadUsersFromFile(UsersFile);


}

void ShowManageUsersScreen()
{
	if (!CheckAccessPermission(enMainMenuePermissions::manageUsersScreen))
	{
		ShowAccessDeniedScreen();
		ExitScreenToaMainMenue();
	}

	ShowScreenTemplate("Manage Users Screen");

	cout << "\t\[1] List users \n";
	cout << "\t\[2] Add new user.\n";
	cout << "\t\[3] Delete User.\n";
	cout << "\t\[4] Update User\n";
	cout << "\t\[5] FindUser.\n";
	cout << "\t\[6] Main Menue.\n";
	PrintEqualSigns(40); cout << '\n';

	switch (ReadManageUsersMenueChoices())
	{
	case listusers:
		ShowListUsersScreen();
		GoToManageUsersScreen();
		break;
	case addnewuser:
		ShowAddNewUserScreen();
		GoToManageUsersScreen();
		break;
	case deleteuser:
		ShowDeleteUserScreen();
		GoToManageUsersScreen();
		break;
	case updateuser:
		ShowUpdateUserScreen();
		GoToManageUsersScreen();
		break;
	case finduser:
		FindUserScreen();
		GoToManageUsersScreen();
		break;
	case Mainmenue:
		ShowMainMenueScreen();
		break;
	}
}

void ShowMainMenueScreen()
{
	system("cls");
	PrintMainMenueScreen();

	switch (ReadMainMenueUserChoice())
	{
	case showclientlist:
		ShowClientListScreen();
		break;
	case addnewclient:
		ShowAddNewClietnScreen();
		break;
	case deleteclient:
		ShowDeleteClientScreen();
		break;
	case updateclient:
		ShowUpdateClientScreen();
		break;
	case findclient:
		FindClientScreen();
		break;
	case transactionmenue:
		ShowTransactionMenueScreen();
		break;
	case manageusers:
		ShowManageUsersScreen();
		break;
	case logout:
		ShowLoginScreen();
		break;
	}
}




enum enAtmOptions { QuickWithdraw = 1, NormalWithdraw, Deposite, CheckBalance, Logout };

enAtmOptions ReadATMmenueChoice()
{
	short Choice = 0;
	cout << "Choose what you want to do [1 to 5]\n";
	cin >> Choice;
	return (enAtmOptions)Choice;
}

void PrintQickWithDrawOptions()
{
	cout << "[1] 20\t [2] 50\n";
	cout << "[3] 100\t [4] 200\n";
	cout << "[5] 400\t [6] 600\n";
	cout << "[7] 800\t [8] 1000\n";
	cout << "[9] Exit\n";
}

enum enQuickWithdraw { twenty = 1, fifty = 2, hundred, hundred2, hundred4, hundred6, hundred8, thousand, exitquickwithdraw };

enQuickWithdraw ReadQuickWithdrawChoice()
{
	short Choice = 0;
	cout << "Press the number corresponds with the amount of money you want to Withdraw\n";
	cin >> Choice;
	return (enQuickWithdraw)Choice;
}

void WithdrawClientBalanceByN(stClientData& Client, int N)
{
	ValidateWithdraw(Client.accountBalance, N);

	Client.accountBalance -= N;
	cout << "Withdraw Done successfully, The current Balance is: " <<
		Client.accountBalance << endl;

	UpdateCurrentClientInfoInFile(Client);
}

void GoToATMmainScreen()
{
	cout << "Press any key to go to ATM main menue\n";
	system("pause>0");
	ShowMainATMScreen();
}

void PerFormQuickWithdrawOptions(enQuickWithdraw Choice)
{
	switch (Choice)
	{
	case twenty:
		WithdrawClientBalanceByN(CurrentClient, 20);
		GoToATMmainScreen();
		break;
	case fifty:
		WithdrawClientBalanceByN(CurrentClient, 50);
		GoToATMmainScreen();
		break;
	case hundred:
		WithdrawClientBalanceByN(CurrentClient, 100);
		GoToATMmainScreen();
		break;
	case hundred2:
		WithdrawClientBalanceByN(CurrentClient, 200);
		GoToATMmainScreen();
		break;
	case hundred4:
		WithdrawClientBalanceByN(CurrentClient, 400);
		GoToATMmainScreen();
		break;
	case hundred6:
		WithdrawClientBalanceByN(CurrentClient, 600);
		GoToATMmainScreen();
		break;
	case hundred8:
		WithdrawClientBalanceByN(CurrentClient, 800);
		GoToATMmainScreen();
		break;
	case thousand:
		WithdrawClientBalanceByN(CurrentClient, 1000);
		GoToATMmainScreen();
		break;
	case exitquickwithdraw:
		ShowMainATMScreen();
		break;
	}
}

void ShowQuickWithdrawScreen()
{
	ShowScreenTemplate("Quick Withdraw");

	PrintQickWithDrawOptions();
	PerFormQuickWithdrawOptions(ReadQuickWithdrawChoice());
}

void ShowDepositeScreenForATMsystem()
{
	ShowScreenTemplate("Deposite Screen");

	int D = 0;
	cout << "Enter the amount of money you want to Deoisute: "; cin >> D;

	while (D % 5 != 0)
	{
		cout << "Please Enter Multiples of 5 : ";
		cin >> D;
	}

	while (D == 0)
	{
		cout << "You can't add 0 balance\n";
		cin >> D;
	}

	CurrentClient.accountBalance += D;

	UpdateCurrentClientInfoInFile(CurrentClient);

	cout << "Deposite Done successfully\nCurrent Balance: " << CurrentClient.accountBalance << endl;
}

void ShowBalanceATM()
{
	ShowScreenTemplate("Show Balance");

	cout << "Your Current Balance is: " << CurrentClient.accountBalance << endl << endl;
}

void PerformATMOptions(enAtmOptions Choice)
{
	switch (Choice)
	{
	case QuickWithdraw:
		ShowQuickWithdrawScreen();
		GoToATMmainScreen();
		break;
	case NormalWithdraw:
		ShowWithdrawScreenForATMsystem();
		GoToATMmainScreen();
		break;
	case Deposite:
		ShowDepositeScreenForATMsystem();
		GoToATMmainScreen();
		break;
	case CheckBalance:
		ShowBalanceATM();
		GoToATMmainScreen();
		break;
	case Logout:
		ATMLogin();
		break;
	}
}

void ShowMainATMScreen(bool WelcomeUser)
{
	ShowScreenTemplate("ATM System");

	if (WelcomeUser)
		cout << "          Welcome " << CurrentClient.name << endl;

	cout << "\t\[1] Quick Withdraw.\n";
	cout << "\t\[2] Normal Withdraw.\n";
	cout << "\t\[3] Deposite.\n";
	cout << "\t\[4] Check Balance.\n";
	cout << "\t\[5] Logout.\n";
	PrintEqualSigns(40); cout << '\n';

	PerformATMOptions(ReadATMmenueChoice());
}

void ATMLogin()
{
	ShowScreenTemplate("ATM Login");

	vector<stClientData> vClients = LoadClientsFromFile(ClientsFile);

	bool LoginFail = false;
	string AccNumber = "";
	string PinCode = "";
	do
	{
		if (LoginFail)
		{
			cout << "Invalid Account Number / Pin code\n";
		}
		LoginFail = true;

		cout << "Account Number: "; cin >> AccNumber;
		cout << "Pin Code: "; cin >> PinCode;
		LoginFail = !FindClientByAccountNumberAndPinCodeAndLoadClient(AccNumber, PinCode, vClients, CurrentClient);
	} while (LoginFail);

	ShowMainATMScreen(true);
}




int main(void)
{
	ShowLoginScreen();

	ATMLogin();

	system("Pause>0");
}