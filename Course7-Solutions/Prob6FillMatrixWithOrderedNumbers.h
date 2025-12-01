#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

void FIllMatrixWithOrderedNumbers_p6(int Arr[3][3], short Rows, short Cols)
{
	int Summ = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Summ++;
			Arr[i][j] = Summ;
		}
	}
}

void PrintMAtrix_p6(int Arr[3][3], short Rows, short Cols)
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

void Prob6FillMatrixWithOrderedNumbers()
{
	srand((unsigned)time(0));

	int Arr[3][3];

	FIllMatrixWithOrderedNumbers_p6(Arr, 3, 3);

	cout << "The matrix:\n";
	PrintMAtrix_p6(Arr, 3, 3);
}

