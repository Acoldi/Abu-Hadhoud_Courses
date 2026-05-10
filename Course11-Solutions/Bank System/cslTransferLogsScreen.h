#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "Global.h"


class cslTransferLogsScreen : protected clsScreen
{
	static string _ReadAccountNumber(string Message)
	{
		string AccNum = "";
		cout << Message;
		AccNum = clsInputValidate::ReadString();

		return AccNum;
	}

public:
	static void ShowTransferLogsScreen()
	{
		_DrawScreenHeader("\tTranfer Logs Screen");

		vector<clsBankClient::stTransferLogInfo> vTransferLogs = clsBankClient::GetTransferLoginList();

		cout << setw(8) << "" << "_______________________________________________________________________________________________________________________________\n";
		cout << setw(8) << "" << "| " << left << setw(23) << "Date/Time";
		cout << "| " << left << setw(16) << "Source Account";
		cout << "| " << left << setw(16) << "Dest Account";
		cout << "| " << left << setw(16) << "Amount";
		cout << "| " << left << setw(16) << "Source Balance";
		cout << "| " << left << setw(16) << "Dest Balance";
		cout << "| " << left << setw(16) << "Username" << endl;
		cout << setw(8) << "" << "_______________________________________________________________________________________________________________________________\n\n";

		for (clsBankClient::stTransferLogInfo T : vTransferLogs)
		{
			cout << setw(8) << "" << "| " << left << setw(23) << T.DateAndTime;
			cout << "| " << left << setw(16) << T.SourceAccountNumber;
			cout << "| " << left << setw(16) << T.DestAccountNumber;
			cout << "| " << left << setw(16) << T.Amount;
			cout << "| " << left << setw(16) << T.SourceAccountBalance;
			cout << "| " << left << setw(16) << T.DestAccountBalance;
			cout << "| " << left << setw(16) << T.UserName << endl;
		}
		cout << setw(8) << "" << "_______________________________________________________________________________________________________________________________\n\n";


	}
};/*TransferInfo.DateAndTimel = stof(vTransferLogLine[0]);
		TransferInfo.SourceAccountNumber = vTransferLogLine[1];
		TransferInfo.DestAccountNumber = vTransferLogLine[2];
		TransferInfo.Amount = stof(vTransferLogLine[3]);
		TransferInfo.SourceAccountBalance= stof(vTransferLogLine[4]);
		TransferInfo.DestAccountBalance = stof(vTransferLogLine[5]);
		TransferInfo.UserName = vTransferLogLine[6];*/

