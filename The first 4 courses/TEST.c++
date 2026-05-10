#include <iostream>
#include <string>
#include <math.h>
using namespace std;

float ReadPositiveNum(string Message)
{
    float num;
    do
    {
        cout << Message << ": "; cin >> num;
    } while (num <= 0);
    
    return num;
}

// float SumNumbers()
// {
//     float num = 0;
//     float total = 0;
//     int counter = 0; 
//     do
//     {
//         counter += 1;
//         total += num;
//         num = ReadNum("Enter number " + to_string(counter));
//     }
//     while(num != -99);
//     return total;
// }

// enum enPrimeOrNot {prime = 1, NotPrime = 2};

// enPrimeOrNot IsPrime(int Num)
// {
//     for (int i = 2; i <= Num / 2; i++)
//     {
//         if (Num % i == 0)
//             return enPrimeOrNot::NotPrime;
//     }
//     return enPrimeOrNot::prime;
// }

// void printPrimeOrNot(enPrimeOrNot Type)
// {
//     if (Type == enPrimeOrNot::prime)
//         cout << "The number is prime.\n";
//     else
//         cout << "The number is not prime.\n";
// }

// float  CalculateRemainder(float TotalBill, float CashPaid)
// {
//     return CashPaid - TotalBill;
// }

// float AddFeeAndTax(float TotalBill)
// {
//     TotalBill *= 1.1;
//     return TotalBill *= 1.16;
// }

// float HoursToDays(float Hours)
// {
//     return Hours / 24;
// }

// float HoursToWeeks(float hours)
// {
//     // return hours / (7 * 24);
//     /*or*/ return hours / 24 / 7;
// }

// float DaysToweeks(float days)
// {
//     return days / 7;
// }

// struct strTimeUnits
// {
//     int days, hours, minutes, seconds;
// };

// strTimeUnits ReadTimUnits()
// {
//     strTimeUnits Units;
//     Units.days = ReadPositiveNum("Enter a number of days");
//     Units.hours = ReadPositiveNum("Enter a number of hours");
//     Units.minutes = ReadPositiveNum("Enter a number of minutes");
//     Units.seconds = ReadPositiveNum("Enter a number of seconds");
//     return Units;
// }

// strTimeUnits ConvertUnitsToSeconds(strTimeUnits Units)
// {
//     // I need variables that stores seocnds per each unit
//     int SecondsPerMinute = 60;
//     int SecondsPerHour = 60 * SecondsPerMinute;
//     int SecondsPerDay = 24 * SecondsPerHour;

//     Units.minutes *= SecondsPerMinute;
//     Units.hours *= SecondsPerHour;
//     Units.days *= SecondsPerDay;

//     return Units;
// }

// int CalculateTotalSeconds(strTimeUnits UnitsInSeconds)
// {
//     int TotalSeconds = 0;
//     TotalSeconds += UnitsInSeconds.days + UnitsInSeconds.hours +
//     UnitsInSeconds.minutes + UnitsInSeconds.seconds;
    
//     return TotalSeconds;
// }

// strTimeUnits SecondsToTimeUnits(int Seconds)
// {
//     strTimeUnits Units;
//     const int SecondPerMinute = 60;
//     const int SecondPerHour = 60 * SecondPerMinute;
//     const int SecondPerDay = 24 * SecondPerHour;

//     Units.days = floor(Seconds / SecondPerDay);
//     Seconds %= SecondPerDay;  // Because we want to find the seconds per hours not minutes.
//     Units.hours = floor(Seconds / SecondPerHour);
//     Seconds %= SecondPerHour;
//     Units.minutes = floor(Seconds / SecondPerMinute);
//     Seconds %= SecondPerMinute;
//     Units.seconds = Seconds;

//     return Units;
// }

// void PrintResult(strTimeUnits Units)
// {
//     cout << Units.days << ":" << Units.hours << ":" << Units.minutes << ":"
//     << Units.seconds;
// }

