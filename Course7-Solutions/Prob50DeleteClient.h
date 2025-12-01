#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cctype> // For tolower

using namespace std;

const string FileNamep50 = "Clients.txt";

// Generic ReadString function for convenience (copied from Prob45)
string ReadStringp50() {
    string S1;
    getline(cin >> ws, S1); // ws to consume leading whitespace
    return S1;
}

// Generic Split function for convenience (copied from Prob45)
vector<string> Splitp50(string S, string Delimiter) {
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

struct stClientDatap50
{
	string accountNumber;
	string pinCode;
	string name;
	string phoneNumber;
	string accountBalance;
	bool MarkedForDelete = false; // Added for this solution
};

stClientDatap50 ConvertClientRecordToDatap50(string DataRecord, string Deli)
{
	vector<string> vClient;
	stClientDatap50 sClientData;

	vClient = Splitp50(DataRecord, Deli);

	sClientData.accountNumber = vClient[0];
	sClientData.pinCode = vClient[1];
	sClientData.name = vClient[2];
	sClientData.phoneNumber = vClient[3];
	sClientData.accountBalance = vClient[4];

	return sClientData;
}

void PrintClientCardp50(stClientDatap50 Data)
{
	cout << "\nAccount Number: " << Data.accountNumber << endl;
	cout << "Pin Code: " << Data.pinCode << endl;
	cout << "Name: " << Data.name << endl;
	cout << "Phone Number: " << Data.phoneNumber << endl;
	cout << "Account Balance: " << Data.accountBalance << endl;
}

vector<stClientDatap50> LoadClientsFromFilep50(string FileName)
{
	vector<stClientDatap50> vClientsRecord;
	string ClientLine;
	stClientDatap50 Client;

	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		while (getline(MyFile, ClientLine))
		{
			Client = ConvertClientRecordToDatap50(ClientLine, "#//#");
			vClientsRecord.push_back(Client);
		}

		MyFile.close();
	}

	return vClientsRecord;
}

bool FindClientByAccountNumberp50(vector<stClientDatap50> vClients, string AccNumber, stClientDatap50& Client)
{
	for (stClientDatap50 C : vClients)
	{
		if (C.accountNumber == AccNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

string ConvertRecordToLinep50(stClientDatap50 Data, string Deli)
{
	string veClientData;
	veClientData += Data.accountNumber + Deli;
	veClientData += Data.pinCode + Deli;
	veClientData += Data.name + Deli;
	veClientData += Data.phoneNumber + Deli;
	veClientData += Data.accountBalance;

	return veClientData;
}

void MarkClientAsDeletedp50(vector<stClientDatap50> &vClients, string AccNumber)
{
	for (stClientDatap50 &C : vClients)
	{
		if (C.accountNumber == AccNumber)
		{
			C.MarkedForDelete = true;
		}
	}
}

void SaveClientsDataToFilep50(vector<stClientDatap50> &vClients)
{
	fstream MyFile;
	MyFile.open(FileNamep50, ios::out);
	
	if (MyFile.is_open())
	{
		for (stClientDatap50 C : vClients)
		{
			if (C.MarkedForDelete == false)
			{
				MyFile << ConvertRecordToLinep50(C, "#//#") << '\n';
			}
		}

		MyFile.close();
	}
}

void DeleteClientFromFilep50(string AccountNumber, vector<stClientDatap50>& vClients)
{

stClientDatap50 Client;
	if (FindClientByAccountNumberp50(vClients, AccountNumber, Client))
	{
		PrintClientCardp50(Client);

		char Confirm = 'n';
		cout << "\nAre you sure you want to delete this account number? (Y/N)\n";

		cin >> Confirm;

		if (tolower(Confirm) == 'y') // Corrected if condition
		{
			MarkClientAsDeletedp50(vClients, AccountNumber);
			SaveClientsDataToFilep50(vClients);
			cout << "\nClient Deleted Successfully!\n";
		}
		else
		{
			cout << "\nClient Deletion Cancelled.\n";
		}
	}
	else
		cout << "\nAccount With " << AccountNumber << " Is not found.\n";
}

void Prob50_DeleteClient()
{
	cout << "Enter Client Number You Want to Delete: ";
	string AccountNumber = ReadStringp50();

	vector<stClientDatap50> vClients = LoadClientsFromFilep50(FileNamep50);
	
	DeleteClientFromFilep50(AccountNumber, vClients);

	// Refresh vector - not explicitly needed for the main function but good practice if more operations followed
	// vClients = LoadClientsFromFilep50(FileNamep50); 
	 
	system("Pause>0");
}
