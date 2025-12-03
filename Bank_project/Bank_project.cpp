#include "Basics.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>

enum eMainMenueList {
	showclientlist = 1, addnewclient = 2, deleteclient = 3,
	updateclient = 4, findclient = 5, transactionmenue = 6, Exit = 7
};

enum eTransactionMenueList {
	deposite = 1, withdraw = 2, totalbalances = 3,
	mainmenue = 4
};

using namespace std;

void ShowMainMenueScreen();
void ShowTransactionMenueScreen();

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
	vector<stClientData> vClients = LoadClientsFromFile(FileName);

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
	system("pause>0");
	system("cls");
	ShowMainMenueScreen();
}

void ShowClientListScreen()
{
	PrintClientsTable();
	ExitScreenToaMainMenue();
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
	cout << "\t\[7] Exit.\n";
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

stClientData ReadNewClient()
{
	stClientData Data;
	cout << "       Client Data\n\n";
	cout << "Account Number: ";
	getline(cin >> ws, Data.accountNumber);

	while (ClientExistsByAccountNumber(Data.accountNumber, FileName))
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

	AddDataLineToFile("Clients.txt", ConvertRecordToLine(Client, "#//#"));
}

void AddClients(void)
{
	char AddMore = 'y';
	do
	{
		system("cls");
		cout << "Adding new client\n\n";

		AddNewClient("Clients.txt");
		cout << "Client Added successfully!\n";

		cout << "\nDo you want to add another client? y/n \n - "; cin >> AddMore;
	} while (tolower(AddMore) == 'y');
}

void ShowAddNewClietnScreen()
{
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

void ShowDeleteClientScreen()
{
	PrintEqualSigns(40);
	cout << "\tDelete Client Screen\n";
	PrintEqualSigns(40);

	cout << "Enter Client Number You Want to Delete: ";
	string AccountNumber;
	getline(cin >> ws, AccountNumber);

	vector<stClientData> vClients = LoadClientsFromFile(FileName);

	DeleteClientFromFile(AccountNumber, vClients);

	// Refresh vector
	vClients = LoadClientsFromFile(FileName);

	ExitScreenToaMainMenue();

}

void ShowUpdateClientScreen()
{
	PrintEqualSigns(40);
	cout << "\tUpdate Client Screen\n";
	PrintEqualSigns(40);

	cout << "Enter Client Number You Want to Update: ";
	string AccountNumber;
	getline(cin >> ws, AccountNumber);

	vector<stClientData> vClients = LoadClientsFromFile(FileName);

	UpdateClientByAccountNumber(AccountNumber, vClients);

	ExitScreenToaMainMenue();
}

void FindClientScreen()
{
	PrintEqualSigns(30);
	cout << "\tFind Client Screen\n";
	PrintEqualSigns(30);

	stClientData Client;
	cout << "Enter Client Number: ";
	string AccountNumber;
	getline(cin >> ws, AccountNumber);

	vector<stClientData> vClients = LoadClientsFromFile(FileName);

	if (FindClientByAccountNumber(AccountNumber, Client, vClients))
	{
		PrintClientCard(Client);
	}
	else
		cout << "Client wit " << AccountNumber << " Is Not Found\n";

	ExitScreenToaMainMenue();
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

void ShowScreenTemplate(string Title) {
	system("cls");
	PrintEqualSigns(30);
	cout << '\t' << Title << '\n';
	PrintEqualSigns(30);
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
	vector<stClientData> vClients = LoadClientsFromFile(FileName);
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
	vector<stClientData> vClients = LoadClientsFromFile(FileName);
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
	vector<stClientData> vClients = LoadClientsFromFile(FileName);

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

void ShowMainMenueScreen()
{
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
	case Exit:
		ShowEndScreen();
		break;
	default:
		break;
	}
}

void BuildConfigurations()
{
	ifstream FILE;
	FILE.open(FileName, ios::out);

	if (FILE.is_open())
		return;
	else
	{
		std::ofstream newFile(FileName);
		newFile << "";
		ofstream(FileName);
	}
}

int main(void)
{
	BuildConfigurations();

	ShowMainMenueScreen();

	system("Pause>0");
}