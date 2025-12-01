#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

const string FileNamep49 = "Clients.txt";

// Generic ReadString function for convenience (copied from Prob45)
string ReadStringp49() {
    string S1;
    getline(cin >> ws, S1); // ws to consume leading whitespace
    return S1;
}

// Generic Split function for convenience (copied from Prob45)
vector<string> Splitp49(string S, string Delimiter) {
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

struct stClientDatap49
{
	string accountNumber;
	string pinCode;
	string name;
	string phoneNumber;
	string accountBalance;
};

stClientDatap49 ConvertClientRecordToDatap49(string DataRecord, string Deli)
{
	vector<string> vClient;
	stClientDatap49 sClientData;

	vClient = Splitp49(DataRecord, Deli);

	sClientData.accountNumber = vClient[0];
	sClientData.pinCode = vClient[1];
	sClientData.name = vClient[2];
	sClientData.phoneNumber = vClient[3];
	sClientData.accountBalance = vClient[4];

	return sClientData;
}

void PrintClientCardp49(stClientDatap49 Data)
{
	cout << "       Client Data\n\n";
	cout << "Account Number: " << Data.accountNumber << endl;
	cout << "Pin Code: " << Data.pinCode << endl;
	cout << "Name: " << Data.name << endl;
	cout << "Phone Number: " << Data.phoneNumber << endl;
	cout << "Account Balance: " << Data.accountBalance << endl;
}

vector<stClientDatap49> LoadClientsFromFilep49(string FileName)
{
	vector<stClientDatap49> vClientsRecord;
	string ClientLine;
	stClientDatap49 Client;

	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		while (getline(MyFile, ClientLine))
		{
			Client = ConvertClientRecordToDatap49(ClientLine, "#//#");
			vClientsRecord.push_back(Client);
		}

		MyFile.close();
	}

	return vClientsRecord;
}

bool FindClientByAccountNumberp49(string AccNumber, stClientDatap49 &Client)
{
	vector<stClientDatap49> vClients = LoadClientsFromFilep49(FileNamep49);

	for (stClientDatap49 C : vClients)
	{
		if (C.accountNumber == AccNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

void Prob49_FindClientByAccountNumber()
{
	stClientDatap49 Client;
	cout << "Enter Client Number: ";
	string AccountNumber = ReadStringp49();

	if (FindClientByAccountNumberp49(AccountNumber, Client))
	{
		PrintClientCardp49(Client);
	}
	else
		cout << "Client with " << AccountNumber << " Is Not Found\n";
	
	system("Pause>0");
}
