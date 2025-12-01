#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void PrintMatrixp17(int Arr[3][3], short Rows, short Cols)
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

bool IsNumberInMatrixp17(int Arr[3][3], short Row, short Col, int Number)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (Arr[i][j] == Number)
			{
				return true;
			}
		}
	}
	return false;
}

void Prob17_IsNumberInMatrix()
{
	srand((unsigned)time(0));

	int Matrix1[3][3] = { {1, 10, 10}, {0, 0, 0}, {0, 8, 1} };

	//FIllMatrixWithRandomNumbers(Matrix1, 3, 3);

	cout << "Matrix1:\n";
	PrintMatrixp17(Matrix1, 3, 3);

	if (IsNumberInMatrixp17(Matrix1, 3, 3, 8))
		cout << "It is FOUND\n";
	else
		cout << "It is NOT FOUND\n";
	
	system("Pause>0");
}