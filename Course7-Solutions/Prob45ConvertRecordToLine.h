#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream> // For fstream, though not used in this specific main

using namespace std;

// Generic ReadString function for convenience
string ReadStringp45() {
    string S1;
    getline(cin >> ws, S1); // ws to consume leading whitespace
    return S1;
}

// Generic Split function for convenience (needed for subsequent problems)
vector<string> Splitp45(string S, string Delimiter) {
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

struct stClientDatap45
{
	string accountNumber;
	string pinCode;
	string name;
	string phoneNumber;
	string accountBalance;
};

stClientDatap45 ReadClientDatap45()
{
	stClientDatap45 Data;

	cout << "       Client Data\n\n";
	cout << "Account Number: ";
	Data.accountNumber = ReadStringp45();
	cout << "Pin Code: ";
	Data.pinCode = ReadStringp45();
	cout << "Name: ";
	Data.name = ReadStringp45();
	cout << "Phone Number: ";
	Data.phoneNumber = ReadStringp45();
	cout << "Account Balance: ";
	Data.accountBalance = ReadStringp45();

	return Data;
}

string ConvertRecordToLinep45(stClientDatap45 Data, string Deli)
{
	string veClientData;
	veClientData += Data.accountNumber + Deli; 
	veClientData += Data.pinCode + Deli; 
	veClientData += Data.name + Deli; 
	veClientData += Data.phoneNumber + Deli; 
	veClientData += Data.accountBalance;

	return veClientData;
}


void Prob45_ConvertRecordToLine()
{
	stClientDatap45 stClientData = ReadClientDatap45();

	cout << "Client Record For saving is: \n  ";
	cout << ConvertRecordToLinep45(stClientData, "#//#") << endl;

	system("Pause>0");
}
