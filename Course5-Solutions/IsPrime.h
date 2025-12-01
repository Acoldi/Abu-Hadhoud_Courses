#pragma once
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

enum enPrimeOrNot {prime = 1, NotPrime = 2};

enPrimeOrNot IsPrime(int Num)
{
    for (int i = 2; i <= Num / 2; i++)
    {
        if (Num % i == 0)
            return enPrimeOrNot::NotPrime;
    }
    return enPrimeOrNot::prime;
}

void PrintPrimeNumbersTo(int To)
{
    cout << "prime numbers from 1 to " << To << " are\n";
    for (int i = 1; i <= To; i++)
    {
        if (IsPrime(i) == enPrimeOrNot::prime)
            cout << i << endl;
    }
}

