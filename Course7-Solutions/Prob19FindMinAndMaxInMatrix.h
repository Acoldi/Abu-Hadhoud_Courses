#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include "RandomNumber.h"

using namespace std;

void FIllMatrixWithRandomNumbersp19(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows + 1; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintMatrixp19(int Arr[3][3], short Rows, short Cols)
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

int FindMaxNumberInMatrixp19(int Arr[3][3], short Row, short Col)
{
	int Max = Arr[0][0];

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (Arr[i][j] > Max)
			{
				Max = Arr[i][j];
			}
		}
	}
	return Max;
}

int FindMinNumberInMatrixp19(int Arr[3][3], short Row, short Col)
{
	int Min = Arr[0][0];

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (Arr[i][j] < Min)
			{
				Min = Arr[i][j];
			}
		}
	}
	return Min;
}

void Prob19_FindMinMax()
{
	srand((unsigned)time(0));

	int Matrix1[3][3];

	FIllMatrixWithRandomNumbersp19(Matrix1, 3, 3);

	cout << "Matrix1:\n";
	PrintMatrixp19(Matrix1, 3, 3);


	cout << "\nMax = " << FindMaxNumberInMatrixp19(Matrix1, 3, 3);
	cout << "\nMin = " << FindMinNumberInMatrixp19(Matrix1, 3, 3);
	
	
system("Pause>0");
}