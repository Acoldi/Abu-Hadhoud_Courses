#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip> // For setw, left

using namespace std;

const string FileNamep48 = "Clients.txt";

// Generic Split function for convenience (copied from Prob45)
vector<string> Splitp48(string S, string Delimiter) {
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

struct stClientDatap48
{
	string accountNumber;
	string pinCode;
	string name;
	string phoneNumber;
	string accountBalance;
};

stClientDatap48 ConvertClientRecordToDatap48(string DataRecord, string Deli)
{
	vector<string> vClient;
	stClientDatap48 sClientData;

	vClient = Splitp48(DataRecord, Deli);

	sClientData.accountNumber = vClient[0];
	sClientData.pinCode = vClient[1];
	sClientData.name = vClient[2];
	sClientData.phoneNumber = vClient[3];
	sClientData.accountBalance = vClient[4];

	return sClientData;
}

void PrintHorizentalLinep48(int Length)
{
	for (int i = 0; i < Length; i++)
	{
		cout << "_";
	}
}

void PrintClientp48(vector<stClientDatap48> Clients)
{
	for (stClientDatap48 &Client : Clients)
	{
		cout << endl << "| " << left << setw(20) << Client.accountNumber
			<< "| " << left << setw(20) << Client.pinCode
			<< "| " << left << setw(25) << Client.name 
			<< "| " << left << setw(20) << Client.phoneNumber
			<< "| " << left << setw(20) << Client.accountBalance;
		cout << endl;  PrintHorizentalLinep48(120);
	}
}

void PrintClientsTablep48(vector<stClientDatap48> vClients)
{
	cout << "Client List (" << vClients.size() << ") Clients" << endl << endl;

	PrintHorizentalLinep48(120); cout << endl;
    cout<< "| " << left << setw(20) << "AccountNumber"
		<< "| " << left << setw(20) << "Pin Code"
		<< "| " << left << setw(25) << "Name"
		<< "| " << left << setw(20) << "Phone Number"
		<< "| " << left << setw(20) << "Account Balance";
	cout << endl;  PrintHorizentalLinep48(120);

	PrintClientp48(vClients);
}

vector<stClientDatap48> LoadClientsFromFilep48(string FileName)
{
	vector<stClientDatap48> vClientsRecord;
	string ClientLine;
	stClientDatap48 Client;

	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		while (getline(MyFile, ClientLine))
		{
			Client = ConvertClientRecordToDatap48(ClientLine, "#//#");
			vClientsRecord.push_back(Client);
		}

		MyFile.close();
	}

	return vClientsRecord;
}

void Prob48_ReadClientsFromFile()
{
	vector<stClientDatap48> vClients = LoadClientsFromFilep48(FileNamep48);

	PrintClientsTablep48(vClients);
	
	system("Pause>0");
}
