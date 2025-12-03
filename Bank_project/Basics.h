#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

const string FileName = "Clients.txt";

int RandomNumber(int From, int To)
{
	int N;
	N = rand() % (To - From + 1) + From;
	return N;
}

int ReadNumber(string Text)
{

	int number;
	cout << Text; cin >> number;
	return number;
}



void PrintArray(int array[], int Length)
{
	for (int i = 0; i < Length; i++)
	{
		cout << array[i] << " ";
	}
}

string ReadString(void)
{
	string name;
	getline(cin, name);
	return name;
}

void FIllMatrixWithRandomNumbers(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows + 1; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Arr[i][j] = RandomNumber(1, 10);
		}
	}
}

bool IsNumberInMatrix(int Arr[3][3], short Row, short Col, int Number)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (Arr[i][j] == Number)
			{
				return true;
			}
		}
	}
	return false;
}

void UpperStringLetters(string& Text)
{

	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = toupper(Text[i]);
	}
}

void LowerStringLetters(string& Text)
{

	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = tolower(Text[i]);
	}
}

char InvertLetterCase(char C)
{
	return isupper(C) ? tolower(C) : toupper(C);
}

string JoinSting(vector<string> text, string Deli)
{
	string Result = "";
	for (string& word : text)
	{
		Result += word;
		Result += Deli;
	}
	return Result.substr(0, Result.length() - Deli.length());
}

vector <string> Split(string text, string Delimeter)
{
	vector <string> vString;
	int pos = 0;
	string word = "";

	while ((pos = text.find(Delimeter)) != std::string::npos)
	{
		word = text.substr(0, pos);

		if (word != "")
			vString.push_back(word);

		text.erase(0, pos + Delimeter.length());
	}

	if (text != "")
		vString.push_back(text);

	return vString;
}

void PrintEqualSigns(int Length)
{
	for (int i = 0; i < Length; i++)
	{
		cout << "=";
	}
	cout << '\n';
}

void PrintHorizentalLine(int Length)
{
	for (int i = 0; i < Length; i++)
	{
		cout << "_";
	}
}

struct stClientData
{
	string accountNumber;
	string pinCode;
	string name;
	string phoneNumber;
	double accountBalance = 0;
	bool MarkedForDelete = false;
};

stClientData ConvertLineToRecord(string DataRecord, string Deli)
{
	vector<string> vClient;
	stClientData sClientData;

	vClient = Split(DataRecord, Deli);

	sClientData.accountNumber = vClient[0];
	sClientData.pinCode = vClient[1];
	sClientData.name = vClient[2];
	sClientData.phoneNumber = vClient[3];
	sClientData.accountBalance = stod(vClient[4]);

	return sClientData;
}

void PrintClientCard(stClientData Data)
{
	cout << "_________________________________\n";
	cout << "\nAccount Number: " << Data.accountNumber << endl;
	cout << "Pin Code: " << Data.pinCode << endl;
	cout << "Name: " << Data.name << endl;
	cout << "Phone Number: " << Data.phoneNumber << endl;
	cout << "Account Balance: " << to_string(Data.accountBalance) << endl;
	cout << "_________________________________\n";
}

void LoadFileContentToVector(string FileName, vector <string>& Vector)
{
	fstream MyFile;

	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line;

		while (getline(MyFile, Line))
		{
			Vector.push_back(Line);
		}

		MyFile.close();
	}
}

void SaveVectorToFile(vector <string> VfileContent, string FileName)
{
	fstream MyFile;

	MyFile.open(FileName, ios::out);

	if (MyFile.is_open())
	{
		for (string Line : VfileContent)
		{
			if (Line != "") // or "\\n"
			{
				MyFile << Line << endl;
			}
		}

		MyFile.close();
	}
}

string ConvertRecordToLine(stClientData Data, string Deli)
{
	string veClientData;
	veClientData += Data.accountNumber + Deli;
	veClientData += Data.pinCode + Deli;
	veClientData += Data.name + Deli;
	veClientData += Data.phoneNumber + Deli;
	veClientData += to_string(Data.accountBalance);

	return veClientData;
}

void DeleteRecordFromFIle(string FileName, string Record)
{
	fstream MyFile;

	vector <string> vFile;

	LoadFileContentToVector(FileName, vFile);

	for (string& Line : vFile)
	{
		if (Line == Record)
		{
			Line = "";
		}
	}
	SaveVectorToFile(vFile, FileName);
}

vector<stClientData> LoadClientsFromFile(string FileName)
{
	vector<stClientData> vClientsRecord;
	string ClientLine;
	stClientData Client;

	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		while (getline(MyFile, ClientLine))
		{
			Client = ConvertLineToRecord(ClientLine, "#//#");
			vClientsRecord.push_back(Client);
		}

		MyFile.close();
	}

	return vClientsRecord;
}

bool FindClientByAccountNumber(string AccNumber, stClientData& Client, vector<stClientData>& vClients)
{

	for (stClientData& C : vClients)
	{
		if (C.accountNumber == AccNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

void SaveClientsDataToFile(vector<stClientData>& vClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out); // Write mod

	if (MyFile.is_open())
	{
		for (stClientData& C : vClients)
		{
			if (C.MarkedForDelete == false)
			{
				MyFile << ConvertRecordToLine(C, "#//#") << '\n';
			}
		}

		MyFile.close();
	}
}

stClientData ChangeClientData(string accNumber)
{
	stClientData Data;
	Data.accountNumber = accNumber;
	cout << "Pin Code: ";
	getline(cin >> ws, Data.pinCode);
	cout << "Name: ";
	Data.name = ReadString();
	cout << "Phone Number: ";
	Data.phoneNumber = ReadString();
	cout << "Account Balance: ";
	Data.accountBalance = stod(ReadString());

	return Data;
}

void UpdateClientByAccountNumber(string AccountNumber, vector<stClientData>& vClients)
{
	stClientData Client;
	if (FindClientByAccountNumber(AccountNumber, Client, vClients))
	{
		PrintClientCard(Client);

		char Confirm = 'n';
		cout << "Are you sure you want to update this account? (Y/N)\n";
		cin >> Confirm;

		if (Confirm == 'y' || Confirm == 'Y')
		{
			for (stClientData& C : vClients)
			{
				if (C.accountNumber == AccountNumber)
				{
					C = ChangeClientData(AccountNumber);
					break; // Important
				}
			}

			SaveClientsDataToFile(vClients);

			cout << "Client Updated Successfully!";
		}
	}
	else
		cout << "Account With " << AccountNumber << " Is not found";
}