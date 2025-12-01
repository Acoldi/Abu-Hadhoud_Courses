#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include "RandomNumber.h"

using namespace std;

void FIllMatrixWithRandomNumbersp15(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows + 1; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintMatrixp15(int Arr[3][3], short Rows, short Cols)
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

int NumberCountInMatrixp15(int Arr[3][3], short Row, short Col, int Number)
{
	short Counter = 0;
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (Arr[i][j] == Number)
			{
				Counter += 1;
			}
			
		}
	}
	return Counter;
}

void Prob15_NumberCountInMatrix()
{
	srand((unsigned)time(0));

	int Matrix1[3][3] = { {1, 1, 1}, {0, 4, 0}, {0, 0, 1} };

	//FIllMatrixWithRandomNumbersp15(Matrix1, 3, 3);

	cout << "Matrix1:\n";
	PrintMatrixp15(Matrix1, 3, 3);

	int Number = 0;

	cout << "\nThe Number You Want to check its count: "; cin >> Number;

	cout << "\nThe Number Count = " << NumberCountInMatrixp15(Matrix1, 3, 3, Number);
	

	system("Pause>0");
}