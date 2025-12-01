#pragma once
#include <iostream>

using namespace std;

void PrintFiboncciUsingLoopp21(short Number)
{
	int FibNumber = 1, Prev1 = 0, Prev2 = 0;
	
	for (int i = 1; i < Number; i++)
	{
		cout << Prev1 + FibNumber << "   ";
		Prev2 = Prev1;
		Prev1 = FibNumber;
		FibNumber = Prev1 + Prev2;
	}
    cout << endl;
}

void Prob21_FibonacciSeriesLoop() 
{
    short Number = 10;
    cout << "Fibonacci series of " << Number << " numbers:\n";
    PrintFiboncciUsingLoopp21(Number);
    system("Pause>0");
}

