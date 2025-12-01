#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype> // For tolower

using namespace std;

// Generic ReadString function for convenience (copied from Prob45)
string ReadStringp47() {
    string S1;
    getline(cin >> ws, S1); // ws to consume leading whitespace
    return S1;
}

// Generic Split function for convenience (copied from Prob45)
vector<string> Splitp47(string S, string Delimiter) {
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

struct stClientDatap47
{
	string accountNumber;
	string pinCode;
	string name;
	string phoneNumber;
	string accountBalance;
};

stClientDatap47 ReadNewClientp47()
{
	stClientDatap47 Data;

	cout << "       Client Data\n\n";
	cout << "Account Number: ";
	getline(cin >> ws, Data.accountNumber); // Using getline with ws for account number
	cout << "Pin Code: ";
	Data.pinCode = ReadStringp47();
	cout << "Name: ";
	Data.name = ReadStringp47();
	cout << "Phone Number: ";
	Data.phoneNumber = ReadStringp47();
	cout << "Account Balance: ";
	Data.accountBalance = ReadStringp47();

	return Data;
}

string ConvertRecordToLinep47(stClientDatap47 Data, string Deli)
{
	string ClientData;
	ClientData += Data.accountNumber + Deli;
	ClientData += Data.pinCode + Deli;
	ClientData += Data.name + Deli;
	ClientData += Data.phoneNumber + Deli;
	ClientData += Data.accountBalance;

	return ClientData;
}

stClientDatap47 ConvertClientRecordToDatap47(string DataRecord, string Deli)
{
	vector<string> vClient;
	stClientDatap47 sClientData;

	vClient = Splitp47(DataRecord, Deli);
	
sClientData.accountNumber = vClient[0];
	sClientData.pinCode = vClient[1];
	sClientData.name = vClient[2];
	sClientData.phoneNumber = vClient[3];
	sClientData.accountBalance = vClient[4];

	return sClientData;
}

void AddDataLineToFilep47(string FileName, string Line)
{
	fstream Myfile;
	Myfile.open(FileName, ios::out | ios::app);

	if (Myfile.is_open())
	{
		Myfile << Line << endl;

		Myfile.close();
	}
}

void AddNewClientp47(string FileName)
{
	stClientDatap47 Client;
	Client = ReadNewClientp47();

	AddDataLineToFilep47(FileName, ConvertRecordToLinep47(Client, "#//\#"));
}

void PrintClientDatap47(stClientDatap47 Data)
{
	cout << "       Client Data\n\n";
	cout << "Account Number: " << Data.accountNumber << endl;
	cout << "Pin Code: " << Data.pinCode << endl;
	cout << "Name: " << Data.name << endl;
	cout << "Phone Number: " << Data.phoneNumber << endl;
	cout << "Account Balance: " << Data.accountBalance << endl;
}

void AddClientsp47(void)
{
	char AddMore = 'y';
	do
	{
		system("cls"); // This might not work on all systems, but kept as per original.
		cout << "Adding new client\n\n";

		AddNewClientp47("Clients.txt"); // Assuming Clients.txt is in the same directory
		cout << "Client Added successfully!\n";

		cout << "\nDo you want to add another client? y/n \n - "; cin >> AddMore;
	} while (tolower(AddMore) == 'y');
}

void Prob47_AddClientsToFile()
{
	AddClientsp47();
	system("Pause>0");
}
