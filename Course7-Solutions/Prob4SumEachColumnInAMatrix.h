#pragma once
#include <iostream>
#include <iomanip>
#include "RandomNumber.h"

using namespace std;

int SummColumn_p4(int Arr[3][3], short Row, short CurrentCol)
{
	int sum = 0;
	for (int i = 0; i < Row; i++)
	{
		sum += Arr[i][CurrentCol];
	}
	return sum;
}

void FIllMatrixWithRandomNumbers_p4(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Arr[i][j] = RandomNumber(1, 100);
		}
	}
}

void SumMatrixsColumns_p4(int SummArray[3], int Arr[3][3], short Row, short Col)
{
	for (int i = 0; i < Col; i++)
	{
		*(SummArray + i) = SummColumn_p4(Arr, Row, i);
	}
}


void PrintMAtrix_p4(int Arr[3][3], short Rows, short Cols)
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

void PrintColumnSumaArray_p4(int Arr[3])
{
	for (int i = 0; i < 3; i++)
	{
		cout << "Sum of [" << i + 1 << "] Column: ";
		cout << Arr[i] << endl;
	}
}

void Prob4SumEachColumnInAMatrix()
{
	srand((unsigned)time(0));

	int Arr[3][3];
	int SummRows[3];

	FIllMatrixWithRandomNumbers_p4(Arr, 3, 3);

	cout << "The matrix:\n";
	PrintMAtrix_p4(Arr, 3, 3);

	SumMatrixsColumns_p4(SummRows, Arr, 3, 3);

	cout << "Column Summation:\n";
	PrintColumnSumaArray_p4(SummRows);
}