// enum enWeekDays {Sun = 1, Mon, Tue, Wed, Thu, Fri, Sat};

// int ReadNumberInRange(int From, int To, string Message)
// {
//     int Number;
//     do
//     {
//         cout << Message << endl;
//         cin >> Number;
//     }
//     while(Number <= From && Number >= To);
//     return Number;
// }

// enWeekDays ReadDayOfWeek()
// {
//     return (enWeekDays) ReadNumberInRange(1, 7, "Enter a number From 1 to 7 ");
// }

// string GetDayOfWeek(enWeekDays Day)
// {
//     switch ( Day)
//     {
//     case enWeekDays::Fri:
//         return "Friday";
//     case enWeekDays::Sat:
//         return "Saturday";
//     case enWeekDays::Sun:
//         return "Sunday";
//     case enWeekDays::Mon:
//         return "Monday";
//     case enWeekDays::Tue:
//         return "Tueseday";
//     case enWeekDays::Wed:
//         return "Wednessday";
//     case enWeekDays::Thu:
//         return "Thursday";
//     }
// }

// void PrintAtoZ(void)
// {
//     for (int i = 65; i < 91; i++)
//     {
//         cout << char(i) << endl;
//     }
// }

// int MotnthsTosettleLoanAmount(int LoatAmount, int MonthlyPayment)
// {
//     return (float) LoatAmount / MonthlyPayment;
// }

// float GetMonthlyInstallmentAmount(int amount, int NumberOfmonths)
// {
//     float Result = (float) amount / NumberOfmonths;
//     return Result;
// }

string ReadPinCode()
{
    string Pin;
    cout << "Enter PIN code: "; cin >> Pin;
    return Pin;
}

bool LogIn()
{
    string pinCode;
    int counter = 3;
    do
    {
        counter--;
        pinCode = ReadPinCode();
        if (pinCode == "1234")
        {
            return 1;
        }
        else
        {
            cout << "Wrong PIN, You have " << counter << " more tries\n";
            system("color 4F");
        }
    } while (pinCode != "1234" && counter > 0);
    cout << "Your card has been locked, call the bank for more information\n";
    return 0;
    
}

int main(void)
{
    // cout << SumNumbers() << endl;
    // printPrimeOrNot(IsPrime(ReadPositiveNum("Enter a positive number")));
    // float TotalBill = ReadPositiveNum("Enter the total bill");
    // float CashPaid = ReadPositiveNum("Enter the paid cash");
    // cout <<"The remainder: " << CalculateRemainder(TotalBill, CashPaid);
    // cout << "The total bill is " << AddFeeAndTax(ReadPositiveNum("Enter the total bill value"));
    // float Hours = ReadPositiveNum("Enter a number of hours");
    // float Days = HoursToDays(Hours);
    // float weeks = HoursToWeeks(Hours);
    // cout << "Days: " << Days << endl;
    // cout << "Weeks: " << weeks << endl;
    // cout << CalculateTotalSeconds(ConvertUnitsToSeconds(ReadTimUnits()));
    // PrintResult(SecondsToTimeUnits(ReadPositiveNum("Enter number of Seconds")));
    // cout << GetDayOfWeek(ReadDayOfWeek()) << endl;
    // The same as the above but for months.
    // PrintAtoZ();
    // float LoanAmount = ReadPositiveNum("The Loan amount");
    // float MonthlyPayment = ReadPositiveNum("The monthly payment amount");
    // cout << "the number of months to settle the loan amount is "
    //      << MotnthsTosettleLoanAmount(LoanAmount, MonthlyPayment);
    // float LoanAmount = ReadPositiveNum("Enter the loan amount");
    // float TotalAmount = ReadPositiveNum("Enter the total amount");
    // float Months = ReadPositiveNum("Enter the number of months to settle the amount");
    // cout << GetMonthlyInstallmentAmount(TotalAmount, Months);
    if (LogIn())
    {
        system("color 2F");
        cout << "Your balance is " << 7500 << '\n';
    }

}