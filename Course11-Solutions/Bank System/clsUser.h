#pragma once
#include"clsPerson.h"
#include"clsString.h"
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<iomanip>
#include "clsDate.h"
#include "clsUtil.h"



using namespace std;

class clsUser : public clsPerson
{
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };

	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permisions;
	bool _MarkedForDelete = false;

	static clsUser _GetEmptyUser()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static clsUser _ConvertLinetoUserObject(string Line, string Seporator = "#//#")
	{
		vector<string> vUsers = clsString::Split(Line, Seporator);

		clsUser User(enMode::UpdateMode, vUsers[0], vUsers[1],
			vUsers[2], vUsers[3], vUsers[4], vUsers[5], stoi(vUsers[6]));

		return User;
	}

	static vector<clsUser> _LoadUsersDataFromFile()
	{
		vector<clsUser> vUsers;

		fstream Myfile;
		Myfile.open("Users.txt", ios::in); // Read mode

		if (Myfile.is_open())
		{
			string Line = "";
			while (getline(Myfile >> ws, Line))  // Is << ws necessary??
			{
				vUsers.push_back(_ConvertLinetoUserObject(Line));
			}
			Myfile.close();
		}
		return vUsers;
	}

	string _ConvertUserToLine(clsUser User, string Seporator = "#//#")
	{
		string sUser = "";

		sUser += User.Name + Seporator;
		sUser += User.LastName + Seporator;
		sUser += User.Email + Seporator;
		sUser += User.PhoneNumber + Seporator;
		sUser += User._UserName + Seporator;
		sUser += clsUtil::EncryptText(User._Password, 4) + Seporator;
		sUser += to_string(User._Permisions);
		return sUser;
	}

	void _SaveUsersDataToFile(vector<clsUser> vUsers)
	{
		fstream Myfile;
		Myfile.open("Users.txt", ios::out); // Overwrite

		if (Myfile.is_open())
		{
			for (clsUser U : vUsers)
			{
				if (U._MarkedForDelete == false)
					Myfile << _ConvertUserToLine(U) << endl;
			}
			Myfile.close();
		}
	}

	void _Update()
	{
		vector<clsUser> vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : vUsers)
		{
			if (U._UserName == _UserName)
			{
				U = *this;
				break;
			}
		}

		_SaveUsersDataToFile(vUsers);
	}

	void _AddDatalineTofile(string Line)
	{
		Line = _ConvertUserToLine(*this);

		fstream Myfile;
		Myfile.open("Users.txt", ios::app | ios::app);

		if (Myfile.is_open())
		{
			Myfile << Line << endl;

			Myfile.close();
		}
	}

	void _AddNewUser()
	{
		_AddDatalineTofile(_ConvertUserToLine(*this));
	}

	string _PrepareLoginRecordLine(string Separator = "#//#")
	{
		string LoginRecord = "";
		LoginRecord += clsDate::GetSystemDatetimeString() + Separator;
		LoginRecord += UserName + Separator;
		LoginRecord += clsUtil::EncryptText(Password, 4) + Separator;
		LoginRecord += to_string(Permissions);

		return LoginRecord;
	}
	struct stLoginRegisterRecord;
	static stLoginRegisterRecord _ConvertLineToLoginRegisterRecord(string Line, string Separator = "#//#")
	{
		vector<string> vLine = clsString::Split(Line, Separator);

		stLoginRegisterRecord Record;

		Record.DateAndTime = vLine[0];
		Record.UserName = vLine[1];
		Record.Password = clsUtil::DecryptText(vLine[2], 4);
		Record.Permissions = stoi(vLine[3]);
		
		return Record;
	}

