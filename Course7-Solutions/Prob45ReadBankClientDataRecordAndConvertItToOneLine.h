#pragma once
#include <iostream>
#include <string>
using namespace std;

struct ClientDataRecord
{
	string AccountNumer;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

ClientDataRecord ReadCLientDate()
{
	ClientDataRecord clientDataRecord;

	cout << "Enter Client Data";
	cout << "Account Number: "; cin >> clientDataRecord.AccountNumer; cout << endl;
	cout << "Pin code: "; cin >> clientDataRecord.PinCode; cout << endl;
	cout << "Name: "; cin >> clientDataRecord.Name; cout << endl;
	cout << "Phone: "; cin >> clientDataRecord.Phone; cout << endl;
	cout << "Account Balance: "; cin >> clientDataRecord.AccountBalance; cout << endl;

	return clientDataRecord;
}

string ConvertClientDataToOneLine(ClientDataRecord clientdr, string delimeter)
{
	
	return clientdr.Name +
		delimeter +
		clientdr.AccountNumer +
		delimeter +
		clientdr.PinCode +
		delimeter +
		clientdr.Name +
		delimeter +
		clientdr.Phone +
		delimeter +
		std::to_string(clientdr.AccountBalance);
}

void Prob45ReadBankClientDataRecordAndConvertItToOneLine()
{

	ClientDataRecord cld =  ReadCLientDate();

	cout << ConvertClientDataToOneLine(cld, "#//#");
}