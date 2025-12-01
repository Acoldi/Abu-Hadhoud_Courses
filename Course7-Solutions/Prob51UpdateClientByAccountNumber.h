#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cctype> // For tolower

using namespace std;

const string FileNamep51 = "Clients.txt";

// Generic ReadString function for convenience (copied from Prob45)
string ReadStringp51() {
    string S1;
    getline(cin >> ws, S1); // ws to consume leading whitespace
    return S1;
}

// Generic Split function for convenience (copied from Prob45)
vector<string> Splitp51(string S, string Delimiter) {
    vector<string> vString;
    size_t pos = 0;
    string token;
    while ((pos = S.find(Delimiter)) != string::npos) {
        token = S.substr(0, pos);
        if (token != "") {
            vString.push_back(token);
        }
        S.erase(0, pos + Delimiter.length());
    }
    if (S != "") {
        vString.push_back(S);
    }
    return vString;
}

struct stClientDatap51
{
	string accountNumber;
	string pinCode;
	string name;
	string phoneNumber;
	string accountBalance;
	bool MarkedForDelete = false; // Added for this solution
};

stClientDatap51 ConvertClientRecordToDatap51(string DataRecord, string Deli)
{
	vector<string> vClient;

stClientDatap51 sClientData;

	vClient = Splitp51(DataRecord, Deli);

	sClientData.accountNumber = vClient[0];
	sClientData.pinCode = vClient[1];
	sClientData.name = vClient[2];
	sClientData.phoneNumber = vClient[3];
	sClientData.accountBalance = vClient[4];

	return sClientData;
}

void PrintClientCardp51(stClientDatap51 Data)
{
	cout << "\nAccount Number: " << Data.accountNumber << endl;
	cout << "Pin Code: " << Data.pinCode << endl;
	cout << "Name: " << Data.name << endl;
	cout << "Phone Number: " << Data.phoneNumber << endl;
	cout << "Account Balance: " << Data.accountBalance << endl;
}

vector<stClientDatap51> LoadClientsFromFilep51(string FileName)
{
	vector<stClientDatap51> vClientsRecord;
	string ClientLine;

stClientDatap51 Client;

	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		while (getline(MyFile, ClientLine))
		{
			Client = ConvertClientRecordToDatap51(ClientLine, "#//#");
			vClientsRecord.push_back(Client);
		}

		MyFile.close();
	}

	return vClientsRecord;
}

bool FindClientByAccountNumberp51(vector<stClientDatap51> vClients, string AccNumber, stClientDatap51& Client)
{
	for (stClientDatap51 C : vClients)
	{
		if (C.accountNumber == AccNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

string ConvertRecordToLinep51(stClientDatap51 Data, string Deli)
{
	string veClientData;
	veClientData += Data.accountNumber + Deli;
	veClientData += Data.pinCode + Deli;
	veClientData += Data.name + Deli;
	veClientData += Data.phoneNumber + Deli;
	veClientData += Data.accountBalance;

	return veClientData;
}

void SaveClientsDataToFilep51(vector<stClientDatap51>& vClients)
{
	fstream MyFile;
	MyFile.open(FileNamep51, ios::out);

	if (MyFile.is_open())
	{
		for (stClientDatap51 &C : vClients)
		{
			if (C.MarkedForDelete == false) // This might not be needed for update, but kept as per original structure
			{
				MyFile << ConvertRecordToLinep51(C, "#//#") << '\n';
			}
		}

		MyFile.close();
	}
}

stClientDatap51 ChangeClientDatap51(string accNumber)
{

stClientDatap51 Data;
	Data.accountNumber = accNumber;
	cout << "Pin Code: ";
	getline(cin >> ws, Data.pinCode);
	cout << "Name: ";
	Data.name = ReadStringp51();
	cout << "Phone Number: ";
	Data.phoneNumber = ReadStringp51();
	cout << "Account Balance: ";
	Data.accountBalance = ReadStringp51();
	
	return Data;
}

void UpdateClientByAccountNumberp51(string AccountNumber, vector<stClientDatap51>& vClients)
{

stClientDatap51 Client;
	if (FindClientByAccountNumberp51(vClients, AccountNumber, Client))
	{
		PrintClientCardp51(Client);

		char Confirm = 'n';
		cout << "\nAre you sure you want to update this account? (Y/N)\n";

		cin >> Confirm;

		if (tolower(Confirm) == 'y') // Corrected if condition
		{
			for (stClientDatap51 &C : vClients)
			{
				if (C.accountNumber == AccountNumber)
				{
					C = ChangeClientDatap51(AccountNumber);
					break;
				}
			}

			SaveClientsDataToFilep51(vClients); // Save all clients back to file

			cout << "\nClient Updated Successfully!\n";
		}
		else
		{
			cout << "\nClient Update Cancelled.\n";
		}
	}
	else
		cout << "\nAccount With " << AccountNumber << " Is not found.\n";
}

void Prob51_UpdateClientByAccountNumber()
{
	cout << "Enter Client Number You Want to Update: ";
	string AccountNumber = ReadStringp51();

	vector<stClientDatap51> vClients = LoadClientsFromFilep51(FileNamep51);

	UpdateClientByAccountNumberp51(AccountNumber, vClients);

	system("Pause>0");
}
