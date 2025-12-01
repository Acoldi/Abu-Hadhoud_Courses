#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream> // For fstream, though not used in this specific main
#include <iomanip> // For setw, used in PrintClientData

using namespace std;

// Generic Split function for convenience (copied from Prob45)
vector<string> Splitp46(string S, string Delimiter) {
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

struct stClientDatap46
{
	string accountNumber;
	string pinCode;
	string name;
	string phoneNumber;
	string accountBalance;
};

stClientDatap46 ConvertClientRecordToDatap46(string DataRecord, string Deli)
{
	vector<string> vClient;
	stClientDatap46 sClientData;

	vClient = Splitp46(DataRecord, Deli);
	
sClientData.accountNumber = vClient[0];
	sClientData.pinCode = vClient[1];
	sClientData.name = vClient[2];
	sClientData.phoneNumber = vClient[3];
	sClientData.accountBalance = vClient[4];

	return sClientData;
}

void PrintClientDatap46(stClientDatap46 Data)
{
	cout << "       Client Data\n\n";
	cout << "Account Number: " << Data.accountNumber << endl;
	cout << "Pin Code: " << Data.pinCode << endl;
	cout << "Name: " << Data.name << endl;
	cout << "Phone Number: " << Data.phoneNumber << endl;
	cout << "Account Balance: " << Data.accountBalance << endl;
}

void Prob46_ConvertLineToRecord()
{
	string ClientRecord = "2222#//#1234#//#Alllawey#//#07826055128#//#77";
	stClientDatap46 ClientData;

	cout << "Client Data Record : " << ClientRecord << endl;
	
	ClientData = ConvertClientRecordToDatap46(ClientRecord, "#//#");

	PrintClientDatap46(ClientData);

	system("Pause>0");
}
