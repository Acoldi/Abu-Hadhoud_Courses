#pragma once
#include"clsPerson.h"
#include"clsString.h"
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;

class clsBankClient : public clsPerson
{
private:
	enum enMode {EmptyMode = 0, UpdateMode = 1, AddNewMode=2};

	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkedForDelete = false;

	static clsBankClient _GetEmptyClient()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static clsBankClient _ConvertLinetoClientObject(string Line, string Seporator = "#//#")
	{
		vector<string> vClient = clsString::Split(Line, Seporator);

		clsBankClient Client(enMode::UpdateMode, vClient[0], vClient[1],
			vClient[2], vClient[3], vClient[4], vClient[5], stod(vClient[6]));

		return Client;
	}

	static vector<clsBankClient> _LoadClientsDataFromFile()
	{
		vector<clsBankClient> vClient;

		fstream Myfile;
		Myfile.open("Clients.txt", ios::in); // Read mode

		if (Myfile.is_open())
		{
			string Line = "";
			while (getline(Myfile >> ws, Line))  // Is << ws necessary??
			{
				vClient.push_back(_ConvertLinetoClientObject(Line));
			}
			Myfile.close();
		}
		return vClient;
	}

	string _ConvertClientToLine(clsBankClient Client, string Seporator = "#//#")
	{
		string sClient = "";

		sClient += Client.Name + Seporator;
		sClient += Client.LastName + Seporator;
		sClient += Client.Email + Seporator;
		sClient += Client.PhoneNumber + Seporator;
		sClient += Client.AccountNumber() + Seporator;
		sClient += Client.PinCode + Seporator;
		sClient += to_string(Client.AccountBalance);
		return sClient;
	}

	void _SaveCleintsDataToFile(vector<clsBankClient> vClients)
	{
		fstream Myfile;
		Myfile.open("Clients.txt", ios::out); // Overwrite
		
		if (Myfile.is_open())
		{
			for (clsBankClient C : vClients)
			{
				if (C.MarkedForDelete() == false)
					Myfile << _ConvertClientToLine(C) << endl;
			}
			Myfile.close();
		}
	}

	void _Update()
	{
		vector<clsBankClient> _vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C._AccountNumber == _AccountNumber)
			{
				C = *this;
				break;
			}
		}

		_SaveCleintsDataToFile(_vClients);
	}

	void _AddDatalineTofile(string Line)
	{
		Line = _ConvertClientToLine(*this);

		fstream Myfile;
		Myfile.open("Clients.txt", ios::app | ios::app);

		if (Myfile.is_open())
		{
			Myfile << Line << endl;
			
			Myfile.close();
		}
	}

	void _AddNewClient()
	{
		_AddDatalineTofile(_ConvertClientToLine(*this));
	}

	struct stTransferLogInfo;
	static stTransferLogInfo _ConvertTransferLogLineToRecord(clsString Line)
	{
		stTransferLogInfo TransferInfo;
		vector<string> vTransferLogLine = Line.Split("#//#");

		TransferInfo.DateAndTime = vTransferLogLine[0];
		TransferInfo.SourceAccountNumber = vTransferLogLine[1];
		TransferInfo.DestAccountNumber = vTransferLogLine[2];
		TransferInfo.Amount = stof(vTransferLogLine[3]);
		TransferInfo.SourceAccountBalance= stof(vTransferLogLine[4]);
		TransferInfo.DestAccountBalance = stof(vTransferLogLine[5]);
		TransferInfo.UserName = vTransferLogLine[6];

		return TransferInfo;
	}

	string _PrepareTransferLogLine(float Amount, clsBankClient DestinationClient, string Separator, string UserName)
	{
		string Line = "";
		Line = clsDate::GetSystemDatetimeString() + Separator;
		Line += this->_AccountNumber + Separator;
		Line += DestinationClient._AccountNumber + Separator;
		Line += to_string(Amount) + Separator;
		Line += to_string(this->AccountBalance) + Separator;
		Line += to_string(DestinationClient.AccountBalance) + Separator;
		Line += UserName;

		return Line;
	}
	void _RegisterTranferLog(float Amount, clsBankClient DestinationClient, string UserName)
	{
		string Line = _PrepareTransferLogLine(Amount, DestinationClient, "#//#", UserName);

		fstream Myfile;
		Myfile.open("TransferLog.txt", ios::out | ios::app);

		if (Myfile.is_open())
		{
			Myfile << Line << endl;

			Myfile.close();
		}
	}

