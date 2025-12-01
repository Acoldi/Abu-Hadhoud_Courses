#pragma once
#include <iostream>
#include <iomanip>
#include "RandomNumber.h"

using namespace std;

void FIllMatrixWithRandomNumbers_p10(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Arr[i][j] = RandomNumber(1, 10);
		}
	}
}

int SumOfMatrix_p10(int Arr[3][3], short Row, short Column)
{
	int Sum = 0;
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column ; j++)
		{
			Sum += Arr[i][j];
		}
	}
	return Sum;
}

void PrintMatrix_p10(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			printf("%.2i     ", Arr[i][j]);
		}
		cout << endl;
	}
}

void Prob10SumOfMatrix()
{
	srand((unsigned)time(0));

	int Matrix1[3][3];

	FIllMatrixWithRandomNumbers_p10(Matrix1, 3, 3);

	cout << "Matrix:\n";
	PrintMatrix_p10(Matrix1, 3, 3);

	cout << "\nSum of Matrix = " << SumOfMatrix_p10(Matrix1, 3, 3) << endl;
}
