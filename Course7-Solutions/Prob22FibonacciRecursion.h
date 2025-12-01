#pragma once
#include <iostream>

using namespace std;

void PrintFibonacciUsingRecursionp22(short Number, int Prev1, int Prev2)
{
	int FibNumber = 0;
	if (Number > 0)
	{
		FibNumber = Prev1 + Prev2;
		cout << FibNumber << "   ";
		Prev2 = Prev1;
		Prev1 = FibNumber;

		PrintFibonacciUsingRecursionp22(Number - 1, Prev1, Prev2);
	}
}

void Prob22_FibonacciRecursion()
{
    cout << "Fibonacci series using recursion:\n";
    PrintFibonacciUsingRecursionp22(10, 0, 1);
    cout << endl;
    system("Pause>0");
}

