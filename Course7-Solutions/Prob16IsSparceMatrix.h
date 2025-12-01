#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void PrintMatrixp16(int Arr[3][3], short Rows, short Cols)
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

bool IsSparceMatrixp16(int Arr[3][3], short Row, short Col)
{
	short ZerosCounter = 0;
	short NonZerosCounter = 0;

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (Arr[i][j] == 0)
				ZerosCounter++;
			else
				NonZerosCounter++;
		}
	}
	return (ZerosCounter > NonZerosCounter);
}

void Prob16_IsSparceMatrix()
{
	srand((unsigned)time(0));

	int Matrix1[3][3] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };

	//FIllMatrixWithRandomNumbers(Matrix1, 3, 3);

	cout << "Matrix1:\n";
	PrintMatrixp16(Matrix1, 3, 3);

	if (IsSparceMatrixp16(Matrix1, 3, 3))
		cout << "It is a sparce matrix\n";
	else
		cout << "It is Not sparce matrix\n";
	
	system("Pause>0");
}