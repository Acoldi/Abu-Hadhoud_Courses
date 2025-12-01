#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include "RandomNumber.h"

using namespace std;

void FIllMatrixWithRandomNumbersp12(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows + 1; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintMatrixp12(int Arr[3][3], short Rows, short Cols)
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

bool AreTypicalMatricesp12(int Arr[3][3], int Arr2[3][3], short Row, short Col)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (Arr[i][j] != Arr2[i][j])
				return false;
		}
	}
	return true;
}

void Prob12_AreTypicalMatrices()
{
	srand((unsigned)time(0));

	int Matrix1[3][3], Matrix2[3][3];

	FIllMatrixWithRandomNumbersp12(Matrix1, 3, 3);
	FIllMatrixWithRandomNumbersp12(Matrix2, 3, 3);

	cout << "Matrix1:\n";
	PrintMatrixp12(Matrix1, 3, 3);
	cout << "\nMatrix2:\n";
	PrintMatrixp12(Matrix2, 3, 3);

	if (AreTypicalMatricesp12(Matrix1, Matrix2, 3, 3))
		cout << "They are Typical!\n";
	else
		cout << "They are not Typical!\n";

	system("Pause>0");
}