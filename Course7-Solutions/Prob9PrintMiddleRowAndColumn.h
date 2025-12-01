#pragma once
#include <iostream>
#include <iomanip>
#include "RandomNumber.h"

using namespace std;

void FIllMatrixWithRandomNumbers_p9(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintMiddleRowOfMatrix_p9(int Matrix1[3][3], short Row, short Column)
{
	int MiddleRow = Row / 2;

	for (int j = 0; j < Column; j++)
	{
		printf("%.2i     ", Matrix1[MiddleRow][j]);
	}
	cout << endl;
}

void PrintMiddleColumnOfMatrix_p9(int Matrix1[3][3], short Row, short Column)
{
	int MiddleColumn = Column / 2;

	for (int i = 0; i < Row; i++)
	{
		printf("%.2i     \n", Matrix1[i][MiddleColumn]);
	}
}



void PrintMatrix_p9(int Arr[3][3], short Rows, short Cols)
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

void Prob9PrintMiddleRowAndColumn()
{
	srand((unsigned)time(0));

	int Matrix1[3][3];

	FIllMatrixWithRandomNumbers_p9(Matrix1, 3, 3);

	cout << "Matrix1:\n";
	PrintMatrix_p9(Matrix1, 3, 3);
	

	cout << "\nMiddle Row:\n";
	PrintMiddleRowOfMatrix_p9(Matrix1, 3, 3);

	cout << "\nMiddle Column:\n";
	PrintMiddleColumnOfMatrix_p9(Matrix1, 3, 3);
}
