#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include "RandomNumber.h"

using namespace std;

void FIllMatrixWithRandomNumbersp11(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows + 1; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Arr[i][j] = RandomNumber(1, 10);
		}
	}
}

int SumOfMatrixp11(int Arr[3][3], short Row, short Column)
{
	int Sum = 0;
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column ; j++)
		{
			Sum += Arr[i][j];
		}
		cout << endl;
	}
	return Sum;
}

void PrintMatrixp11(int Arr[3][3], short Rows, short Cols)
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

bool CheckMatricesEquivilantp11(int Arr[3][3], int Arr2[3][3], short Row, short Col)
{
	return (SumOfMatrixp11(Arr, 3, 3) == SumOfMatrixp11(Arr2, 3, 3));
}

void Prob11_AreEqualMatrices()
{
	srand((unsigned)time(0));

	int Matrix1[3][3], Matrix2[3][3];

	FIllMatrixWithRandomNumbersp11(Matrix1, 3, 3);
	FIllMatrixWithRandomNumbersp11(Matrix2, 3, 3);

	cout << "Matrix1:\n";
	PrintMatrixp11(Matrix1, 3, 3);
	cout << "\nMatrix2:\n";
	PrintMatrixp11(Matrix2, 3, 3);

	if (CheckMatricesEquivilantp11(Matrix1, Matrix2, 3, 3))
		cout << "They are equivilant!\n";
	else
		cout << "They are not equivilant!\n";

	system("Pause>0");
}