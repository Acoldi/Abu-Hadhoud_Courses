#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include <string>
#include "clsString.h"
using namespace std;

class clsCurrency
{
	enum eMode {eEmptyMode = 1, eUpdateMode = 2};
	eMode _Mode;
	
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;


	static string _ConverCurrencyObjectToLine(clsCurrency Currency, string Seporator = "#//#")
	{
		string Line = "";
		Line = Currency.Country + Seporator;
		Line += Currency.CurrencyCode + Seporator;
		Line += Currency._CurrencyName + Seporator;
		Line += to_string(Currency.Rate);

		return Line;
	}

	static void _SaveCurrencyDataToFile(vector<clsCurrency> vCurrencies)
	{
		fstream Myfile;
		Myfile.open("Currencies.txt", ios::out);

		if (Myfile.is_open())
		{
			string Line;
			for (clsCurrency C : vCurrencies)
			{
				Line = _ConverCurrencyObjectToLine(C);
				Myfile << Line << endl;
			}

			Myfile.close();
		}
	}

	void _Update()
	{		
		vector<clsCurrency> vCurrencies = _LoadCurrencysDataFromFile();

		for (clsCurrency& C : vCurrencies)
		{
			if (C.CurrencyCode == _CurrencyCode)
			{
				C = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(vCurrencies);

	}

	static clsCurrency _GetEmptyCurrency()
	{
		return clsCurrency(eMode::eEmptyMode, "", "", "", 0);
	}

	static clsCurrency _ConvertLinetoCurrencyObject(string Line)
	{
		vector<string> vLine = clsString::Split(Line, "#//#");

		clsCurrency Currency(eMode::eUpdateMode, vLine[0], vLine[1], vLine[2], stof(vLine[3]));
		return Currency;
	}

	static vector<clsCurrency> _LoadCurrencysDataFromFile()
	{
		fstream Myfile;
		Myfile.open("Currencies.txt", ios::in);
		
		if (Myfile.is_open())
		{
			vector<clsCurrency> vCurrencies;
			string Line;

			while (getline(Myfile >> ws, Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
				vCurrencies.push_back(Currency);
			}

			Myfile.close();

			return vCurrencies;
		}
	}

public:
	clsCurrency(eMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	string GetCurrencyCode()
	{
		return _CurrencyCode;
	}
	__declspec(property(get = GetCurrencyCode)) string CurrencyCode;

	string GetCountry()
	{
		return _Country;
	}
	__declspec(property(get = GetCountry)) string Country;

	string GetCurrencyName()
	{
		return _CurrencyName;
	}
	__declspec(property(get = GetCurrencyName)) string Name;

	float GetRate()
	{
		return _Rate;
	}
	float SetRate(float Rate)
	{
		_Rate = Rate;
	}
	__declspec(property(get = GetRate, put = SetRate)) float Rate;
	

	float UpdateRate(float Rate)
	{
		_Rate = Rate;
		_Update();

		return true;
	}

	bool IsEmpty()
	{
		return _Mode == eMode::eEmptyMode;
	}

	static vector<clsCurrency> GetAllUSDRates()
	{
		return _LoadCurrencysDataFromFile();
	}

	static clsCurrency FindByCode(string Code)
	{
		vector<clsCurrency> vCurrencies = _LoadCurrencysDataFromFile();

		for (clsCurrency C : vCurrencies)
		{
			if (C.CurrencyCode == Code)
			{
				return C;
				break;
			}
		}
		return _GetEmptyCurrency();
	}

	static clsCurrency FindByCountry(string Country)
	{
		vector<clsCurrency> vCurrencies = _LoadCurrencysDataFromFile();

		for (clsCurrency C : vCurrencies)
		{
			if (C.Country == Country)
			{
				return C;
				break;
			}
		}
		return _GetEmptyCurrency();
	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
		return (!C1.IsEmpty());

	}

	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrencysDataFromFile();
	}

	float ConverToUSD(float Amount)
	{
		return Amount / Rate;
	}

	float ConverToOtherCurrency(float Amount, clsCurrency ToCurrency)
	{
		float AmountInUSD = Amount / Rate;

		if (ToCurrency.CurrencyCode == "USD")
		{
			return AmountInUSD;
		}

		return (float)AmountInUSD * ToCurrency.Rate;
	}


};

