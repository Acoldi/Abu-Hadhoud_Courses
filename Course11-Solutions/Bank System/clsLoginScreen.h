#pragma once
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "Global.h"
#include "clsDate.h"
#include <time.h>



class clsLoginScreen : protected clsScreen
{
	static bool _Login()
	{
		bool LoginFailed;
		short LoginFailedCount = 0;

		do
		{
			string UserName, Password;
			cout << "User Name: ";
			UserName = clsInputValidate::ReadString();
			cout << "Password: ";
			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(UserName, clsUtil::EncryptText(Password, 4));

			LoginFailed = CurrentUser.IsEmpty();

			if (LoginFailed)
			{
				LoginFailedCount++;

				cout << "Login Failed, you have " << 3 - LoginFailedCount << " trials left\n";
			}

			if (LoginFailedCount == 3)
			{
				cout << "Login Failed!\n";
				return false;
			}

		} while (LoginFailed);

		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenue();
		return true;
	}

public:
	static bool ShowLoginScreen()
	{
		_DrawScreenHeader("\t Login Screen");
		return _Login();
	}
};

