#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include "RandomNumber.h"

using namespace std;

void FIllMatrixWithRandomNumbersp14(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows + 1; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintMatrixp14(int Arr[3][3], short Rows, short Cols)
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

bool IsScalarMatrixp14(int Arr[3][3], short Row, short Col)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (i == j && Arr[i][j] != Arr[0][0])
			{
				return false;
			}
			else if (i != j && Arr[i][j] != 0)
				return false;
		}
	}
	return true;
}

void Prob14_IsScalarMatrix()
{
	srand((unsigned)time(0));

	int Matrix1[3][3] = { {1, 0, 0}, {0, 4, 0}, {0, 0, 1} };

	//FIllMatrixWithRandomNumbersp14(Matrix1, 3, 3);

	cout << "Matrix1:\n";
	PrintMatrixp14(Matrix1, 3, 3);


	if (IsScalarMatrixp14(Matrix1, 3, 3))
		cout << "It is a scalar matrix!\n";
	else
		cout << "It is not a scalar matrix!\n";

	system("Pause>0");
}