#pragma once
#include <iostream>
#include <iomanip>
#include "RandomNumber.h"

using namespace std;

void FIllMatrixWithRandomNumbers_p3(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Arr[i][j] = RandomNumber(1, 100);
		}
	}
}

void SumMatrixsRows_p3(int SummArray[3], int Arr[3][3])
{
	SummArray[0] = 0;
	SummArray[1] = 0;
	SummArray[2] = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			*(SummArray+i) += Arr[i][j];
		}
	}
}


void PrintMAtrix_p3(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(3) << Arr[i][j] << "    ";
		}
		cout << endl;
	}
}

void PrintArray_p3(int Arr[3])
{
	for (int i = 0; i < 3; i++)
	{
		cout << "Sum of [" << i + 1 << "] Row: ";
		cout << Arr[i] << endl;
	}
}

void Prob3SumMatrixRowsUsingArray()
{
	srand((unsigned) time(0));

	int Arr[3][3];
	int SummRows[3];

	FIllMatrixWithRandomNumbers_p3(Arr, 3, 3);
	SumMatrixsRows_p3(SummRows, Arr);

	cout << "The matrix:\n";
	PrintMAtrix_p3(Arr, 3, 3);

	cout << "Rows Summation:\n";
	PrintArray_p3(SummRows);
}
