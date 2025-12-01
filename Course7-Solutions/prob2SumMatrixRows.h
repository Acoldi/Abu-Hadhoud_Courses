#pragma once

#include <iostream>
#include <iomanip>
#include "RandomNumber.h"
using namespace std;


void FIllMatrixWithRandomNumbers(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Arr[i][j] = RandomNumber(1, 100);
		}
	}
}

int SumMatrixsRow(int matrix[3][3], int RowNumber)
{
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum += matrix[RowNumber][i];
	}

	return sum;
}

void PrintMAtrix(int Arr[3][3], short Rows, short Cols)
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

void PrintRowSums(int Arr[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		cout << "Sum of [" << i + 1 << "] Row: ";
		cout << SumMatrixsRow(Arr,i) << endl;
	}
}

void prob2SumMatrixRows(void)
{
	srand((unsigned)time(0));

	int Arr[3][3];

	FIllMatrixWithRandomNumbers(Arr, 3, 3);

	cout << "The matrix:\n";
	PrintMAtrix(Arr, 3, 3);

	cout << "Rows Summation:\n";
	PrintRowSums(Arr);
}