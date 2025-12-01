#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include "RandomNumber.h"

using namespace std;

void FIllMatrixWithRandomNumbersp13(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows + 1; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintMatrixp13(int Arr[3][3], short Rows, short Cols)
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

bool IsIdentityMatrixp13(int Arr[3][3], short Row, short Col)
{
	bool Diagnose = 0, Zeros = 0;

	if (Arr[0][0] == 1 && Arr[1][1] == 1 && Arr[2][2] == 1)
		Diagnose = true;
	if (Arr[0][1] == 0 && Arr[0][2] == 0 && Arr[1][0] == 0 &&
		Arr[1][2] == 0 && Arr[2][0] == 0 && Arr[2][1] == 0)
		Zeros = true;

	return (Diagnose && Zeros);
}

void Prob13_IsIdentityMatrix()
{
	srand((unsigned)time(0));

	int Matrix1[3][3] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };

	//FIllMatrixWithRandomNumbersp13(Matrix1, 3, 3);

	cout << "Matrix1:\n";
	PrintMatrixp13(Matrix1, 3, 3);


	if (IsIdentityMatrixp13(Matrix1, 3, 3))
		cout << "It is an identity matrix!\n";
	else
		cout << "It is not an identity matrix!\n";

	system("Pause>0");
}