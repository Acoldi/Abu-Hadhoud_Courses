#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"
#include "clsUtil.h"
#include <cstdlib>
using namespace std;

class clsInputValidate
{
public:
	 template <typename T>
     static bool IsNumberBetween(T number, T From, T To)
     {
         return (number <= To && number >= From);
     }
     
     static bool IsDateBetween(clsDate Date, clsDate from, clsDate to)
     {
         if ((clsDate::IsDate1AfterDate2(Date, from) || clsDate::IsDate1EqualtoDate2(Date, from)) 
             &&
         (clsDate::IsDate1BeforeDate2(Date, to) || clsDate::IsDate1EqualtoDate2(Date, to)))
         {
             return true;
         }

         if ((clsDate::IsDate1BeforeDate2(Date, from) || clsDate::IsDate1EqualtoDate2(Date, from))
                 && (clsDate::IsDate1AfterDate2(Date, to) || clsDate::IsDate1EqualtoDate2(Date, to)))
         {
             return true;
         }

         return false;
     }

     template <typename T>
     static T ReadNumber(string ErrorMessage = "Invalid Number, Try again: ")
     {
         T number;
         while (!(cin >> number)) {
             cin.clear();
             cin.ignore(numeric_limits<streamsize>::max(), '\n');
             cout << ErrorMessage;
         }
         return number;
     }

     template <typename T>
     static T ReadNumberBetween(T from, T to, string ErrorMessage = "Invalid Number, Enter Again: ")
     {
         T number = ReadNumber<T>();
         while (!IsNumberBetween(number, from, to))
         {
             cout << ErrorMessage;
             number = ReadNumber<T>();
         }
         return number;
     }

     static bool IsValidDate(clsDate Date)
     {
         return clsDate::IsValidDate(Date);
     }
     
     static string ReadString()
     {
         string text = "";
         getline(cin >> ws, text);

         return text;
     }

     static string UpperStringLetters(string Text)
     {
         for (int i = 0; i < Text.length(); i++)
         {
             Text[i] = toupper(Text[i]);
         }
         return Text;
     }

     static string UpperFirstLetters(string Text)
     {
         bool IsFirstLetter = true;

         for (int i = 0; i < Text.length(); i++)
         {
             // If the current letter is not dash and the previous letter is dash
             if (Text[i] != ' ' && IsFirstLetter)
             {
                 Text[i] = toupper(Text[i]);
             }

             IsFirstLetter = (Text[i] == ' ' ? true : false);
         }

         return Text;
     }
};