public:
	clsUser(enMode Mode, string Name, string LastName, string Email, string PhoneNumber,
		string UserName, string Password, int Permissions) :
		clsPerson(Name, LastName, Email, PhoneNumber)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permisions = Permissions;
	}

	// Set Properties
	void SetUserName(string Username)
	{
		this->_UserName = Username;
	}
	string GetUserName()
	{
		return this->_UserName;
	}
	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	void SetPassword(string Pword)
	{
		this->_Password = Pword;
	}
	string GetPassword()
	{
		return this->_Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;


	void SetPermissions(int Per)
	{
		this->_Permisions = Per;
	}
	int GetPermissions()
	{
		return this->_Permisions;
	}
	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;




	static clsUser Find(string UserName)
	{
		fstream MyFIle;
		MyFIle.open("Users.txt", ios::in);

		if (MyFIle.is_open())
		{
			string Line;
			while (getline(MyFIle >> ws, Line))
			{
				clsUser User = _ConvertLinetoUserObject(Line);
				if (User._UserName == UserName)
				{
					return User;
					break;
				}
			}
			MyFIle.close();
		}
		return _GetEmptyUser();
	}
	static clsUser Find(string UserName, string Password)
	{
		fstream MyFIle;
		MyFIle.open("Users.txt", ios::in);

		if (MyFIle.is_open())
		{
			string Line;
			while (getline(MyFIle >> ws, Line))
			{
				clsUser User = _ConvertLinetoUserObject(Line);
				if (User._UserName == UserName && User._Password == Password)
				{
					return User;
					break;
				}
			}
			MyFIle.close();
		}
		return _GetEmptyUser();
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	static bool IsUserExist(string UserName)
	{
		clsUser User = clsUser::Find(UserName);

		return (!User._Mode == enMode::EmptyMode); // If user is not empty, it exists in the file. Hence the mode is updatemode
	}

	enum enSaveResults { svFailedEmptyObject = 0, svSucceeded = 1, svFailedUserNameExists = 2 };
	enSaveResults Save()
	{
		switch (_Mode)
		{
		case clsUser::EmptyMode:
			return enSaveResults::svFailedEmptyObject;

		case clsUser::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;

			break; // Is this break important?
		}
		case clsUser::AddNewMode:
			if (clsUser::IsUserExist(UserName))
			{
				return enSaveResults::svFailedUserNameExists;
			}
			else
			{
				_AddNewUser();
				return enSaveResults::svSucceeded;
			}
		}
	}

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	bool Delete()
	{
		vector<clsUser> vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : vUsers)
		{
			if (U.UserName == _UserName)
			{
				U._MarkedForDelete = true;
				break;
			}
		}

		*this = _GetEmptyUser();

		_SaveUsersDataToFile(vUsers);

		return true;
	}

	/*bool MarkedForDelete() // I don't need this!
	{
		return _MarkedForDelete;
	}*/

	static vector<clsUser> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}

	// We define this enum publicly so the classes can inherits it "protectedly"
	enum enPermissions {
		All = -1, pShowClientList = 1, pAddNewClient = 2, pDeleteClient = 4, pUpdateClientInfo = 8, pFindClient = 16,
		pTransactions = 32, pShowLoginsLis = 64, pManageUsers = 128
	};

	bool CheckAccessPermission(short Permission)
	{
		if (Permission == enPermissions::All)
			return true;

		if ((Permission & this->Permissions) == Permission)
		{
			return true;
		}
		else
			return false;
	}

	void RegisterLogin()
	{
		string stDateline = _PrepareLoginRecordLine();

		fstream file;
		file.open("LoginRegister.txt", ios::app | ios::out);

		if (file.is_open())
		{
			file << stDateline << endl;

			file.close();
		}
	}

	struct stLoginRegisterRecord
	{
		string DateAndTime;
		string UserName;
		string Password;
		int Permissions;
	};

	static vector<stLoginRegisterRecord> GetLoginResgistersList()
	{
		fstream Myfile;
		Myfile.open("LoginRegister.txt");

		if (Myfile.is_open())
		{
			string Line;
			stLoginRegisterRecord LoginRecord;
			vector<stLoginRegisterRecord> vLoginRecords;

			while (getline(Myfile >> ws, Line))
			{
				// Convert Line to Data
				LoginRecord = _ConvertLineToLoginRegisterRecord(Line);
				vLoginRecords.push_back(LoginRecord);
			}
			Myfile.close();
			return vLoginRecords;
		}
	}
};

