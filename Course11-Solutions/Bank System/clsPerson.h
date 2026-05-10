#pragma once
#include<iostream>
#include"clsString.h"
#include"InterfaceComunication.h"


class clsPerson : public InterfaceComunication
{
private:
	string _Name;
	string _LastName;
	string _Email;
	string _PhoneNumber;

public:
	clsPerson(string Name, string LastName, string Email, string PhoneNumber)
	{
		_Name = Name;
		_LastName = LastName;
		_Email = Email;
		_PhoneNumber = PhoneNumber;
	}

	void SetName(string Name)
	{
		_Name = Name;
	}
	void SetLastName(string LName)
	{
		_LastName = LName;
	}
	void SetEmail(string Email)
	{
		_Email = Email;
	}
	void SetPhoneNumber(string PhoneNumber)
	{
		_PhoneNumber = PhoneNumber;
	}

	string GetName()
	{
		return _Name;
	}
	string GetLastName()
	{
		return _LastName;
	}
	string GetEmail()
	{
		return _Email;
	}
	string GetPhoneNUmber()
	{
		return _PhoneNumber;
	}

	__declspec(property(get = GetName, put = SetName)) string Name;
	__declspec(property(get = GetLastName, put = SetLastName)) string LastName;
	__declspec(property(get = GetPhoneNUmber, put = SetPhoneNumber)) string PhoneNumber;
	__declspec(property(get = GetEmail, put = SetEmail)) string Email;


	void SendSMS(string Title, string Body)
	{
		cout << "The following message sent successfully to the phone number: " << _PhoneNumber << endl;
		cout << Body;
	}
	void SendEmail(string Title, string Body)
	{
		cout << "The following message sent successfully to the email: " << _Email << endl;
		cout << "Subject: " << Title << endl;
		cout << "Body: " << Body << endl;
	}
	void SendFax(string Title, string Body)
	{

	}

};
