#pragma once
#include <iostream>
#include <iomanip>
#include "RandomNumber.h"

using namespace std;

void FIllMatrixWithRandomNumbers_p8(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void Multiply2Matrix_p8(int Matrix1[3][3], int Matrix2[3][3], short Row, short Column)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			Matrix2[i][j] *= Matrix1[i][j];
		}
	}
}

void PrintMatrix_p8(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			printf("%.2i     ",Arr[i][j]);  
		}
		cout << endl;
	}
}

void Prob8Multiply2Matrices()
{
	srand((unsigned)time(0));

	int Matrix1[3][3];
	int Matrix2[3][3];

	FIllMatrixWithRandomNumbers_p8(Matrix1, 3, 3);
	FIllMatrixWithRandomNumbers_p8(Matrix2, 3, 3);

	cout << "Matrix1:\n";
	PrintMatrix_p8(Matrix1, 3, 3);

	cout << "\nMatrix2:\n";
	PrintMatrix_p8(Matrix2, 3, 3);

	Multiply2Matrix_p8(Matrix1, Matrix2, 3, 3);

	cout << "\nMatrix2 Multiplied by Matrix1:\n";
	PrintMatrix_p8(Matrix2, 3, 3);
}
