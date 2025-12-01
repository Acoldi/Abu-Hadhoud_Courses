#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

void FIllMatrixWithRandomNumbersp18(int Arr[3][3], short Rows, short Cols);
void PrintArrayp18(int Arr[], int size);

int FindIntersectNumbersFrom2Matricesp18(int Arr[3][3], int Arr2[3][3], int Arr3[18], short Row, short Col)
{
	int temp = 0;
	int counter = 0;
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			temp = Arr[i][j];
			for (int k = 0; k < Row; k++)
			{
				for (int l = 0; l < Col; l++)
				{
					if (temp == Arr2[k][l])
					{
						Arr3[counter] = temp;
			            counter += 1;
					}

				}
			}

		}
	}
	return counter;
}

void PrintMatrixp18(int Arr[3][3], short Rows, short Cols)
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

void Prob18_FindIntersectedNumbers()
{
	srand((unsigned)time(0));

	int Matrix1[3][3], Matrix2[3][3];
	int Arr[18];

	FIllMatrixWithRandomNumbersp18(Matrix1, 3, 3);
	FIllMatrixWithRandomNumbersp18(Matrix2, 3, 3);

	cout << "Matrix1:\n";
	PrintMatrixp18(Matrix1, 3, 3);
	cout << "\nMatrix2:\n";
	PrintMatrixp18(Matrix2, 3, 3);

	int size = FindIntersectNumbersFrom2Matricesp18(Matrix1, Matrix2, Arr, 3, 3);

	cout << "Intersected Numbers Are: \n";
	
	PrintArrayp18(Arr, size);
	
	
system("Pause>0");
}

void FIllMatrixWithRandomNumbersp18(int Arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows + 1; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintArrayp18(int Arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << Arr[i] << " ";
	}
    cout << endl;
}