public:
	clsBankClient(enMode Mode, string Name, string LastName, string Email, string PhoneNumber,
		string AccountNumber, string PinCode, float AccountBalance) :
		clsPerson(Name, LastName, Email, PhoneNumber)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFIle;
		MyFIle.open("Clients.txt", ios::in);

		if (MyFIle.is_open())
		{
			string Line;
			while (getline(MyFIle >> ws, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client._AccountNumber == AccountNumber)
				{
					return Client;
					break;
				}
			}
			MyFIle.close();
		}
		return _GetEmptyClient();
	}
	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		fstream MyFIle;
		MyFIle.open("Clients.txt", ios::in);

		if (MyFIle.is_open())
		{
			string Line;
			while (getline(MyFIle >> ws, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client._AccountNumber == AccountNumber && Client._PinCode == PinCode)
				{
					return Client;
				}
			}
			MyFIle.close();
		}
		return _GetEmptyClient();
	}

	/*void Print()  // No UI related code in Objects
	{
		cout << "\tClietn Card\n";
		cout << "__________________________________\n";
		cout << "Name           : " << Name << endl;  // what variable are these?
		cout << "LastName       : " << LastName << endl;
		cout << "Email          : " << Email << endl;
		cout << "Phone Number   : " << PhoneNumber << endl;
		cout << "Account Number : " << _AccountNumber << endl;
		cout << "Pin Code       : " << _PinCode << endl;
		cout << "Account Balance: " << _AccountBalance << endl;
		cout << "__________________________________\n";
	}*/

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	// This enum is to return the status of the saving process
	// giving the choice to the programmer to decide what to do if saved/unsaved.

	enum enSaveResults {svFailedEmptyObject=0, svSucceeded=	1, svFailedAccountNumberExists=2};
	enSaveResults Save()
	{
		switch (_Mode)
		{
		case clsBankClient::EmptyMode:
			return enSaveResults::svFailedEmptyObject;

		case clsBankClient::UpdateMode:
			{
				_Update();
				return enSaveResults::svSucceeded;

				break;
			}
		case clsBankClient::AddNewMode:
		{
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFailedAccountNumberExists;
			}
			else
			{
				_AddNewClient();
				return enSaveResults::svSucceeded;
			}
		}
		}
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);

		return (!Client._Mode == enMode::EmptyMode); // If client is not empty, it exists in the file. Hence the mode is updatemode
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete()
	{
		vector<clsBankClient> vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C._MarkedForDelete = true;
				break;
			}
		}

		*this = _GetEmptyClient(); // The object in memory should be empty when deleting its stored record

		_SaveCleintsDataToFile(vClients);

		return true;
	}

	bool MarkedForDelete()
	{
		return _MarkedForDelete;
	}

	static vector<clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	// To make perform operations on the current object and save it in file at the same time
	void Deposite(float Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	// There is only 1 reason -in our case- that causes the withdraw to fail which is the amount of the withdraw amount
	// So we make the return value boolean not a certain dedicated enum.
	bool Withdraw (float Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
			return true;
		}
	}

	static double GetTotalBalances()
	{
		vector<clsBankClient> vClients = GetClientsList();

		double totalBalance = 0;

		for (clsBankClient C : vClients)
		{
			totalBalance += C.AccountBalance;
		}

		return totalBalance;
	}

	bool Transfer(float Amount, clsBankClient& DestinationClient, string UserName) // Calling BY reference is necessary!
	{
		if (Amount > AccountBalance)
			return false;

		Withdraw(Amount);
		DestinationClient.Deposite(Amount);

		_RegisterTranferLog(Amount, DestinationClient, UserName);

		return true;
	}

	struct stTransferLogInfo {
		string DateAndTime;
		string SourceAccountNumber;
		string DestAccountNumber;
		float Amount;
		float SourceAccountBalance;
		float DestAccountBalance;
		string UserName;
	};
	static vector<stTransferLogInfo> GetTransferLoginList() // This is related with both the client and the user object??
	{
		fstream file;
		file.open("TransferLog.txt", ios::in);

		if (file.is_open())
		{
			vector<stTransferLogInfo> vTransferLogList;
			stTransferLogInfo TransferLog;

			string Line = "";

			while (getline(file >> ws, Line))
			{
				TransferLog = _ConvertTransferLogLineToRecord(Line);
				vTransferLogList.push_back(TransferLog);
			}
			file.close();
			return vTransferLogList;
		}
	}


	// Set Properties
	string AccountNumber()
	{
		return this->_AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		this->_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return this->_PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;


	void SetAccountBalnce(float AccBalance)
	{
		this->_AccountBalance = AccBalance;
	}

	float GetAccountBalance()
	{
		return this->_AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalnce)) float AccountBalance;


};

